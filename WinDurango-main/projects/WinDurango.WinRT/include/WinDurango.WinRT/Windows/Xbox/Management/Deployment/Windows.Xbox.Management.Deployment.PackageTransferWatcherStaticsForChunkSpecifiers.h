#pragma once
#include "Windows.Xbox.Management.Deployment.PackageTransferWatcherStaticsForChunkSpecifiers.g.h"

namespace winrt::Windows::Xbox::Management::Deployment::implementation
{
    struct PackageTransferWatcherStaticsForChunkSpecifiers
    {
        PackageTransferWatcherStaticsForChunkSpecifiers() = default;

        static winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher CreateForChunkSpecifiers(winrt::Windows::ApplicationModel::Package const& unk, winrt::Windows::Xbox::Management::Deployment::ChunkSpecifiers const& unka);
    };
}
namespace winrt::Windows::Xbox::Management::Deployment::factory_implementation
{
    struct PackageTransferWatcherStaticsForChunkSpecifiers : PackageTransferWatcherStaticsForChunkSpecifiersT<PackageTransferWatcherStaticsForChunkSpecifiers, implementation::PackageTransferWatcherStaticsForChunkSpecifiers>
    {
    };
}
