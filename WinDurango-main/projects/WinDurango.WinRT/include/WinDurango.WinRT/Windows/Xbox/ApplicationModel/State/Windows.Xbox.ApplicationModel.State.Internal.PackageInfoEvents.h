#pragma once
#include "Windows.Xbox.ApplicationModel.State.Internal.PackageChangedEventArgs.g.h"
#include "Windows.Xbox.ApplicationModel.State.Internal.PackageInfoEvents.g.h"

namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::implementation
{
    struct PackageChangedEventArgs : PackageChangedEventArgsT<PackageChangedEventArgs>
    {
        PackageChangedEventArgs() = default;

        hstring PackageInstanceId();
    };
    
    struct PackageInfoEvents : PackageInfoEventsT<PackageInfoEvents>
    {
        PackageInfoEvents() = default;

        winrt::event_token PackageChanged(winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageChangedEventArgs> const& handler);
        void PackageChanged(winrt::event_token const& token) noexcept;
        winrt::event_token PackageReset(winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler);
        void PackageReset(winrt::event_token const& token) noexcept;
        void LogStats();
    };
}
namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::factory_implementation
{
    struct PackageInfoEvents : PackageInfoEventsT<PackageInfoEvents, implementation::PackageInfoEvents>
    {
    };
}