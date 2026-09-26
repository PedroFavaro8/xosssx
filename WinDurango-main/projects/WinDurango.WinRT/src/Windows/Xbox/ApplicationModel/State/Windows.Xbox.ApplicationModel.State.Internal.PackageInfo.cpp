#include "Windows.Xbox.ApplicationModel.State.Internal.PackageInfo.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::implementation
{
    winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo DlcInfo::Package()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: Package");
        throw hresult_not_implemented();
    }
    hstring DlcInfo::ShortName()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: ShortName");
        throw hresult_not_implemented();
    }
    hstring DlcInfo::LongName()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: LongName");
        throw hresult_not_implemented();
    }
    hstring DlcInfo::Description()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: Description");
        throw hresult_not_implemented();
    }
    hstring DlcInfo::ForegroundText()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: ForegroundText");
        throw hresult_not_implemented();
    }
    uint32_t DlcInfo::BackgroundColor()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: BackgroundColor");
        throw hresult_not_implemented();
    }
    hstring DlcInfo::Logo()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: Logo");
        throw hresult_not_implemented();
    }
    hstring DlcInfo::WideLogo()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: WideLogo");
        throw hresult_not_implemented();
    }
    hstring DlcInfo::SmallLogo()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: SmallLogo");
        throw hresult_not_implemented();
    }
    winrt::guid DlcInfo::AllowedProductId()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: AllowedProductId");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IVectorView<winrt::guid> DlcInfo::RelatedMedia()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: RelatedMedia");
        throw hresult_not_implemented();
    }
    hstring DlcInfo::AllowedPackageFamilyName()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: AllowedPackageFamilyName");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IVectorView<hstring> DlcInfo::RelatedMediaFamilyNames()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: RelatedMediaFamilyNames");
        throw hresult_not_implemented();
    }
    uint32_t DlcInfo::RatingCategory()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: RatingCategory");
        throw hresult_not_implemented();
    }
    hstring DlcInfo::Ratings()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: Ratings");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> PackageInfo::Find(winrt::Windows::Xbox::ApplicationModel::State::Internal::FindPackageInfoFilter const& filter)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: Find");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> PackageInfo::FindByDeviceId(winrt::guid const& deviceId, winrt::Windows::Xbox::ApplicationModel::State::Internal::FindPackageInfoFilter const& filter)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FindByDeviceId");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> PackageInfo::FindByContentId(winrt::guid const& contentId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FindByContentId");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> PackageInfo::FindByProductId(winrt::guid const& productId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FindByProductId");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> PackageInfo::FindByTitleId(uint32_t titleId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FindByTitleId");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> PackageInfo::FindByAllowedProductId(winrt::guid const& allowedProductId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FindByAllowedProductId");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo PackageInfo::FindByPackageInstanceId(hstring const& packageInstanceId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FindByPackageInstanceId");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> PackageInfo::FindUniversalPackagesByFamilyName(hstring const& packageFamilyName)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FindUniversalPackagesByFamilyName");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> PackageInfo::FindByAllowedPackageFamilyName(hstring const& allowedPackageFamilyName)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FindByAllowedPackageFamilyName");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> PackageInfo::FindUnparented()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FindUnparented");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo PackageInfo::FindByFullName(hstring const& fullName)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FindByFullName");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> PackageInfo::FindByTitleSearchString(hstring const& searchString, uint32_t maxResults)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FindByTitleSearchString");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo PackageInfo::FindGameHub(winrt::guid const& gameHubId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FindGameHub");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> PackageInfo::FindPackagesForGameHub(winrt::guid const& gameHubId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FindPackagesForGameHub");
        throw hresult_not_implemented();
    }
    hstring PackageInfo::PackageInstanceId()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: PackageInstanceId");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageContentType PackageInfo::ContentType()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: ContentType");
        throw hresult_not_implemented();
    }
    bool PackageInfo::IsInbox()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: IsInbox");
        throw hresult_not_implemented();
    }
    uint64_t PackageInfo::Version()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: Version");
        throw hresult_not_implemented();
    }
    hstring PackageInfo::FullName()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FullName");
        throw hresult_not_implemented();
    }
    hstring PackageInfo::FamilyName()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FamilyName");
        throw hresult_not_implemented();
    }
    hstring PackageInfo::PublisherName()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: PublisherName");
        throw hresult_not_implemented();
    }
    winrt::guid PackageInfo::ContentId()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: ContentId");
        throw hresult_not_implemented();
    }
    winrt::guid PackageInfo::ProductId()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: ProductId");
        throw hresult_not_implemented();
    }
    winrt::guid PackageInfo::DeviceId()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: DeviceId");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::OsEnvironment PackageInfo::OsEnvironment()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: OsEnvironment");
        throw hresult_not_implemented();
    }
    bool PackageInfo::ImplementsContentRestrictions()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: ImplementsContentRestrictions");
        throw hresult_not_implemented();
    }
    uint64_t PackageInfo::Size()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: Size");
        throw hresult_not_implemented();
    }
    uint64_t PackageInfo::PersistentLocalStorageSize()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: PersistentLocalStorageSize");
        throw hresult_not_implemented();
    }
    bool PackageInfo::IsPreIndexed()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: IsPreIndexed");
        throw hresult_not_implemented();
    }
    bool PackageInfo::HasContentId()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: HasContentId");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::AppInfo> PackageInfo::Apps()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: Apps");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::DlcInfo PackageInfo::Dlc()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: Dlc");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::DateTime PackageInfo::InstallDate()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: InstallDate");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::DateTime PackageInfo::UpdateDate()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: UpdateDate");
        throw hresult_not_implemented();
    }
    hstring PackageInfo::OneStoreProductId()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: OneStoreProductId");
        throw hresult_not_implemented();
    }
    bool PackageInfo::SupportsMultipleUsers()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: SupportsMultipleUsers");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::AppInfo PackageInfo::FirstVisibleApp()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FirstVisibleApp");
        throw hresult_not_implemented();
    }
    bool PackageInfo::IsStoreInstalledSystemApp()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: IsStoreInstalledSystemApp");
        throw hresult_not_implemented();
    }
    bool PackageInfo::IsContainerless()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: IsContainerless");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::ApplicationModel::State::Internal::ConsoleGeneration PackageInfo::Generation()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: Generation");
        throw hresult_not_implemented();
    }
    winrt::guid PackageInfo::BuildId()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: BuildId");
        throw hresult_not_implemented();
    }
    bool PackageInfo::WasRemoteInstalled()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: WasRemoteInstalled");
        throw hresult_not_implemented();
    }
    bool PackageInfo::IsCloudPackage()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: IsCloudPackage");
        throw hresult_not_implemented();
    }
    winrt::guid PackageInfo::GameHubId()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: GameHubId");
        throw hresult_not_implemented();
    }
    bool PackageInfo::IsGameHub()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: IsGameHub");
        throw hresult_not_implemented();
    }
}
