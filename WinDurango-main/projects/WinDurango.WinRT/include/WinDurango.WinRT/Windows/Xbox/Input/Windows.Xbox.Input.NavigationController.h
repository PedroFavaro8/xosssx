#pragma once
#include "Windows.Xbox.Input.NavigationController.g.h"
#include "Windows.Xbox.System.User.h"
#include <Windows.h>

namespace winrt::Windows::Xbox::Input::implementation
{
    struct NavigationController : NavigationControllerT<NavigationController>
    {
        NavigationController() = default;
        NavigationController(uint64_t id) : id(id) {}

        uint64_t Id();
        hstring Type();
        winrt::Windows::Xbox::System::User User();
        winrt::Windows::Xbox::Input::INavigationReading GetNavigationReading();
        winrt::Windows::Xbox::Input::RawNavigationReading GetRawNavigationReading();
    private:
        uint64_t id = 0;
    };
}
namespace winrt::Windows::Xbox::Input::factory_implementation
{
    struct NavigationController : NavigationControllerT<NavigationController, implementation::NavigationController>
    {
    };
}
