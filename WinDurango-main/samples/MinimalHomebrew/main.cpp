// MinimalHomebrew - homebrew de exemplo para WinDurangoHost.
//
// Pacote .wdapp padrao: Minimal.wdapp/app.exe
// Uso minimo das APIs de compatibilidade: apenas kernelx (KernelX) e
// d3d11_x (D3D11X), carregadas em tempo de execucao a partir do diretorio
// do proprio pacote. Nada e vinculado estaticamente.

#include <cstdio>
#include <cstdlib>
#include <string>

#ifdef _WIN32
#include <Windows.h>
#endif

namespace {

struct ApiProbe {
    const char* name;
    bool loaded;
    std::string detail;
};

ApiProbe TryLoad(const char* name) {
#ifdef _WIN32
    HMODULE module = LoadLibraryA(name);
    if (module) {
        return {name, true, "ok"};
    }
    return {name, false, std::string("Win32=") + std::to_string(GetLastError())};
#else
    (void)name;
    return {name, false, "requer Windows (verificado no CI)"};
#endif
}

void PrintApiRoot() {
#ifdef _WIN32
    wchar_t apiRoot[32768]{};
    DWORD length = GetEnvironmentVariableW(
        L"WINDURANGO_API_ROOT", apiRoot, static_cast<DWORD>(1024));
    if (length > 0 && length < 1024) {
        std::wprintf(L"WINDURANGO_API_ROOT=%s\n", apiRoot);
    } else {
        std::puts("WINDURANGO_API_ROOT ausente (rode via --launch-package)");
    }
#else
    const char* apiRoot = std::getenv("WINDURANGO_API_ROOT");
    if (apiRoot) {
        std::printf("WINDURANGO_API_ROOT=%s\n", apiRoot);
    } else {
        std::puts("WINDURANGO_API_ROOT ausente (rode via --launch-package)");
    }
#endif
}

} // namespace

int main() {
    std::puts("========================================");
    std::puts(" WinDurango Minimal Homebrew");
    std::puts(" rodando coisas alem do normal.");
    std::puts("========================================");

    PrintApiRoot();

    const ApiProbe apis[] = {
        TryLoad("kernelx.dll"),
        TryLoad("d3d11_x.dll"),
    };
    for (const auto& api : apis) {
        std::printf("api %s: %s (%s)\n", api.name,
                    api.loaded ? "carregada" : "indisponivel",
                    api.detail.c_str());
    }

    std::puts("fim.");
    return 0;
}
