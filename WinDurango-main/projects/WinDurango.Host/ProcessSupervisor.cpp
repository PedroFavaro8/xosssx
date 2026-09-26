#include "WinDurango.Host/ProcessSupervisor.h"
#include "WinDurango.Host/ApiLoader.h"

#include <algorithm>
#include <cwctype>
#include <iostream>
#include <iterator>
#include <limits>
#include <string>

#ifdef _WIN32
#include <Windows.h>
#endif

namespace windurango::host {
namespace {

std::wstring Lower(std::wstring value) {
    std::transform(value.begin(), value.end(), value.begin(),
        [](wchar_t c) { return static_cast<wchar_t>(std::towlower(c)); });
    return value;
}

bool IsInside(const std::filesystem::path& file, const std::filesystem::path& root) {
    const auto fileText = Lower(file.generic_wstring());
    auto rootText = Lower(root.generic_wstring());
    if (!rootText.empty() && rootText.back() != L'/') {
        rootText.push_back(L'/');
    }
    return fileText.starts_with(rootText);
}

bool IsAllowed(const std::filesystem::path& requested,
              const std::filesystem::path& root,
              std::filesystem::path& resolved) {
    (void)root;
    if (requested.empty()) {
        return false;
    }
    std::error_code error;
    resolved = std::filesystem::weakly_canonical(requested, error);
    if (error || !std::filesystem::is_regular_file(resolved, error) || error) {
        return false;
    }
    return true;
}

#ifdef _WIN32
struct ChildProcess {
    PROCESS_INFORMATION process{};

    ChildProcess() = default;
    ChildProcess(const ChildProcess&) = delete;
    ChildProcess& operator=(const ChildProcess&) = delete;

    ChildProcess(ChildProcess&& other) noexcept : process(other.process) {
        other.process = {};
    }

    ChildProcess& operator=(ChildProcess&& other) noexcept {
        if (this != &other) {
            Close();
            process = other.process;
            other.process = {};
        }
        return *this;
    }

    ~ChildProcess() {
        Close();
    }

    void Close() noexcept {
        if (process.hProcess) {
            if (WaitForSingleObject(process.hProcess, 0) == WAIT_TIMEOUT) {
                TerminateProcess(process.hProcess, 0);
                WaitForSingleObject(process.hProcess, 2000);
            }
            CloseHandle(process.hProcess);
        }
        if (process.hThread) {
            CloseHandle(process.hThread);
        }
        process = {};
    }
};

class ScopedEnvironmentVariable {
public:
    ScopedEnvironmentVariable(const wchar_t* name, const std::wstring& value)
        : name_(name) {
        if (value.empty()) {
            return;
        }
        wchar_t previous[32768]{};
        const DWORD length = GetEnvironmentVariableW(name_, previous,
                                                      static_cast<DWORD>(std::size(previous)));
        if (length > 0 && length < std::size(previous)) {
            hadPrevious_ = true;
            previous_ = previous;
        }
        active_ = SetEnvironmentVariableW(name_, value.c_str()) != FALSE;
    }

    ScopedEnvironmentVariable(const ScopedEnvironmentVariable&) = delete;
    ScopedEnvironmentVariable& operator=(const ScopedEnvironmentVariable&) = delete;

