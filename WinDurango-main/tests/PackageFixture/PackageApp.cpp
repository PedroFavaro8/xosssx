#include <chrono>
#include <filesystem>
#include <iostream>
#include <iterator>
#include <thread>

#ifdef _WIN32
#include <Windows.h>
#endif

int main() {
    std::cout << "WinDurango package fixture app started\n";
#ifdef _WIN32
    wchar_t apiRoot[32768]{};
    if (GetEnvironmentVariableW(L"WINDURANGO_API_ROOT", apiRoot,
                                static_cast<DWORD>(std::size(apiRoot))) == 0) {
        return 2;
    }
    std::cout << "package api root propagated" << std::endl;
#endif
#ifdef _WIN32
    wchar_t runToken[32768]{};
    if (GetEnvironmentVariableW(L"WINDURANGO_PACKAGE_RUN_TOKEN", runToken,
                                static_cast<DWORD>(std::size(runToken))) == 0) {
        return 4;
    }
    const auto serviceMarker = std::filesystem::current_path() /
        (std::wstring(L"service.started.") + runToken);
    for (int attempt = 0; attempt < 40 && !std::filesystem::exists(serviceMarker); ++attempt) {
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
    if (!std::filesystem::exists(serviceMarker)) {
        return 3;
    }
    std::cout << "package service started" << std::endl;
#else
    std::cout << "package fixture requires Windows" << std::endl;
#endif
    return 0;
}
