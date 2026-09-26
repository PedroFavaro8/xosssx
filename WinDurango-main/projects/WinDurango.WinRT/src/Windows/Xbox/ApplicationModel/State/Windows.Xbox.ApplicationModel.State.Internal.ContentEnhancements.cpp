#include "Windows.Xbox.ApplicationModel.State.Internal.ContentEnhancements.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::implementation
{
    uint64_t ContentEnhancements::GetEnhancementSettings(uint32_t titleId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: GetEnhancementSettings");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::EnhancementFeatureState ContentEnhancements::GetAutoHDREnabledGlobally()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: GetAutoHDREnabledGlobally");
        throw hresult_not_implemented();
    }
    bool ContentEnhancements::GetAutoHDRAllowedForGame(uint32_t titleId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: GetAutoHDRAllowedForGame");
        throw hresult_not_implemented();
    }
    bool ContentEnhancements::GetAutoHDREnabledForGame(uint32_t titleId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: GetAutoHDREnabledForGame");
        throw hresult_not_implemented();
    }
    void ContentEnhancements::SetAutoHDREnabledForGame(uint32_t titleId, bool isFeatureEnabled)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: SetAutoHDREnabledForGame");
        throw hresult_not_implemented();
    }
    bool ContentEnhancements::GetPerformanceModeAllowedForGame(uint32_t titleId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: GetPerformanceModeAllowedForGame");
        throw hresult_not_implemented();
    }
    bool ContentEnhancements::GetPerformanceModeEnabledForGame(uint32_t titleId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: GetPerformanceModeEnabledForGame");
        throw hresult_not_implemented();
    }
    void ContentEnhancements::SetPerformanceModeEnabledForGame(uint32_t titleId, bool isFeatureEnabled)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: SetPerformanceModeEnabledForGame");
        throw hresult_not_implemented();
    }
    bool ContentEnhancements::GetPerformanceModeForGameRequires120Hz(uint32_t titleId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: GetPerformanceModeForGameRequires120Hz");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::PerformanceModeDetails ContentEnhancements::GetPerformanceModeDetailsForGame(uint32_t titleId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: GetPerformanceModeDetailsForGame");
        throw hresult_not_implemented();
    }
    bool ContentEnhancements::GetAutoHDRAllowedForGameFromManifest(hstring const& aumid)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: GetAutoHDRAllowedForGameFromManifest");
        throw hresult_not_implemented();
    }
    bool ContentEnhancements::GetAutoHDREnabledForGameFromManifest(uint32_t titleId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: GetAutoHDREnabledForGameFromManifest");
        throw hresult_not_implemented();
    }
    bool ContentEnhancements::IsGen9AwareGame(winrt::guid const& legacyProductId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: IsGen9AwareGame");
        throw hresult_not_implemented();
    }
}
