/* R2Shims: erros WinRT. Semantica honesta, sem dialogo. */
#include <windows.h>
#include <roerrorapi.h>

HRESULT WINAPI WD_RoOriginateError(HRESULT error, HSTRING message) {
    (void)message;
    return error;
}

HRESULT WINAPI WD_RoTransformError(HRESULT oldError, DWORD flags, HRESULT newError) {
    (void)oldError;
    (void)flags;
    return newError;
}

void WINAPI WD_RoOriginateLanguageException(HRESULT error, HSTRING message, IUnknown* languageException) {
    (void)error;
    (void)message;
    (void)languageException;
}

void WINAPI WD_RoFailFastWithErrorContext(HRESULT error) {
    /* Fail-fast e terminal por definicao: encerra, nao trava em dialogo. */
    TerminateProcess(GetCurrentProcess(), (UINT)error);
}
