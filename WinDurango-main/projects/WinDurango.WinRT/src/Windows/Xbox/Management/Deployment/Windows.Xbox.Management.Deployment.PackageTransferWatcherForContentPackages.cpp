#include "Windows.Xbox.Management.Deployment.PackageTransferWatcherForContentPackages.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::Management::Deployment::implementation
{
    winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher PackageTransferWatcherForContentPackages::CreateForContentPackage(winrt::Windows::Xbox::Management::Deployment::ContentPackage const& unk)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Management::Deployment", "Unimplemented: CreateForContentPackage");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher PackageTransferWatcherForContentPackages::CreateForDownloadableContentPackage(winrt::Windows::Xbox::Management::Deployment::DownloadableContentPackage const& unk)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Management::Deployment", "Unimplemented: CreateForDownloadableContentPackage");
        throw hresult_not_implemented();
    }
}
