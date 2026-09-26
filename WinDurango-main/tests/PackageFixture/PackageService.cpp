#include <chrono>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <thread>

#ifdef _WIN32
#include <Windows.h>
#endif

int main() {
    wchar_t runToken[32768]{};
#ifdef _WIN32
    if (GetEnvironmentVariableW(L"WINDURANGO_PACKAGE_RUN_TOKEN", runToken,
                                static_cast<DWORD>(std::size(runToken))) == 0) {
        return 2;
    }
#endif
    const auto markerName = std::filesystem::path(
        std::wstring(L"service.started.") + runToken);
    std::ofstream marker(std::filesystem::current_path().parent_path() / markerName,
                         std::ios::trunc);
    marker << "started\n";
    std::this_thread::sleep_for(std::chrono::seconds(30));
    return 0;
}
