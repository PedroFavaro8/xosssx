#pragma once
#include "Windows.Xbox.Chat.ChatUserCorrelation.g.h"

namespace winrt::Windows::Xbox::Chat::implementation
{
    struct ChatUserCorrelation : ChatUserCorrelationT<ChatUserCorrelation>
    {
        ChatUserCorrelation() = default;

        winrt::Windows::Xbox::System::User User();
    };
}
namespace winrt::Windows::Xbox::Chat::factory_implementation
{
    struct ChatUserCorrelation : ChatUserCorrelationT<ChatUserCorrelation, implementation::ChatUserCorrelation>
    {
    };
}
