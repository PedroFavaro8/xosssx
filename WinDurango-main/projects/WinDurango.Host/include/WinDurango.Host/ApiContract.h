#pragma once

#include <cstdint>

#if defined(_WIN32) && defined(WINDURANGO_API_BUILD)
#define WINDURANGO_API_EXPORT __declspec(dllexport)
#else
#define WINDURANGO_API_EXPORT
#endif

extern "C" {

struct WinDurangoApiInfo {
    uint32_t abi_version;
    const char* name;
    const char* version;
};

struct WinDurangoApiHost {
    uint32_t abi_version;
    void (*log)(const char* message);
};

using WinDurangoApiGetInfo = bool (*)(WinDurangoApiInfo* info);
using WinDurangoApiInitialize = bool (*)(const WinDurangoApiHost* host);

}

inline constexpr uint32_t WinDurangoApiAbiVersion = 1;
