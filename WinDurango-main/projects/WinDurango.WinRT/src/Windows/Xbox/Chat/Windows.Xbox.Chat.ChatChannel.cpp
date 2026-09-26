#include "Windows.Xbox.Chat.ChatChannel.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::Chat::implementation
{
    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Chat::ChatParticipant> ChatChannel::Participants()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Chat::ChatChannel", "Unimplemented: Participants");
        throw hresult_not_implemented();
    }
}
