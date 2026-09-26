#include <cwchar>
#include <string>

#ifdef _WIN32
#include <Windows.h>

namespace {
constexpr wchar_t kWindowClass[] = L"WinDurangoCompatibilityShell";
constexpr wchar_t kWindowTitle[] = L"WinDurango Compatibility Shell";

std::wstring platform_line() {
    SYSTEM_INFO systemInfo{};
    GetNativeSystemInfo(&systemInfo);
    MEMORYSTATUSEX memory{};
    memory.dwLength = sizeof(memory);

    const bool x64 = systemInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64;
    if (!GlobalMemoryStatusEx(&memory)) {
        return L"Perfil: falha ao consultar memoria fisica";
    }

    wchar_t buffer[160]{};
    const double gib = static_cast<double>(memory.ullTotalPhys) /
        (1024.0 * 1024.0 * 1024.0);
    const bool memoryTarget = memory.ullTotalPhys >= 8ull * 1024ull * 1024ull * 1024ull;
    swprintf_s(buffer, _countof(buffer), L"Perfil: arquitetura=%s | memoria=%.1f GiB | x64/8GB=%s",
        x64 ? L"x64" : L"nao-x64", gib, (x64 && memoryTarget) ? L"pass" : L"fail");
    return buffer;
}

LRESULT CALLBACK WindowProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_PAINT: {
        PAINTSTRUCT paint{};
        HDC dc = BeginPaint(window, &paint);
        SetBkMode(dc, TRANSPARENT);
        const auto draw = [&](int x, int y, const wchar_t* text) {
            TextOutW(dc, x, y, text, static_cast<int>(wcslen(text)));
        };
        draw(24, 24, L"WinDurango compatibility shell");
        draw(24, 56, L"Estado: ambiente proprio de compatibilidade inicializado");
        const std::wstring profile = platform_line();
        draw(24, 88, profile.c_str());
        draw(24, 120, L"Entrada: XInput e teclado");
        draw(24, 152, L"Backend grafico: D3D11/D3D12 (quando disponivel)");
        draw(24, 200, L"Shell de diagnostico; somente modulos da camada WinDurango.");
        draw(24, 232, L"Imagens de sistema, firmware e conteudo proprietario nao sao carregados.");
        EndPaint(window, &paint);
        return 0;
    }
    case WM_KEYDOWN:
        if (wParam == VK_ESCAPE) {
            DestroyWindow(window);
            return 0;
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        break;
    }
    return DefWindowProcW(window, message, wParam, lParam);
}
}

int run_compatibility_window() {
    HINSTANCE instance = GetModuleHandleW(nullptr);
    WNDCLASSW windowClass{};
    windowClass.hInstance = instance;
    windowClass.lpfnWndProc = WindowProc;
    windowClass.lpszClassName = kWindowClass;
    windowClass.hCursor = LoadCursorW(nullptr, IDC_ARROW);
    windowClass.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
    if (!RegisterClassW(&windowClass) && GetLastError() != ERROR_CLASS_ALREADY_EXISTS) {
        return 2;
    }
    HWND window = CreateWindowExW(0, kWindowClass, kWindowTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 760, 360, nullptr, nullptr, instance, nullptr);
    if (!window) {
        return 3;
    }
    ShowWindow(window, SW_SHOW);
    UpdateWindow(window);
    MSG message{};
    while (GetMessageW(&message, nullptr, 0, 0) > 0) {
        TranslateMessage(&message);
        DispatchMessageW(&message);
    }
    return static_cast<int>(message.wParam);
}

#else
int run_compatibility_window() { return 3; }
#endif
