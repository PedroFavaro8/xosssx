#include "Windows.Xbox.Networking.ErrorMessages.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::Networking::implementation
{
    hstring ErrorMessages::GetMessageForError(uint32_t errorCode)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: GetMessageForError");
        throw hresult_not_implemented();
    }
}
