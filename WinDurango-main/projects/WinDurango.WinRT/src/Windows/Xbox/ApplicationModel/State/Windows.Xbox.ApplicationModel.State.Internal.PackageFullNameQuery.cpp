#include "Windows.Xbox.ApplicationModel.State.Internal.PackageFullNameQuery.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::implementation
{
    bool PackageFullNameQuery::IsInbox(hstring const& packageFullName)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: IsInbox");
        throw hresult_not_implemented();
    }
    bool PackageFullNameQuery::IsEra(hstring const& packageFullName)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: IsEra");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageContentType PackageFullNameQuery::GetContentType(hstring const& packageFullName)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: GetContentType");
        throw hresult_not_implemented();
    }
    bool PackageFullNameQuery::IsGameCore(hstring const& packageFullName)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: IsGameCore");
        throw hresult_not_implemented();
    }
}
