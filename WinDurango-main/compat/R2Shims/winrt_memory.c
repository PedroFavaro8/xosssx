/* R2Shims: memoria virtual nova via APIs antigas (degradado real). */
#include <windows.h>
#include <memoryapi.h>

PVOID WINAPI WD_VirtualAlloc2(HANDLE Process, PVOID BaseAddress, SIZE_T Size,
                              ULONG AllocationType, ULONG PageProtection,
                              MEM_EXTENDED_PARAMETER* ExtendedParameters, ULONG ParameterCount) {
    (void)ExtendedParameters;
    (void)ParameterCount;
    if (Process != NULL && Process != GetCurrentProcess()) {
        SetLastError(ERROR_NOT_SUPPORTED);
        return NULL;
    }
    return VirtualAlloc(BaseAddress, Size, AllocationType, PageProtection);
}

PVOID WINAPI WD_MapViewOfFile3(HANDLE FileMapping, HANDLE Process, PVOID BaseAddress,
                               ULONG64 Offset, SIZE_T ViewSize, ULONG AllocationType,
                               ULONG PageProtection, MEM_EXTENDED_PARAMETER* ExtendedParameters,
                               ULONG ParameterCount) {
    DWORD access;
    (void)AllocationType;
    (void)ExtendedParameters;
    (void)ParameterCount;
    if (Process != NULL && Process != GetCurrentProcess()) {
        SetLastError(ERROR_NOT_SUPPORTED);
        return NULL;
    }
    access = (PageProtection & (PAGE_READWRITE | PAGE_WRITECOPY |
                                PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY))
                 ? FILE_MAP_ALL_ACCESS
                 : FILE_MAP_READ;
    return MapViewOfFileEx(FileMapping, access, (DWORD)(Offset >> 32),
                           (DWORD)Offset, ViewSize, BaseAddress);
}

HANDLE WINAPI WD_CreateFileMapping2(HANDLE File, SECURITY_ATTRIBUTES* SecurityAttributes,
                                    ACCESS_MASK DesiredAccess, ULONG PageProtection,
                                    ULONG64 MaximumSize, ULONG Flags,
                                    MEM_EXTENDED_PARAMETER* ExtendedParameters,
                                    ULONG ParameterCount) {
    (void)DesiredAccess;
    (void)Flags;
    (void)ExtendedParameters;
    (void)ParameterCount;
    return CreateFileMappingW(File, SecurityAttributes, PageProtection,
                              (DWORD)(MaximumSize >> 32), (DWORD)MaximumSize, NULL);
}

BOOL WINAPI WD_UnmapViewOfFile2(HANDLE Process, PVOID BaseAddress, ULONG UnmapFlags) {
    (void)UnmapFlags;
    if (Process != NULL && Process != GetCurrentProcess()) {
        SetLastError(ERROR_NOT_SUPPORTED);
        return FALSE;
    }
    return UnmapViewOfFile(BaseAddress);
}
