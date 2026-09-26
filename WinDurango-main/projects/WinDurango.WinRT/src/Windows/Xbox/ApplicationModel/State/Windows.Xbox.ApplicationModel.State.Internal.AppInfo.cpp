#include "Windows.Xbox.ApplicationModel.State.Internal.AppInfo.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::implementation
{
    winrt::Windows::Xbox::ApplicationModel::State::Internal::AppInfo AppInfo::FindByAumid(hstring const& aumid)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FindByAumid");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::AppInfo> AppInfo::FindByTitleId(uint32_t titleId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FindByTitleId");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo AppInfo::Package()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: Package");
        throw hresult_not_implemented();
    }
    hstring AppInfo::PackageRelativeId()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: PackageRelativeId");
        throw hresult_not_implemented();
    }
    hstring AppInfo::ShortName()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: ShortName");
        throw hresult_not_implemented();
    }
    hstring AppInfo::LongName()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: LongName");
        throw hresult_not_implemented();
    }
    hstring AppInfo::Description()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: Description");
        throw hresult_not_implemented();
    }
    hstring AppInfo::ForegroundText()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: ForegroundText");
        throw hresult_not_implemented();
    }
    uint32_t AppInfo::BackgroundColor()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: BackgroundColor");
        throw hresult_not_implemented();
    }
    hstring AppInfo::Logo()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: Logo");
        throw hresult_not_implemented();
    }
    hstring AppInfo::WideLogo()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: WideLogo");
        throw hresult_not_implemented();
    }
    hstring AppInfo::SmallLogo()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: SmallLogo");
        throw hresult_not_implemented();
    }
    hstring AppInfo::Aumid()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: Aumid");
        throw hresult_not_implemented();
    }
    hstring AppInfo::SplashScreen()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: SplashScreen");
        throw hresult_not_implemented();
    }
    uint32_t AppInfo::TitleId()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: TitleId");
        throw hresult_not_implemented();
    }
    winrt::guid AppInfo::PrimaryServiceConfigId()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: PrimaryServiceConfigId");
        throw hresult_not_implemented();
    }
    hstring AppInfo::VuiAlm()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: VuiAlm");
        throw hresult_not_implemented();
    }
    hstring AppInfo::VuiPron()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: VuiPron");
        throw hresult_not_implemented();
    }
    uint32_t AppInfo::RatingCategory()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: RatingCategory");
        throw hresult_not_implemented();
    }
    hstring AppInfo::Ratings()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: Ratings");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::AppListEntry AppInfo::AppListEntry()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: AppListEntry");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::ConsoleType AppInfo::ConsoleType()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: ConsoleType");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::XboxLiveTier AppInfo::XboxLiveTier()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: XboxLiveTier");
        throw hresult_not_implemented();
    }
    hstring AppInfo::InteractiveElements()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: InteractiveElements");
        throw hresult_not_implemented();
    }
    bool AppInfo::RequiresXboxLive()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: RequiresXboxLive");
        throw hresult_not_implemented();
    }
    hstring AppInfo::ExecutableName()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: ExecutableName");
        throw hresult_not_implemented();
    }
    bool AppInfo::IsXboxOneXEnhanced()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: IsXboxOneXEnhanced");
        throw hresult_not_implemented();
    }
    bool AppInfo::IsDemo()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: IsDemo");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::GameAttributes AppInfo::GameAttributes()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: GameAttributes");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::Genre AppInfo::Genres()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: Genres");
        throw hresult_not_implemented();
    }
    hstring AppInfo::CloudId()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: CloudId");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::InteractiveElement AppInfo::InteractiveElementFlags()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: InteractiveElementFlags");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::TechnicalFeature AppInfo::TechnicalFeatures()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: TechnicalFeatures");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::AccessibilityFeature AppInfo::AccessibilityFeatures()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: AccessibilityFeatures");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::Language AppInfo::AudioSupportedLanguages()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: AudioSupportedLanguages");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::Language2 AppInfo::AudioSupportedLanguages2()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: AudioSupportedLanguages2");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::Language AppInfo::InterfaceSupportedLanguages()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: InterfaceSupportedLanguages");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::Language2 AppInfo::InterfaceSupportedLanguages2()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: InterfaceSupportedLanguages2");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::Language AppInfo::SubtitleSupportedLanguages()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: SubtitleSupportedLanguages");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::Language2 AppInfo::SubtitleSupportedLanguages2()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: SubtitleSupportedLanguages2");
        throw hresult_not_implemented();
    }
}
