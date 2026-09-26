#include "Windows.Xbox.Chat.ChatEncoder.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::Chat::implementation
{
    ChatEncoder::ChatEncoder(winrt::Windows::Xbox::Chat::Format const& format, winrt::Windows::Xbox::Chat::EncodingQuality const& quality)
    {

    }
    void ChatEncoder::Encode(winrt::Windows::Storage::Streams::IBuffer const& buffer, winrt::Windows::Storage::Streams::IBuffer& encodedBuffer)
    {

    }
    int32_t ChatEncoder::IsDataInFlight()
    {
        return 0;
    }
    void ChatEncoder::Encode(winrt::Windows::Storage::Streams::IBuffer const& buffer, winrt::Windows::Xbox::Chat::ChatBufferSource const& source, winrt::Windows::Storage::Streams::IBuffer& encodedBuffer, winrt::Windows::Xbox::Chat::ChatBufferSource& encodedSource)
    {

    }
}
