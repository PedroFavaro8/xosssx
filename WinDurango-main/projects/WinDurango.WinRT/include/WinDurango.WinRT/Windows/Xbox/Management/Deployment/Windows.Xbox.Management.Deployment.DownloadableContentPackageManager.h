#pragma once
#include <winrt/Windows.Foundation.h>
#include "Windows.Xbox.Management.Deployment.CheckForUpdateResult.g.h"
#include "Windows.Xbox.Management.Deployment.ChunkCompletedEventArgs.g.h"
#include "Windows.Xbox.Management.Deployment.ChunkSpecifiers.g.h"
#include "Windows.Xbox.Management.Deployment.ContentPackage.g.h"
#include "Windows.Xbox.Management.Deployment.LicenseTerminatedEventArgs.g.h"
#include "Windows.Xbox.Management.Deployment.RequestUpdatePackageResult.g.h"
#include "Windows.Xbox.Management.Deployment.DownloadableContentPackage.g.h"
#include "Windows.Xbox.Management.Deployment.DownloadableContentPackageInstallCompletedEventArgs.g.h"
#include "Windows.Xbox.Management.Deployment.DownloadableContentPackageManager.g.h"
#include <winrt/Windows.Foundation.Collections.h>

namespace winrt::Windows::Xbox::Management::Deployment::implementation
{
    struct CheckForUpdateResult : CheckForUpdateResultT<CheckForUpdateResult>
    {
        CheckForUpdateResult() = default;
        CheckForUpdateResult(bool updateAvail, bool updateMandatory) : updateAvail(updateAvail), updateMandatory(updateMandatory) {}

        bool IsUpdateAvailable();
        bool IsUpdateMandatory();
    private:
        bool updateAvail;
        bool updateMandatory;
    };

    struct ChunkCompletedEventArgs : ChunkCompletedEventArgsT<ChunkCompletedEventArgs>
    {
        ChunkCompletedEventArgs() = default;
        ChunkCompletedEventArgs(uint32_t chunkID) : chunkID(chunkID) {}

        uint32_t ChunkId();
    private:
        uint32_t chunkID;
    };

    struct ChunkSpecifiers : ChunkSpecifiersT<ChunkSpecifiers>
    {
        ChunkSpecifiers() = default;
        ChunkSpecifiers(winrt::Windows::Foundation::Collections::IVector<hstring> langs, winrt::Windows::Foundation::Collections::IVector<hstring> tags)
            : langs(langs), tags(tags) {}

        winrt::Windows::Foundation::Collections::IVector<hstring> Languages();
        winrt::Windows::Foundation::Collections::IVector<hstring> Tags();
    private:
        winrt::Windows::Foundation::Collections::IVector<hstring> langs;
        winrt::Windows::Foundation::Collections::IVector<hstring> tags;
    };

    struct ContentPackage : ContentPackageT<ContentPackage>
    {
        ContentPackage() = default;
        ContentPackage(hstring title, hstring content, hstring product, hstring packageFullName, 
            uint32_t contentType, hstring displayName, hstring description, hstring publisher, hstring version)
            : title(title), content(content), product(product), packageFullName(packageFullName), contentType(contentType),
            displayName(displayName), description(description), publisher(publisher), version(version) {}

        hstring TitleId();
        hstring ContentId();
        hstring ProductId();
        hstring PackageFullName();
        uint32_t ContentType();
        hstring DisplayName();
        hstring Description();
        hstring Publisher();
        hstring Version();
    private:
        hstring title;
        hstring content;
        hstring product;
        hstring packageFullName;
        uint32_t contentType;
        hstring displayName;
        hstring description;
        hstring publisher;
        hstring version;
    };

    struct LicenseTerminatedEventArgs : LicenseTerminatedEventArgsT<LicenseTerminatedEventArgs>
    {
        LicenseTerminatedEventArgs() = default;
        LicenseTerminatedEventArgs(winrt::hresult reason, hstring packageFullName, hstring userXuid) 
            : reason(reason), packageFullName(packageFullName), userXuid(userXuid) {}

        winrt::hresult Reason();
        hstring PackageFullName();
        hstring UserXuidIfCausedBySignout();
    private:
        winrt::hresult reason;
        hstring packageFullName;
        hstring userXuid;
    };

    struct RequestUpdatePackageResult : RequestUpdatePackageResultT<RequestUpdatePackageResult>
    {
        RequestUpdatePackageResult() = default;
        RequestUpdatePackageResult(winrt::hresult hres) : result(hres) {}

