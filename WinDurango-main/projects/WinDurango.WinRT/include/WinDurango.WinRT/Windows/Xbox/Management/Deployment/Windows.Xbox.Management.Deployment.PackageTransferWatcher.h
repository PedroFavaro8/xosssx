#pragma once
#include "Windows.Xbox.Management.Deployment.PackageTransferWatcher.g.h"
#include "Windows.Xbox.Management.Deployment.ProgressChangedEventArgs.g.h"
#include "Windows.Xbox.Management.Deployment.TransferCompletedEventArgs.g.h"
#include "Windows.Xbox.Management.Deployment.TransferStatusChangedEventArgs.g.h"

namespace winrt::Windows::Xbox::Management::Deployment::implementation
{
    struct ProgressChangedEventArgs : ProgressChangedEventArgsT<ProgressChangedEventArgs>
    {
        ProgressChangedEventArgs() = default;
        ProgressChangedEventArgs(uint32_t percent) : percent(percent) {}

        uint32_t PercentComplete();
    private:
        uint32_t percent;
    };

    struct TransferCompletedEventArgs : TransferCompletedEventArgsT<TransferCompletedEventArgs>
    {
        TransferCompletedEventArgs() = default;

    };

    struct TransferStatusChangedEventArgs : TransferStatusChangedEventArgsT<TransferStatusChangedEventArgs>
    {
        TransferStatusChangedEventArgs() = default;

        void UnknownOne();
        void UnknownTwo();
    };

    struct PackageTransferWatcher : PackageTransferWatcherT<PackageTransferWatcher>
    {
        PackageTransferWatcher() = default;

        static winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher Create(winrt::Windows::ApplicationModel::Package const& unk, winrt::Windows::Foundation::Collections::IIterable<uint32_t> const& unka);
        static winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher Create(winrt::Windows::ApplicationModel::Package const& unk);
        winrt::Windows::Xbox::Management::Deployment::PackageTransferStatus TransferStatus();
        winrt::Windows::Xbox::Management::Deployment::PackageTransferType TransferType();
        winrt::event_token TransferStatusChanged(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher, winrt::Windows::Xbox::Management::Deployment::TransferStatusChangedEventArgs> const& handler);
        void TransferStatusChanged(winrt::event_token const& token) noexcept;
        winrt::Windows::Foundation::Collections::IVectorView<uint32_t> ChunkIds();
        winrt::event_token ChunkCompleted(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher, winrt::Windows::Xbox::Management::Deployment::ChunkCompletedEventArgs> const& handler);
        void ChunkCompleted(winrt::event_token const& token) noexcept;
        winrt::event_token ProgressChanged(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher, winrt::Windows::Xbox::Management::Deployment::ProgressChangedEventArgs> const& handler);
        void ProgressChanged(winrt::event_token const& token) noexcept;
        winrt::event_token TransferCompleted(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher, winrt::Windows::Xbox::Management::Deployment::TransferCompletedEventArgs> const& handler);
        void TransferCompleted(winrt::event_token const& token) noexcept;
    private:
        winrt::event<winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher, winrt::Windows::Xbox::Management::Deployment::TransferStatusChangedEventArgs>> e_TransferStatusChanged;
        winrt::event<winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher, winrt::Windows::Xbox::Management::Deployment::ChunkCompletedEventArgs>> e_ChunkCompleted;
        winrt::event<winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher, winrt::Windows::Xbox::Management::Deployment::ProgressChangedEventArgs>> e_ProgressChanged;
        winrt::event<winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher, winrt::Windows::Xbox::Management::Deployment::TransferCompletedEventArgs>> e_TransferCompleted;
    };
}
namespace winrt::Windows::Xbox::Management::Deployment::factory_implementation
{
    struct PackageTransferWatcher : PackageTransferWatcherT<PackageTransferWatcher, implementation::PackageTransferWatcher>
    {
    };
}
