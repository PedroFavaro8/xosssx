#include "Windows.Xbox.ApplicationModel.State.Internal.PackageInfoEvents.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::implementation
{
    hstring PackageChangedEventArgs::PackageInstanceId()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: PackageInstanceId");
        throw hresult_not_implemented();
    }
    winrt::event_token PackageInfoEvents::PackageChanged(winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageChangedEventArgs> const& handler)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: PackageChanged");
        throw hresult_not_implemented();
    }
    void PackageInfoEvents::PackageChanged(winrt::event_token const& token) noexcept
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: PackageChanged");
        throw hresult_not_implemented();
    }
    winrt::event_token PackageInfoEvents::PackageReset(winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: PackageReset");
        throw hresult_not_implemented();
    }
    void PackageInfoEvents::PackageReset(winrt::event_token const& token) noexcept
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: PackageReset");
        throw hresult_not_implemented();
    }
    void PackageInfoEvents::LogStats()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: LogStats");
        throw hresult_not_implemented();
    }
}
