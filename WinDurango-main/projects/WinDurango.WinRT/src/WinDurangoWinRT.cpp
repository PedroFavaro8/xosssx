#include "WinDurangoWinRT.h"
#include "../include/WinDurango.WinRT/Windows/Xbox/Storage/Windows.Xbox.Storage.ConnectedStorage.h"

std::shared_ptr<wd::common::WinDurango> p_wd = nullptr;

DWORD WINAPI ThreadProc(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    if (!wd::WinRT::g_UserStorage)
    {
        wd::WinRT::g_UserStorage = new wd::WinRT::ConnectedStorage();
        wd::WinRT::g_UserStorage->InitializeStorage(L"UserStorage").get();
    }

    if (!wd::WinRT::g_MachineStorage)
    {
        wd::WinRT::g_MachineStorage = new wd::WinRT::ConnectedStorage();
        wd::WinRT::g_MachineStorage->InitializeStorage(L"MachineStorage").get();
    }

    return 1;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,
                    DWORD fdwReason,
                    LPVOID lpvReserved)
{
    if (p_wd == nullptr)
    {
        p_wd = wd::common::WinDurango::GetInstance();
        p_wd->log.Log("WinDurango::WinRT", "Initialized");
    }

    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        CreateThread(nullptr, 0, ThreadProc, nullptr, 0, nullptr);
    }

    return TRUE;
}

HRESULT WINAPI ActivationFactory(HSTRING classID, void* factory) {
    return 0;
}