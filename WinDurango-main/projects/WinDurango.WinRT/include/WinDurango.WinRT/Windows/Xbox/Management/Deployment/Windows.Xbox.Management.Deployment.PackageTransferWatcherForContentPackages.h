#pragma once
#include "Windows.Xbox.Management.Deployment.PackageTransferWatcherForContentPackages.g.h"

namespace winrt::Windows::Xbox::Management::Deployment::implementation
{
    struct PackageTransferWatcherForContentPackages
    {
        PackageTransferWatcherForContentPackages() = default;

        static winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher CreateForContentPackage(winrt::Windows::Xbox::Management::Deployment::ContentPackage const& unk);
        static winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher CreateForDownloadableContentPackage(winrt::Windows::Xbox::Management::Deployment::DownloadableContentPackage const& unk);
    };
}
namespace winrt::Windows::Xbox::Management::Deployment::factory_implementation
{
    struct PackageTransferWatcherForContentPackages : PackageTransferWatcherForContentPackagesT<PackageTransferWatcherForContentPackages, implementation::PackageTransferWatcherForContentPackages>
    {
    };
}
