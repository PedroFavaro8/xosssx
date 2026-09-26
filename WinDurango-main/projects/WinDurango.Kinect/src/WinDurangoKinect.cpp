#include "WinDurangoKinect.h"

std::shared_ptr<wd::common::WinDurango> p_wd = nullptr;

DWORD WINAPI ThreadProc(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    return 1;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,
                    DWORD fdwReason,
                    LPVOID lpvReserved)
{
    if (p_wd == nullptr)
    {
        p_wd = wd::common::WinDurango::GetInstance();
        p_wd->log.Log("WinDurango::Kinect", "Initialized");
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