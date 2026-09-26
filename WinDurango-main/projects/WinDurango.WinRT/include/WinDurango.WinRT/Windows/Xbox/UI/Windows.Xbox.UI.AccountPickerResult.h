#pragma once
#include "Windows.Xbox.UI.AccountPickerResult.g.h"

namespace winrt::Windows::Xbox::UI::implementation
{
    struct AccountPickerResult : AccountPickerResultT<AccountPickerResult>
    {
        AccountPickerResult() = default;

        winrt::Windows::Xbox::System::User User();
    };
}