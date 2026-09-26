#include "Windows.Xbox.ApplicationModel.Core.UserContextLookup.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::ApplicationModel::Core::implementation
{
    void UserContextLookup::RefreshUserContext(hstring const& aumid)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::Core", "Unimplemented: RefreshUserContext");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::System::User UserContextLookup::GetCurrentUserContext(hstring const& aumid)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::Core", "Unimplemented: GetCurrentUserContext");
        throw hresult_not_implemented();
    }
    void UserContextLookup::NotifyUserContextChanged(uint32_t userId, uint32_t userSequenceId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::Core", "Unimplemented: NotifyUserContextChanged");
        throw hresult_not_implemented();
    }
}
