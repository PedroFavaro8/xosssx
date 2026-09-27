/* R2Shims: miscelanea real (AreFileApisANSI) + E_NOTIMPL gracioso. */
#include <windows.h>

BOOL WINAPI WD_AreFileApisANSI(void) {
    return TRUE;
}

HRESULT WINAPI WD_RoGetAgileReference(INT32 options, REFIID iid, IUnknown* unk, void** agileRef) {
    (void)options;
    (void)iid;
    (void)unk;
    if (agileRef) {
        *agileRef = NULL;
    }
    return E_NOTIMPL;
}
