#pragma once
#include "Windows.Xbox.Management.Deployment.PackageTransferManager.g.h"

namespace winrt::Windows::Xbox::Management::Deployment::implementation
{
    struct PackageTransferManager : PackageTransferManagerT<PackageTransferManager>
    {
        PackageTransferManager() = default;

        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::Management::Deployment::CheckForUpdateResult> CheckForUpdateAsync(winrt::Windows::Xbox::Management::Deployment::DownloadableContentPackage unk);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::Management::Deployment::RequestUpdatePackageResult> RequestUpdatePackageAsync(winrt::Windows::Xbox::Management::Deployment::DownloadableContentPackage unk);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::Management::Deployment::RequestUpdatePackageResult> RequestUpdateCurrentPackageAsync();
        static winrt::Windows::Xbox::Management::Deployment::PackageTransferManager Current();
        static winrt::Windows::Xbox::Management::Deployment::PackageTransferManager Create(winrt::Windows::ApplicationModel::Package const& unk);
        winrt::Windows::Xbox::Management::Deployment::ChunkSpecifiers AvailableChunkSpecifiers();
        winrt::Windows::Xbox::Management::Deployment::InstallationState GetInstallationState(winrt::Windows::Foundation::Collections::IIterable<uint32_t> const& unk);
        winrt::Windows::Xbox::Management::Deployment::InstallationState GetInstallationState(winrt::Windows::Xbox::Management::Deployment::ChunkSpecifiers const& unk);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher> AddChunkSpecifiersAsync(winrt::Windows::Xbox::Management::Deployment::ChunkSpecifiers unk);
        winrt::Windows::Foundation::IAsyncAction RemoveChunkSpecifiersAsync(winrt::Windows::Xbox::Management::Deployment::ChunkSpecifiers unk);
        winrt::Windows::Xbox::Management::Deployment::PackageTransferType TransferType();
        void UpdateInstallOrder(winrt::Windows::Foundation::Collections::IIterable<uint32_t> const& unk, winrt::Windows::Xbox::Management::Deployment::UpdateInstallOrderBehavior const& unka);
        bool IsChunkInstalled(uint32_t unk);
        bool AreChunksInstalled(winrt::Windows::Foundation::Collections::IIterable<uint32_t> const& unk);
        uint32_t FindChunkFromFile(hstring const& unk);
        winrt::Windows::Xbox::Management::Deployment::PackageTransferStatus TransferStatus();
    };
}
namespace winrt::Windows::Xbox::Management::Deployment::factory_implementation
{
    struct PackageTransferManager : PackageTransferManagerT<PackageTransferManager, implementation::PackageTransferManager>
    {
    };
}
