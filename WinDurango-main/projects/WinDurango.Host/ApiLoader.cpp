#include "WinDurango.Host/ApiLoader.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#include "WinDurango.Host/ApiContract.h"

#ifdef _WIN32
#include <Windows.h>
#endif

namespace windurango::host {
namespace {

std::string Lower(std::string value) {
    std::transform(value.begin(), value.end(), value.begin(),
        [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
    return value;
}

#ifdef _WIN32
std::vector<HMODULE> loadedModules;
std::vector<std::string> loadedPathKeys;

void HostLog(const char* message) {
    if (message) {
        std::cout << "api: " << message << "\n";
    }
}
#endif

} // namespace

bool LoadApiFile(const std::filesystem::path& file) {
#ifndef _WIN32
    (void)file;
    return false;
#else
    std::error_code error;
    if (!std::filesystem::is_regular_file(file, error) || error) {
        return false;
    }

    const auto canonicalFile = std::filesystem::weakly_canonical(file, error);
    if (error || !std::filesystem::is_regular_file(canonicalFile, error) || error) {
        return false;
    }
    const auto canonicalKey = Lower(canonicalFile.generic_string());
    if (std::find(loadedPathKeys.begin(), loadedPathKeys.end(), canonicalKey) != loadedPathKeys.end()) {
        std::cout << "api: already loaded " << canonicalFile.string() << "\n";
        return true;
    }

    HMODULE module = LoadLibraryExW(canonicalFile.wstring().c_str(), nullptr,
        LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR | LOAD_LIBRARY_SEARCH_DEFAULT_DIRS);
    if (!module) {
        std::cerr << "api: failed to load " << canonicalFile.string()
                  << " Win32=" << GetLastError() << "\n";
        return false;
    }

    const auto getInfo = reinterpret_cast<WinDurangoApiGetInfo>(
        GetProcAddress(module, "WinDurangoApiGetInfo"));
    const auto initialize = reinterpret_cast<WinDurangoApiInitialize>(
        GetProcAddress(module, "WinDurangoApiInitialize"));
    WinDurangoApiInfo info{};
    WinDurangoApiHost host{WinDurangoApiAbiVersion, HostLog};
    if (!getInfo || !initialize || !getInfo(&info) ||
        info.abi_version != WinDurangoApiAbiVersion || !initialize(&host)) {
        std::cerr << "api: rejected " << canonicalFile.string()
                  << " (invalid WinDurango ABI)\n";
        FreeLibrary(module);
        return false;
    }

    loadedModules.push_back(module);
    loadedPathKeys.push_back(canonicalKey);
    std::cout << "api: loaded " << (info.name ? info.name : "unnamed")
              << " " << (info.version ? info.version : "unknown") << "\n";
    return true;
#endif
}

ApiLoadResult LoadApis(const std::filesystem::path& directory) {
    ApiLoadResult result{};
#ifndef _WIN32
    (void)directory;
    return result;
#else
    std::error_code error;
    if (!std::filesystem::is_directory(directory, error) || error) {
        return result;
    }

    std::vector<std::filesystem::path> candidates;
    for (const auto& entry : std::filesystem::directory_iterator(directory, error)) {
        if (error || !entry.is_regular_file(error) || error) {
            continue;
        }
        candidates.push_back(entry.path());
    }
    std::sort(candidates.begin(), candidates.end());
    result.discovered = candidates.size();

    for (const auto& candidate : candidates) {
        if (LoadApiFile(candidate)) {
            ++result.loaded;
        }
    }
    return result;
#endif
}

} // namespace windurango::host
