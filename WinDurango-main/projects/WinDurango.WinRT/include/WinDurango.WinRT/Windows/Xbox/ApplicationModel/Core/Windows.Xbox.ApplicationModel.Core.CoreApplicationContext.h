#pragma once
#include "Windows.Xbox.ApplicationModel.Core.CoreApplicationContext.g.h"
#include <winrt/Windows.Foundation.h>

namespace winrt::Windows::Xbox::ApplicationModel::Core::implementation
{
    struct CoreApplicationContext
    {
        CoreApplicationContext() = default;

        static winrt::Windows::Xbox::System::User CurrentUser();
        static winrt::event_token CurrentUserChanged(winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler);
        static void CurrentUserChanged(winrt::event_token const& token) noexcept;
        static void SetCurrentUser(winrt::Windows::Xbox::System::User const& value);
        static winrt::Windows::Xbox::System::User CurrentSystemUser();
        static winrt::event_token CurrentSystemUserChanged(winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler);
        static void CurrentSystemUserChanged(winrt::event_token const& token) noexcept;
    };
}
namespace winrt::Windows::Xbox::ApplicationModel::Core::factory_implementation
{
    struct CoreApplicationContext : CoreApplicationContextT<CoreApplicationContext, implementation::CoreApplicationContext>
    {
    };
}