        winrt::hresult Result();
    private:
        winrt::hresult result;
    };

    struct DownloadableContentPackage : DownloadableContentPackageT<DownloadableContentPackage>
    {
        DownloadableContentPackage() = default;
        DownloadableContentPackage(hstring title, hstring content, hstring product, hstring packageFullName, hstring mountPath, 
            bool isMounted, uint32_t contentType, hstring displayName, hstring description, hstring publisher, hstring version, hstring mount)
            : title(title), content(content), product(product), packageFullName(packageFullName), mountPath(mountPath), isMounted(isMounted),
            contentType(contentType), displayName(displayName), description(description), publisher(publisher), version(version), mount(mount) {}

        hstring TitleId();
        hstring ContentId();
        hstring ProductId();
        hstring PackageFullName();
        hstring MountPath();
        bool IsMounted();
        uint32_t ContentType();
        hstring DisplayName();
        hstring Description();
        hstring Publisher();
        hstring Version();
        hstring Mount();
        void Unmount();
        void CheckLicense(bool& unk, bool& unka);
        winrt::event_token LicenseTerminated(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Management::Deployment::DownloadableContentPackage, winrt::Windows::Xbox::Management::Deployment::LicenseTerminatedEventArgs> const& handler);
        void LicenseTerminated(winrt::event_token const& token) noexcept;
    private:
        hstring title;
        hstring content;
        hstring product;
        hstring packageFullName;
        hstring mountPath;
        bool isMounted;
        uint32_t contentType;
        hstring displayName;
        hstring description;
        hstring publisher;
        hstring version;
        hstring mount;
        winrt::event<winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Management::Deployment::DownloadableContentPackage, winrt::Windows::Xbox::Management::Deployment::LicenseTerminatedEventArgs>> e_LicenseTerminated;
    };

    struct DownloadableContentPackageInstallCompletedEventArgs : DownloadableContentPackageInstallCompletedEventArgsT<DownloadableContentPackageInstallCompletedEventArgs>
    {
        DownloadableContentPackageInstallCompletedEventArgs() = default;
        DownloadableContentPackageInstallCompletedEventArgs(winrt::Windows::Xbox::Management::Deployment::TransferOperationType operationType, hstring packageFullName, winrt::guid contentId, winrt::hresult result)
            : operationType(operationType), packageFullName(packageFullName), contentId(contentId), result(result) {}

        winrt::Windows::Xbox::Management::Deployment::TransferOperationType OperationType();
        hstring PackageFullName();
        winrt::guid ContentId();
        winrt::hresult Result();
    private:
        winrt::Windows::Xbox::Management::Deployment::TransferOperationType operationType;
        hstring packageFullName;
        winrt::guid contentId;
        winrt::hresult result;
    };

    struct DownloadableContentPackageManager : DownloadableContentPackageManagerT<DownloadableContentPackageManager>
    {
        DownloadableContentPackageManager() = default;

        winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Management::Deployment::DownloadableContentPackage> FindPackages(winrt::Windows::Xbox::Management::Deployment::InstalledPackagesFilter const& unk);
        winrt::event_token DownloadableContentPackageInstallCompleted(winrt::Windows::Xbox::Management::Deployment::DownloadableContentPackageInstallCompletedEventHandler const& handler);
        void DownloadableContentPackageInstallCompleted(winrt::event_token const& token) noexcept;
        winrt::event_token DownloadableContentPackageInstallCompletedWithDetails(winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::Management::Deployment::DownloadableContentPackageInstallCompletedEventArgs> const& handler);
        void DownloadableContentPackageInstallCompletedWithDetails(winrt::event_token const& token) noexcept;
    private:
        winrt::event<winrt::Windows::Xbox::Management::Deployment::DownloadableContentPackageInstallCompletedEventHandler> e_DownloadableContentPackageInstallCompleted;
        winrt::event<winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::Management::Deployment::DownloadableContentPackageInstallCompletedEventArgs>> e_DownloadableContentPackageInstallCompletedWithDetails;
    };
}
namespace winrt::Windows::Xbox::Management::Deployment::factory_implementation
{
    struct DownloadableContentPackageManager : DownloadableContentPackageManagerT<DownloadableContentPackageManager, implementation::DownloadableContentPackageManager>
    {
    };
}
