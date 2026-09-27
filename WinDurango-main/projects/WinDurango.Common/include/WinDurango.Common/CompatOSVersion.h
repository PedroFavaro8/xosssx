#pragma once
// CompatOSVersion: resolve um numero de versao de SO real sem exigir a
// imagem de sistema proprietaria do console (o antigo caminho montado).
//
// Ordem de resolucao, toda com conteudo proprio ou do Windows host:
//   1. Recurso de versao do combase.dll do proprio Windows onde o host roda
//      (%SystemRoot%\System32\combase.dll, sempre presente); ou
//   2. Constante de compatibilidade documentada (10.0.19041.0).
//
// Nenhum arquivo de firmware, disco ou imagem de sistema do console e lido.
// Tambem nao ha MessageBox: este codigo roda em DllMain/caminho de jogo,
// onde um dialogo modal travaria o processo sem ninguem para clicar.
#include <cstdint>
#include <string>
#include <vector>

#ifdef _WIN32
#include <Windows.h>
#pragma comment(lib, "version.lib")
#endif

namespace wd::common {

struct CompatOSVersion {
    uint32_t major = 0;
    uint32_t minor = 0;
    uint32_t build = 0;
    uint32_t revision = 0;
};

inline CompatOSVersion ResolveCompatOSVersion() {
#ifdef _WIN32
    wchar_t systemDir[MAX_PATH]{};
    const UINT dirLength = GetSystemDirectoryW(systemDir, MAX_PATH);
    if (dirLength > 0 && dirLength < MAX_PATH) {
        std::wstring path(systemDir);
        path += L"\\combase.dll";
        const DWORD dataSize = GetFileVersionInfoSizeW(path.c_str(), nullptr);
        if (dataSize > 0) {
            std::vector<BYTE> data(dataSize);
            DWORD handle = 0;
            if (GetFileVersionInfoW(path.c_str(), handle, dataSize, data.data())) {
                VS_FIXEDFILEINFO* fixedInfo = nullptr;
                UINT length = 0;
                if (VerQueryValueW(data.data(), L"\\",
                                   reinterpret_cast<LPVOID*>(&fixedInfo),
                                   &length) &&
                    fixedInfo) {
                    CompatOSVersion version;
                    version.major = HIWORD(fixedInfo->dwProductVersionMS);
                    version.minor = LOWORD(fixedInfo->dwProductVersionMS);
                    version.build = HIWORD(fixedInfo->dwProductVersionLS);
                    version.revision = LOWORD(fixedInfo->dwProductVersionLS);
                    if (version.major != 0) {
                        return version;
                    }
                }
            }
        }
    }
#endif
    // Fallback de compatibilidade: Windows 10 2004, acima dos gates
    // minimos usados pela camada (XG >= 10.0.16232, Logan >= 6.2.11785).
    return CompatOSVersion{10, 0, 19041, 0};
}

} // namespace wd::common
