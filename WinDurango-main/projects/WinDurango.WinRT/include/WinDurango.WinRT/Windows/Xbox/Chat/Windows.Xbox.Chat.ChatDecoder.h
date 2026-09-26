#pragma once
#include "Windows.Xbox.Chat.ChatDecoder.g.h"

namespace winrt::Windows::Xbox::Chat::implementation
{
    struct ChatDecoder : ChatDecoderT<ChatDecoder>
    {
        ChatDecoder() = default;

        winrt::Windows::Xbox::Chat::Format Format();
        void Decode(winrt::Windows::Storage::Streams::IBuffer const& buffer, winrt::Windows::Storage::Streams::IBuffer& decodedBuffer);
        int32_t IsDataInFlight();
    };
}
namespace winrt::Windows::Xbox::Chat::factory_implementation
{
    struct ChatDecoder : ChatDecoderT<ChatDecoder, implementation::ChatDecoder>
    {
    };
}
