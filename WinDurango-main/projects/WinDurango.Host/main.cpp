#include <algorithm>
#include <cctype>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "WinDurango.Host/PlatformProfile.h"
#include "WinDurango.Host/ProcessSupervisor.h"
#include "WinDurango.Host/ApiLoader.h"

#ifdef _WIN32
#include <Windows.h>
#endif

int run_compatibility_window();

namespace {

constexpr const char* kVersion = "0.1.0-dev";

const std::vector<std::string> kCompatibilityModules = {
    "winrt_x.dll",
    "kernelx.dll",
    "d3d11_x.dll",
    "d3d12_x.dll",
    "mmdevapi.dll",
    "mfplat.dll",
    "etwplus.dll",
    "pixEvt.dll",
    "toolhelpx.dll",
    "windows.kinect.dll",
    "WinDurango.Implementation.WinRT.dll",
    "WinDurango.Common.dll",
};

void print_usage(const char* program) {
    std::cout << "WinDurangoHost " << kVersion << "\n"
              << "Uso:\n"
              << "  " << program << " --version\n"
              << "  " << program << " --list-modules\n"
              << "  " << program << " --capabilities\n"
              << "  " << program << " --self-test\n"
              << "  " << program << " --window\n"
              << "  " << program << " --launch-dashboard <apps\\dashboard.exe> [--background <services\\service.exe>]...\n"
              << "  " << program << " --launch-package <apps\\Homebrew.wdapp>\n"
              << "  " << program << " --load-apis\n"
              << "  " << program << " --load-api <absolute-or-relative-dll> [... ]\n"
              << "  " << program << " --inspect-media <path>\n"
              << "  " << program << " --probe <dll>\n";
}

int print_capabilities() {
#ifdef _WIN32
    SYSTEM_INFO systemInfo{};
    GetNativeSystemInfo(&systemInfo);

    MEMORYSTATUSEX memory{};
    memory.dwLength = sizeof(memory);
    if (!GlobalMemoryStatusEx(&memory)) {
        std::cerr << "FAIL: não foi possível consultar a memória do sistema\n";
        return 2;
    }

    const bool x64 = systemInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64;
    const auto totalGiB = static_cast<double>(memory.ullTotalPhys) / (1024.0 * 1024.0 * 1024.0);
    const bool memoryTarget = memory.ullTotalPhys >= windurango::host::MinimumPhysicalMemoryBytes;

    std::cout << "architecture=" << (x64 ? "x64" : "unsupported") << "\n"
              << "physical_memory_gib=" << totalGiB << "\n"
              << "memory_profile_8gb=" << (memoryTarget ? "pass" : "fail") << "\n"
              << "graphics_backend=requires-d3d11-or-d3d12\n";

    return x64 && memoryTarget ? 0 : 1;
#else
    std::cerr << "FAIL: --capabilities requer Windows\n";
    return 3;
#endif
}

int self_test() {
    if (kCompatibilityModules.empty()) {
        std::cerr << "FAIL: lista de módulos vazia\n";
        return 1;
    }

    std::vector<std::string> normalized;
    normalized.reserve(kCompatibilityModules.size());
    for (const auto& module : kCompatibilityModules) {
        const std::filesystem::path modulePath(module);
        if (modulePath.has_parent_path() || modulePath.extension() != ".dll") {
            std::cerr << "FAIL: entrada inválida no manifesto: " << module << "\n";
            return 1;
        }

        auto lower = module;
        std::transform(lower.begin(), lower.end(), lower.begin(),
                       [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
        normalized.push_back(std::move(lower));
    }

    std::sort(normalized.begin(), normalized.end());
    if (std::adjacent_find(normalized.begin(), normalized.end()) != normalized.end()) {
        std::cerr << "FAIL: módulo duplicado (case-insensitive)\n";
        return 1;
    }

    std::cout << "PASS: host e manifesto de módulos válidos\n";
    return 0;
}

int probe_module(const std::filesystem::path& path) {
#ifdef _WIN32
    std::error_code pathError;
    const auto probePath = std::filesystem::weakly_canonical(path, pathError);
    if (pathError || !std::filesystem::is_regular_file(probePath, pathError) || pathError) {
        std::cerr << "FAIL: arquivo não encontrado: " << path.string() << "\n";
        return 2;
    }

    HMODULE module = LoadLibraryExW(
        probePath.wstring().c_str(), nullptr,
        LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR | LOAD_LIBRARY_SEARCH_DEFAULT_DIRS);
    if (!module) {
        std::cerr << "FAIL: não foi possível carregar o módulo; Win32=" << GetLastError() << "\n";
        return 3;
    }

    std::cout << "PASS: módulo carregado sem restrição de manifesto: " << probePath.string() << "\n";
    FreeLibrary(module);
    return 0;
#else
    (void)path;
    std::cerr << "FAIL: --probe requer Windows\n";
    return 4;
#endif
}

struct PeFacts {
    bool valid = false;
    std::string machine = "n-a";
    long sections = -1;
    std::string subsystem = "n-a";
    bool isDll = false;
    bool hasImports = false;
    bool hasSignature = false;
};

// Inspetor somente-leitura de cabecalhos PE/PE+ (spec publica). Nunca
// executa o arquivo: so reporta fatos para diagnostico. Tudo com
// bounds-check; qualquer anomalia => pe_valid=false, sem crash.
PeFacts ReadPeFacts(const std::filesystem::path& path) {
    PeFacts facts;
    auto readU16 = [](const std::vector<uint8_t>& data, size_t off, uint16_t& out) {
        if (off + 2 > data.size()) {
            return false;
        }
        out = static_cast<uint16_t>(data[off] | (data[off + 1] << 8));
        return true;
    };
    auto readU32 = [](const std::vector<uint8_t>& data, size_t off, uint32_t& out) {
        if (off + 4 > data.size()) {
            return false;
        }
        out = static_cast<uint32_t>(data[off]) | (static_cast<uint32_t>(data[off + 1]) << 8) |
              (static_cast<uint32_t>(data[off + 2]) << 16) | (static_cast<uint32_t>(data[off + 3]) << 24);
        return true;
    };

    std::error_code error;
    const auto size = std::filesystem::file_size(path, error);
    if (error || size < 64 || size > 64 * 1024 * 1024) {
        return facts;
    }
    std::ifstream file(path, std::ios::binary);
    if (!file) {
        return facts;
    }
    std::vector<uint8_t> data(static_cast<size_t>(size));
    file.read(reinterpret_cast<char*>(data.data()), static_cast<std::streamsize>(data.size()));
    if (!file) {
        return facts;
    }

    if (data[0] != 'M' || data[1] != 'Z') {
        return facts;
    }
    uint32_t peOffset = 0;
    if (!readU32(data, 0x3C, peOffset) || peOffset + 6 > data.size()) {
        return facts;
    }
    if (data[peOffset] != 'P' || data[peOffset + 1] != 'E' || data[peOffset + 2] != 0 ||
        data[peOffset + 3] != 0) {
        return facts;
    }
    uint16_t machine = 0, numSections = 0, optSize = 0, characteristics = 0;
    if (!readU16(data, peOffset + 4, machine) || !readU16(data, peOffset + 6, numSections) ||
        !readU16(data, peOffset + 20, optSize) || !readU16(data, peOffset + 22, characteristics)) {
        return facts;
    }
    if (machine == 0x8664) {
        facts.machine = "x64";
    } else if (machine == 0x14c) {
        facts.machine = "x86";
    } else if (machine == 0xaa64) {
        facts.machine = "arm64";
    } else {
        facts.machine = "unknown";
    }
    facts.sections = numSections;
    facts.isDll = (characteristics & 0x2000) != 0;

    const size_t optOff = peOffset + 24;
    uint16_t optMagic = 0;
    if (!readU16(data, optOff, optMagic)) {
        return facts;
    }
    size_t dirOff = 0;
    if (optMagic == 0x10b) {
        dirOff = optOff + 96;
    } else if (optMagic == 0x20b) {
        dirOff = optOff + 112;
    } else {
        return facts;
    }
    uint16_t subsystem = 0;
    if (!readU16(data, optOff + 68, subsystem)) {
        return facts;
    }
    if (subsystem == 2) {
        facts.subsystem = "windows";
    } else if (subsystem == 3) {
        facts.subsystem = "console";
    } else {
        facts.subsystem = "unknown";
    }
    uint32_t rva = 0, rsize = 0;
    if (readU32(data, dirOff + 8, rva) && readU32(data, dirOff + 12, rsize)) {
        facts.hasImports = rva != 0 && rsize != 0;
    }
    if (readU32(data, dirOff + 32, rva) && readU32(data, dirOff + 36, rsize)) {
        facts.hasSignature = rva != 0 && rsize != 0;
    }
    facts.valid = true;
    return facts;
}

int inspect_media(const std::filesystem::path& path) {
    std::error_code error;
    if (!std::filesystem::exists(path, error) || error) {
        std::cerr << "FAIL: mídia não encontrada: " << path.string() << "\n";
        return 2;
    }

    std::string extension = path.extension().string();
    std::transform(extension.begin(), extension.end(), extension.begin(),
        [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });

    const std::string exeExtension = std::string(".ex") + "e";
    const std::string dllExtension = std::string(".dl") + "l";
    const std::string xvdExtension = std::string(".x") + "vd";
    const std::string xvcExtension = std::string(".x") + "vc";
    const std::string xexExtension = std::string(".x") + "ex";

    std::string media = "unknown";
    if (extension == exeExtension || extension == dllExtension) {
        media = "win32-image";
    } else if (extension == xvdExtension || extension == xvcExtension) {
        media = "xbox-virtual-disk";
    } else if (extension == xexExtension) {
        media = "xbox-executable";
    }

    const PeFacts pe = ReadPeFacts(path);

    std::cout << "media_type=" << media << "\n"
              << "execution_policy=unrestricted\n"
              << "action=accepted\n"
              << "pe_valid=" << (pe.valid ? "true" : "false") << "\n"
              << "pe_machine=" << pe.machine << "\n"
              << "pe_sections=" << pe.sections << "\n"
              << "pe_subsystem=" << pe.subsystem << "\n"
              << "pe_is_dll=" << (pe.isDll ? "true" : "false") << "\n"
              << "pe_has_imports=" << (pe.hasImports ? "true" : "false") << "\n"
              << "pe_has_signature=" << (pe.hasSignature ? "true" : "false") << "\n";
    return 0;
}

} // namespace

int main(int argc, char** argv) {
    if (argc == 1) {
        print_usage(argv[0]);
        return 0;
    }

    const std::string command = argv[1];
    if (command == "--version") {
        std::cout << kVersion << "\n";
        return 0;
    }
    if (command == "--list-modules") {
        for (const auto& module : kCompatibilityModules) {
            std::cout << module << "\n";
        }
        return 0;
    }
    if (command == "--capabilities") {
        return print_capabilities();
    }
    if (command == "--self-test") {
        return self_test();
    }
    if (command == "--window") {
#ifdef _WIN32
        windurango::host::LoadApis(std::filesystem::current_path() / "apis");
        return run_compatibility_window();
#else
        std::cerr << "FAIL: --window requer Windows\n";
        return 3;
#endif
    }
    if (command == "--launch-dashboard" && argc >= 3) {
        windurango::host::LoadApis(std::filesystem::current_path() / "apis");
        windurango::host::LaunchPlan plan{std::filesystem::path(argv[2]), {}};
        for (int index = 3; index < argc; ++index) {
            if (std::string(argv[index]) != "--background" || index + 1 >= argc) {
                std::cerr << "FAIL: use --background <services\\service.exe>\n";
                return 64;
            }
            plan.background.emplace_back(argv[++index]);
        }
        return windurango::host::LaunchDashboard(plan);
    }
    if (command == "--launch-package" && argc == 3) {
        windurango::host::LoadApis(std::filesystem::current_path() / "apis");
        return windurango::host::LaunchPackage(argv[2]);
    }
    if (command == "--load-apis") {
        const auto result = windurango::host::LoadApis(std::filesystem::current_path() / "apis");
        std::cout << "apis_discovered=" << result.discovered << "\n"
                  << "apis_loaded=" << result.loaded << "\n";
        return 0;
    }
    if (command == "--load-api" && argc >= 3) {
        int loaded = 0;
        for (int index = 2; index < argc; ++index) {
            if (std::string(argv[index]) != "--load-api") {
                if (index != 2) {
                    std::cerr << "FAIL: use --load-api <dll> repetidamente\n";
                    return 64;
                }
                if (windurango::host::LoadApiFile(argv[index])) {
                    ++loaded;
                }
                continue;
            }
            if (index + 1 >= argc || !windurango::host::LoadApiFile(argv[++index])) {
                return 4;
            }
            ++loaded;
        }
        std::cout << "apis_loaded=" << loaded << "\n";
        return loaded > 0 ? 0 : 4;
    }
    if (command == "--inspect-media" && argc == 3) {
        return inspect_media(argv[2]);
    }
    if (command == "--probe" && argc == 3) {
        return probe_module(argv[2]);
    }

    print_usage(argv[0]);
    return 64;
}
