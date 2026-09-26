#include "Windows.Xbox.Input.NavigationController.h"
#include "Windows.Xbox.Input.Gamepad.h"
#include "WinDurangoWinRT.h"
namespace winrt::Windows::Xbox::Input::implementation
{
    uint64_t NavigationController::Id()
    {
        return id;
    }

    hstring NavigationController::Type()
    {
        return L"Windows.Xbox.Input.NavigationController";
    }

    winrt::Windows::Xbox::System::User NavigationController::User()
    {
        return winrt::Windows::Xbox::System::implementation::User::GetUserById(static_cast<uint32_t>(id % 4));
    }

    winrt::Windows::Xbox::Input::INavigationReading NavigationController::GetNavigationReading()
    {
        Gamepad gamepad(id, true);
        return gamepad.GetNavigationReading();
    }

    winrt::Windows::Xbox::Input::RawNavigationReading NavigationController::GetRawNavigationReading()
    {
        Gamepad gamepad(id, true);
        return gamepad.GetRawNavigationReading();
    }
}
