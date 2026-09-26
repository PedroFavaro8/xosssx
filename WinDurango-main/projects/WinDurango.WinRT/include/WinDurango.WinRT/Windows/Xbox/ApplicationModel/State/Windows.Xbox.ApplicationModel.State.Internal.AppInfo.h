#pragma once
#include "Windows.Xbox.ApplicationModel.State.Internal.AppInfo.g.h"

namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::implementation
{
    struct AppInfo : AppInfoT<AppInfo>
    {
        AppInfo() = default;

        static winrt::Windows::Xbox::ApplicationModel::State::Internal::AppInfo FindByAumid(hstring const& aumid);
        static winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::AppInfo> FindByTitleId(uint32_t titleId);
        winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo Package();
        hstring PackageRelativeId();
        hstring ShortName();
        hstring LongName();
        hstring Description();
        hstring ForegroundText();
        uint32_t BackgroundColor();
        hstring Logo();
        hstring WideLogo();
        hstring SmallLogo();
        hstring Aumid();
        hstring SplashScreen();
        uint32_t TitleId();
        winrt::guid PrimaryServiceConfigId();
        hstring VuiAlm();
        hstring VuiPron();
        uint32_t RatingCategory();
        hstring Ratings();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::AppListEntry AppListEntry();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::ConsoleType ConsoleType();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::XboxLiveTier XboxLiveTier();
        hstring InteractiveElements();
        bool RequiresXboxLive();
        hstring ExecutableName();
        bool IsXboxOneXEnhanced();
        bool IsDemo();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::GameAttributes GameAttributes();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::Genre Genres();
        hstring CloudId();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::InteractiveElement InteractiveElementFlags();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::TechnicalFeature TechnicalFeatures();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::AccessibilityFeature AccessibilityFeatures();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::Language AudioSupportedLanguages();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::Language2 AudioSupportedLanguages2();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::Language InterfaceSupportedLanguages();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::Language2 InterfaceSupportedLanguages2();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::Language SubtitleSupportedLanguages();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::Language2 SubtitleSupportedLanguages2();
    };
}
namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::factory_implementation
{
    struct AppInfo : AppInfoT<AppInfo, implementation::AppInfo>
    {
    };
}
