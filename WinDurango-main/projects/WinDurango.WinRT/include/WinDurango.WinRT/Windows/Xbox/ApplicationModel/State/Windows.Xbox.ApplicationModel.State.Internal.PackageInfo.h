#pragma once
#include "Windows.Xbox.ApplicationModel.State.Internal.PackageInfo.g.h"
#include "Windows.Xbox.ApplicationModel.State.Internal.DlcInfo.g.h"

namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::implementation
{
    struct DlcInfo : DlcInfoT<DlcInfo>
    {
        DlcInfo() = default;

        winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo Package();
        hstring ShortName();
        hstring LongName();
        hstring Description();
        hstring ForegroundText();
        uint32_t BackgroundColor();
        hstring Logo();
        hstring WideLogo();
        hstring SmallLogo();
        winrt::guid AllowedProductId();
        winrt::Windows::Foundation::Collections::IVectorView<winrt::guid> RelatedMedia();
        hstring AllowedPackageFamilyName();
        winrt::Windows::Foundation::Collections::IVectorView<hstring> RelatedMediaFamilyNames();
        uint32_t RatingCategory();
        hstring Ratings();
    };
    
    struct PackageInfo : PackageInfoT<PackageInfo>
    {
        PackageInfo() = default;

        static winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> Find(winrt::Windows::Xbox::ApplicationModel::State::Internal::FindPackageInfoFilter const& filter);
        static winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> FindByDeviceId(winrt::guid const& deviceId, winrt::Windows::Xbox::ApplicationModel::State::Internal::FindPackageInfoFilter const& filter);
        static winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> FindByContentId(winrt::guid const& contentId);
        static winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> FindByProductId(winrt::guid const& productId);
        static winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> FindByTitleId(uint32_t titleId);
        static winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> FindByAllowedProductId(winrt::guid const& allowedProductId);
        static winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo FindByPackageInstanceId(hstring const& packageInstanceId);
        static winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> FindUniversalPackagesByFamilyName(hstring const& packageFamilyName);
        static winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> FindByAllowedPackageFamilyName(hstring const& allowedPackageFamilyName);
        static winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> FindUnparented();
        static winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo FindByFullName(hstring const& fullName);
        static winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> FindByTitleSearchString(hstring const& searchString, uint32_t maxResults);
        static winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo FindGameHub(winrt::guid const& gameHubId);
        static winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageInfo> FindPackagesForGameHub(winrt::guid const& gameHubId);
        hstring PackageInstanceId();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageContentType ContentType();
        bool IsInbox();
        uint64_t Version();
        hstring FullName();
        hstring FamilyName();
        hstring PublisherName();
        winrt::guid ContentId();
        winrt::guid ProductId();
        winrt::guid DeviceId();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::OsEnvironment OsEnvironment();
        bool ImplementsContentRestrictions();
        uint64_t Size();
        uint64_t PersistentLocalStorageSize();
        bool IsPreIndexed();
        bool HasContentId();
        winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::ApplicationModel::State::Internal::AppInfo> Apps();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::DlcInfo Dlc();
        winrt::Windows::Foundation::DateTime InstallDate();
        winrt::Windows::Foundation::DateTime UpdateDate();
        hstring OneStoreProductId();
        bool SupportsMultipleUsers();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::AppInfo FirstVisibleApp();
        bool IsStoreInstalledSystemApp();
        bool IsContainerless();
        winrt::Windows::Xbox::ApplicationModel::State::Internal::ConsoleGeneration Generation();
        winrt::guid BuildId();
        bool WasRemoteInstalled();
        bool IsCloudPackage();
        winrt::guid GameHubId();
        bool IsGameHub();
    };
}
namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::factory_implementation
{
    struct PackageInfo : PackageInfoT<PackageInfo, implementation::PackageInfo>
    {
    };
}
