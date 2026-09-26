#include "Windows.Xbox.ApplicationModel.State.Internal.ContentCompatibility.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::implementation
{
    winrt::hresult ContentCompatibility::IsContentCompatible(winrt::guid const& contentId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: IsContentCompatible");
        throw hresult_not_implemented();
    }
    winrt::hresult ContentCompatibility::IsContentCompatible(hstring const& productId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: IsContentCompatible");
        throw hresult_not_implemented();
    }
    uint64_t ContentCompatibility::GetQuickResumeFlags(uint32_t titleId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: GetQuickResumeFlags");
        throw hresult_not_implemented();
    }
    bool ContentCompatibility::IsQuickResumeAllowedForEra(uint32_t titleId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: IsQuickResumeAllowedForEra");
        throw hresult_not_implemented();
    }
    bool ContentCompatibility::IsQuickResumeBlockedForGameCore(uint32_t titleId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: IsQuickResumeBlockedForGameCore");
        throw hresult_not_implemented();
    }
    winrt::hresult ContentCompatibility::IsXbox360ContentCompatible(winrt::guid const& legacyProductId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: IsXbox360ContentCompatible");
        throw hresult_not_implemented();
    }
    hstring ContentCompatibility::GetXbox360StoreIdFromContentId(winrt::guid const& contentId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: GetXbox360StoreIdFromContentId");
        throw hresult_not_implemented();
    }
    bool ContentCompatibility::IsQuickResumeBlockedForServer(uint32_t titleId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: IsQuickResumeBlockedForServer");
        throw hresult_not_implemented();
    }
    uint32_t ContentCompatibility::GetMacIdBehaviorForTitleOnServer(uint32_t titleId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: GetMacIdBehaviorForTitleOnServer");
        throw hresult_not_implemented();
    }
}
