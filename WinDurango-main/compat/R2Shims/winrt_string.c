/* R2Shims: HSTRING funcional de verdade (mundo fechado R2).
 *
 * No R2 nenhum produtor de HSTRING do SO existe; a unica criadora usada
 * pelo codigo e WindowsCreateStringReference (fast-pass, sem alocar).
 * O esquema abaixo e auto-consistente entre Reference/Delete/GetRawBuffer.
 * Layout do cabecalho: 32 bytes (x64), igual ao HSTRING_HEADER do SDK.
 */
#include <windows.h>
#include <winstring.h>

#define WD_HSTRING_FLAG_FASTPASS ((UINT_PTR)1)

HRESULT WINAPI WD_WindowsCreateStringReference(PCWSTR sourceString, UINT32 length,
                                               HSTRING_HEADER* hstringHeader, HSTRING* string) {
    void** slots;
    if (!hstringHeader || !string) {
        return E_INVALIDARG;
    }
    if (length > 0 && !sourceString) {
        return E_INVALIDARG;
    }
    slots = (void**)hstringHeader;
    slots[0] = (void*)WD_HSTRING_FLAG_FASTPASS;
    slots[1] = (void*)(UINT_PTR)length;
    slots[2] = (void*)sourceString;
    slots[3] = NULL;
    *string = (HSTRING)hstringHeader;
    return S_OK;
}

HRESULT WINAPI WD_WindowsDeleteString(HSTRING string) {
    (void)string;
    /* Fast-pass nunca aloca: nada a liberar. */
    return S_OK;
}

PCWSTR WINAPI WD_WindowsGetStringRawBuffer(HSTRING string, UINT32* length) {
    static const wchar_t emptyBuffer = 0;
    void** slots;
    UINT32 len;
    PCWSTR buf;
    if (!string) {
        if (length) {
            *length = 0;
        }
        return &emptyBuffer;
    }
    slots = (void**)string;
    len = (UINT32)(UINT_PTR)slots[1];
    buf = (PCWSTR)slots[2];
    if (length) {
        *length = len;
    }
    return (len > 0 && buf) ? buf : &emptyBuffer;
}