    ~ScopedEnvironmentVariable() {
        if (!active_) {
            return;
        }
        if (hadPrevious_) {
            SetEnvironmentVariableW(name_, previous_.c_str());
        } else {
            SetEnvironmentVariableW(name_, nullptr);
        }
    }

private:
    const wchar_t* name_;
    bool active_ = false;
    bool hadPrevious_ = false;
    std::wstring previous_;
};

bool Start(const std::filesystem::path& executable,
           const std::filesystem::path& apiRoot,
           const std::wstring& runToken,
           ChildProcess& child) {
    ScopedEnvironmentVariable apiEnvironment(L"WINDURANGO_API_ROOT", apiRoot.wstring());
    ScopedEnvironmentVariable runEnvironment(L"WINDURANGO_PACKAGE_RUN_TOKEN", runToken);
    std::wstring commandLine = L"\"" + executable.wstring() + L"\"";
    STARTUPINFOW startup{};
    startup.cb = sizeof(startup);
    return CreateProcessW(nullptr, commandLine.data(), nullptr, nullptr, FALSE,
        CREATE_UNICODE_ENVIRONMENT, nullptr, executable.parent_path().wstring().c_str(),
        &startup, &child.process) != FALSE;
}
#endif

} // namespace

int LaunchDashboard(const LaunchPlan& plan) {
#ifndef _WIN32
    (void)plan;
    std::cerr << "FAIL: o supervisor requer Windows\n";
    return 3;
#else
    const auto root = std::filesystem::current_path();
    std::filesystem::path dashboard;
    if (!IsAllowed(plan.dashboard, root / "apps", dashboard)) {
        std::cerr << "FAIL: dashboard não pôde ser resolvido\n";
        return 4;
    }

    std::error_code serviceError;
    const auto serviceRoot = plan.background_root.empty()
        ? root / "services"
        : std::filesystem::weakly_canonical(plan.background_root, serviceError);
    std::vector<std::filesystem::path> services;
    for (const auto& requested : plan.background) {
        std::filesystem::path service;
        if (serviceError || !IsAllowed(requested, serviceRoot, service)) {
            std::cerr << "FAIL: serviço não pôde ser resolvido\n";
            return 5;
        }
        services.push_back(std::move(service));
    }

    std::vector<ChildProcess> children(services.size());
    for (size_t index = 0; index < services.size(); ++index) {
        if (!Start(services[index], plan.api_root, plan.run_token, children[index])) {
            std::cerr << "FAIL: não foi possível iniciar serviço Win32=" << GetLastError() << "\n";
            return 6;
        }
    }

    ChildProcess dashboardProcess;
    if (!Start(dashboard, plan.api_root, plan.run_token, dashboardProcess)) {
        std::cerr << "FAIL: não foi possível iniciar dashboard Win32=" << GetLastError() << "\n";
        return 7;
    }
    if (WaitForSingleObject(dashboardProcess.process.hProcess, INFINITE) != WAIT_OBJECT_0) {
        std::cerr << "FAIL: não foi possível aguardar o dashboard Win32=" << GetLastError() << "\n";
        return 8;
    }

    DWORD exitCode = 0;
    if (!GetExitCodeProcess(dashboardProcess.process.hProcess, &exitCode)) {
        std::cerr << "FAIL: não foi possível consultar o código do dashboard Win32="
                  << GetLastError() << "\n";
        return 9;
    }
    if (exitCode > static_cast<DWORD>(std::numeric_limits<int>::max())) {
        return 1;
    }
    return static_cast<int>(exitCode);
#endif
}

int LaunchPackage(const std::filesystem::path& package) {
#ifndef _WIN32
    (void)package;
    std::cerr << "FAIL: pacotes .wdapp requerem Windows\n";
    return 3;
#else
    const auto root = std::filesystem::current_path();
    std::error_code error;
    const auto resolvedPackage = std::filesystem::weakly_canonical(package, error);
    const auto appsRoot = std::filesystem::weakly_canonical(root / "apps", error);
    if (error || Lower(resolvedPackage.extension().wstring()) != L".wdapp" ||
        !std::filesystem::is_directory(resolvedPackage, error) || error ||
        !IsInside(resolvedPackage, appsRoot)) {
        std::cerr << "FAIL: pacote deve ser uma pasta .wdapp dentro de apps\\\n";
        return 8;
    }

    std::filesystem::path entry;
    if (!IsAllowed(resolvedPackage / "app.exe", appsRoot, entry)) {
        std::cerr << "FAIL: pacote .wdapp precisa conter app.exe\n";
        return 9;
    }
    LoadApis(resolvedPackage / "apis");
    std::vector<std::filesystem::path> services;
    const auto servicesRoot = resolvedPackage / "services";
    if (std::filesystem::is_directory(servicesRoot, error) && !error)
    {
        for (const auto& item : std::filesystem::directory_iterator(servicesRoot, error))
        {
            if (error || !item.is_regular_file(error) || error)
            {
                continue;
            }
            if (Lower(item.path().extension().wstring()) != L".exe")
            {
                continue;
            }
            services.push_back(item.path());
        }
        std::sort(services.begin(), services.end());
    }
    const auto runToken = std::to_wstring(GetCurrentProcessId()) + L"-" +
                          std::to_wstring(GetTickCount64());
    return LaunchDashboard(LaunchPlan{entry, services, servicesRoot,
                                      resolvedPackage / "apis", runToken});
#endif
}

} // namespace windurango::host
