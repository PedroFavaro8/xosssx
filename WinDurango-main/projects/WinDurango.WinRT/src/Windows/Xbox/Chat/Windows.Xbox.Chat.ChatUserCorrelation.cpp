#include "Windows.Xbox.Chat.ChatUserCorrelation.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::Chat::implementation
{
    winrt::Windows::Xbox::System::User ChatUserCorrelation::User()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Chat::ChatUserCorrelation", "Unimplemented: User");
        throw hresult_not_implemented();
    }
}
