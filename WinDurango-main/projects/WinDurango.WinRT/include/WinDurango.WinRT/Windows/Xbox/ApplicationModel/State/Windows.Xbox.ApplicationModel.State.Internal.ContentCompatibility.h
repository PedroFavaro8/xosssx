#pragma once
#include "Windows.Xbox.ApplicationModel.State.Internal.ContentCompatibility.g.h"

namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::implementation
{
    struct ContentCompatibility : ContentCompatibilityT<ContentCompatibility>
    {
        ContentCompatibility() = default;

        winrt::hresult IsContentCompatible(winrt::guid const& contentId);
        winrt::hresult IsContentCompatible(hstring const& productId);
        uint64_t GetQuickResumeFlags(uint32_t titleId);
        bool IsQuickResumeAllowedForEra(uint32_t titleId);
        bool IsQuickResumeBlockedForGameCore(uint32_t titleId);
        winrt::hresult IsXbox360ContentCompatible(winrt::guid const& legacyProductId);
        hstring GetXbox360StoreIdFromContentId(winrt::guid const& contentId);
        bool IsQuickResumeBlockedForServer(uint32_t titleId);
        uint32_t GetMacIdBehaviorForTitleOnServer(uint32_t titleId);
    };
}
namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::factory_implementation
{
    struct ContentCompatibility : ContentCompatibilityT<ContentCompatibility, implementation::ContentCompatibility>
    {
    };
}
