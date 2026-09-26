#include "Windows.Xbox.Chat.ChatDecoder.h"
#include "WinDurangoWinRT.h"
#include "Windows.Xbox.Chat.Format.h"

namespace winrt::Windows::Xbox::Chat::implementation
{
    winrt::Windows::Xbox::Chat::Format ChatDecoder::Format()
    {
        return winrt::make<implementation::Format>();
    }
    void ChatDecoder::Decode(winrt::Windows::Storage::Streams::IBuffer const& buffer, winrt::Windows::Storage::Streams::IBuffer& decodedBuffer)
    {

    }
    int32_t ChatDecoder::IsDataInFlight()
    {
        return 0;
    }
}
