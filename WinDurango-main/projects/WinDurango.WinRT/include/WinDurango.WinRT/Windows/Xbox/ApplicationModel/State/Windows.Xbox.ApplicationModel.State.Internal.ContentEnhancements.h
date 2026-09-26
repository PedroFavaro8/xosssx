#pragma once
#include "Windows.Xbox.ApplicationModel.State.Internal.ContentEnhancements.g.h"

namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::implementation
{
    struct ContentEnhancements : ContentEnhancementsT<ContentEnhancements>
    {
        ContentEnhancements() = default;

        uint64_t GetEnhancementSettings(uint32_t titleId);
        winrt::Windows::Xbox::ApplicationModel::State::Internal::EnhancementFeatureState GetAutoHDREnabledGlobally();
        bool GetAutoHDRAllowedForGame(uint32_t titleId);
        bool GetAutoHDREnabledForGame(uint32_t titleId);
        void SetAutoHDREnabledForGame(uint32_t titleId, bool isFeatureEnabled);
        bool GetPerformanceModeAllowedForGame(uint32_t titleId);
        bool GetPerformanceModeEnabledForGame(uint32_t titleId);
        void SetPerformanceModeEnabledForGame(uint32_t titleId, bool isFeatureEnabled);
        bool GetPerformanceModeForGameRequires120Hz(uint32_t titleId);
        winrt::Windows::Xbox::ApplicationModel::State::Internal::PerformanceModeDetails GetPerformanceModeDetailsForGame(uint32_t titleId);
        bool GetAutoHDRAllowedForGameFromManifest(hstring const& aumid);
        bool GetAutoHDREnabledForGameFromManifest(uint32_t titleId);
        bool IsGen9AwareGame(winrt::guid const& legacyProductId);
    };
}
namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::factory_implementation
{
    struct ContentEnhancements : ContentEnhancementsT<ContentEnhancements, implementation::ContentEnhancements>
    {
    };
}
