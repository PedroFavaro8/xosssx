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

#ifdef _WIN32
namespace {

// Libera um objeto COM pelo slot Release (indice 2 da vtable).
void ComRelease(void* obj) {
    if (!obj) {
        return;
    }
    void** vtable = *static_cast<void***>(obj);
    typedef unsigned long(__stdcall* ReleaseFn)(void*);
    ReleaseFn release = reinterpret_cast<ReleaseFn>(vtable[2]);
    release(obj);
}

struct GuidBytes {
    unsigned long a;
    unsigned short b;
    unsigned short c;
    unsigned char d[8];
};

// Tenta D3D12 de verdade: so existe se d3d12.dll + driver existirem.
bool TryD3D12() {
    HMODULE d3d12 = LoadLibraryA("d3d12.dll");
    if (!d3d12) {
        return false;
    }
    typedef long(__stdcall* CreateFn)(void*, int, const void*, void**);
    CreateFn create = reinterpret_cast<CreateFn>(GetProcAddress(d3d12, "D3D12CreateDevice"));
    if (!create) {
        return false;
    }
    // IID_ID3D12Device = {189819f1-1db6-4b57-be54-1821339b85f7}, FL 11_0 = 0xb000.
    static const GuidBytes iid = {0x189819f1, 0x1db6, 0x4b57,
                                  {0xbe, 0x54, 0x18, 0x21, 0x33, 0x9b, 0x85, 0xf7}};
    void* device = NULL;
    const long ok = create(NULL, 0xb000, &iid, &device);
    if (ok < 0 || !device) {
        return false;
    }
    ComRelease(device);
    return true;
}

// Tenta D3D11 de verdade (11_0 existe desde o Win7/R2 com driver).
bool TryD3D11() {
    HMODULE d3d11 = LoadLibraryA("d3d11.dll");
    if (!d3d11) {
        return false;
    }
    typedef long(__stdcall* CreateFn)(void*, int, void*, unsigned, const int*, unsigned,
                                      unsigned, void**, int*, void**);
    CreateFn create = reinterpret_cast<CreateFn>(GetProcAddress(d3d11, "D3D11CreateDevice"));
    if (!create) {
        return false;
    }
    const int levels[] = {0xb000, 0xa100, 0xa000};
    void* device = NULL;
    void* context = NULL;
    int outLevel = 0;
    const long ok = create(NULL, 1, NULL, 0, levels, 3, 7, &device, &outLevel, &context);
    if (ok < 0 || !device) {
        return false;
    }
    ComRelease(context);
    ComRelease(device);
    return true;
}

} // namespace
#endif

void ProbeGpu() {
#ifdef _WIN32
    if (TryD3D12()) {
        std::puts("gpu: d3d12 em uso");
    } else if (TryD3D11()) {
        std::puts("gpu: d3d11 em uso");
    } else {
        std::puts("gpu: sem backend, usando emulacao");
    }
#else
    std::puts("gpu: sondagem requer Windows (verificado no CI)");
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

    ProbeGpu();

    std::puts("fim.");
    return 0;
}
