#pragma once
#include "Windows.Xbox.Chat.ChatEncoder.g.h"

namespace winrt::Windows::Xbox::Chat::implementation
{
    struct ChatEncoder : ChatEncoderT<ChatEncoder>
    {
        ChatEncoder() = default;

        ChatEncoder(winrt::Windows::Xbox::Chat::Format const& format, winrt::Windows::Xbox::Chat::EncodingQuality const& quality);
        void Encode(winrt::Windows::Storage::Streams::IBuffer const& buffer, winrt::Windows::Storage::Streams::IBuffer& encodedBuffer);
        int32_t IsDataInFlight();
        void Encode(winrt::Windows::Storage::Streams::IBuffer const& buffer, winrt::Windows::Xbox::Chat::ChatBufferSource const& source, winrt::Windows::Storage::Streams::IBuffer& encodedBuffer, winrt::Windows::Xbox::Chat::ChatBufferSource& encodedSource);
    };
}
namespace winrt::Windows::Xbox::Chat::factory_implementation
{
    struct ChatEncoder : ChatEncoderT<ChatEncoder, implementation::ChatEncoder>
    {
    };
}
