//Huge thanks to XWine1 for providing us this hook :)
//(this was almost 2 years ago but works like a charm)
#pragma once
#include <Windows.h>

struct CForzaThread
{
    DWORD Id;
    HANDLE Handle;
    DWORD StackSize;
    DWORD AffinityMask;
    DWORD Priority;
    char Name[128];
};

struct FmodThread
{
    void* virtualtable;
    char Name[256];
};

DWORD(*P_StartForzaThread)(CForzaThread*, LPTHREAD_START_ROUTINE, LPVOID);

DWORD(*P_FmodThreadProc)(FmodThread*);

DWORD D_StartForzaThread(CForzaThread* Thread, LPTHREAD_START_ROUTINE StartAddress, LPVOID Parameter)
{
    WCHAR ThreadName[128];
    ZeroMemory(ThreadName, sizeof(ThreadName));
    DWORD r = P_StartForzaThread(Thread, StartAddress, Parameter);
    MultiByteToWideChar(CP_UTF8, 0, Thread->Name, 128, ThreadName, 128);
    SetThreadDescription(Thread->Handle, ThreadName);
    return r;
}

DWORD D_FmodThreadProc(FmodThread* Thread)
{
    WCHAR ThreadName[256];
    MultiByteToWideChar(CP_UTF8, 0, Thread->Name, 256, ThreadName, 256);
    SetThreadDescription(GetCurrentThread(), ThreadName);
    return P_FmodThreadProc(Thread);
}