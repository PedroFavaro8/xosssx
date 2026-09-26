#pragma once
#include "Windows.Xbox.Networking.ErrorMessages.g.h"

namespace winrt::Windows::Xbox::Networking::implementation
{
    struct ErrorMessages
    {
        ErrorMessages() = default;

        static hstring GetMessageForError(uint32_t errorCode);
    };
}
namespace winrt::Windows::Xbox::Networking::factory_implementation
{
    struct ErrorMessages : ErrorMessagesT<ErrorMessages, implementation::ErrorMessages>
    {
    };
}
