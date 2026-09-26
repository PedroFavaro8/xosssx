#include "Windows.Xbox.UI.AccountPickerResult.h"
#include "Windows.Xbox.System.User.h"

namespace winrt::Windows::Xbox::UI::implementation
{
    winrt::Windows::Xbox::System::User AccountPickerResult::User()
    {
        return winrt::Windows::Xbox::System::implementation::User::Users().GetAt(1);
    }
}
