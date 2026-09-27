/* R2Shims: ativacao WinRT (graceful E_NOTIMPL no R2). */
#include <windows.h>
#include <roapi.h>

HRESULT WINAPI WD_RoGetActivationFactory(HSTRING activatableClassId, REFIID iid, void** factory) {
    (void)activatableClassId;
    (void)iid;
    if (factory) {
        *factory = NULL;
    }
    return E_NOTIMPL;
}

HRESULT WINAPI WD_RoActivateInstance(HSTRING activatableClassId, IInspectable** instance) {
    (void)activatableClassId;
    if (instance) {
        *instance = NULL;
    }
    return E_NOTIMPL;
}
