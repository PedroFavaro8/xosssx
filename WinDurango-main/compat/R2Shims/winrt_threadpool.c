/* R2Shims: TrySubmitThreadpoolCallback real via QueueUserWorkItem (R2 tem). */
#include <windows.h>
#include <stdlib.h>

typedef struct WD_TP_CTXT {
    PTP_SIMPLE_CALLBACK callback;
    PVOID context;
} WD_TP_CTXT;

static DWORD WINAPI WD_TpThunk(LPVOID param) {
    WD_TP_CTXT* ctxt = (WD_TP_CTXT*)param;
    PTP_SIMPLE_CALLBACK callback = ctxt->callback;
    PVOID context = ctxt->context;
    free(ctxt);
    callback(NULL, context, NULL);
    return 0;
}

BOOL WINAPI WD_TrySubmitThreadpoolCallback(PTP_SIMPLE_CALLBACK pfns, PVOID pv,
                                           PTP_CALLBACK_ENVIRON pcbe) {
    WD_TP_CTXT* ctxt;
    (void)pcbe;
    if (!pfns) {
        SetLastError(ERROR_INVALID_PARAMETER);
        return FALSE;
    }
    ctxt = (WD_TP_CTXT*)malloc(sizeof(WD_TP_CTXT));
    if (!ctxt) {
        SetLastError(ERROR_NOT_ENOUGH_MEMORY);
        return FALSE;
    }
    ctxt->callback = pfns;
    ctxt->context = pv;
    if (!QueueUserWorkItem(WD_TpThunk, ctxt, WT_EXECUTEDEFAULT)) {
        free(ctxt);
        return FALSE;
    }
    return TRUE;
}
