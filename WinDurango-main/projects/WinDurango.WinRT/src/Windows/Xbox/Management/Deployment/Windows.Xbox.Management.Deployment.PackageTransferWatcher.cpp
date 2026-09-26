#include "Windows.Xbox.Management.Deployment.PackageTransferWatcher.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::Management::Deployment::implementation
{
    uint32_t ProgressChangedEventArgs::PercentComplete()
    {
        return percent;
    }
    void TransferStatusChangedEventArgs::UnknownOne()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Management::Deployment", "Unimplemented: UnknownOne");
        throw hresult_not_implemented();
    }
    void TransferStatusChangedEventArgs::UnknownTwo()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Management::Deployment", "Unimplemented: UnknownTwo");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher PackageTransferWatcher::Create(winrt::Windows::ApplicationModel::Package const& unk, winrt::Windows::Foundation::Collections::IIterable<uint32_t> const& unka)
    {
        return winrt::make<PackageTransferWatcher>();
    }
    winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher PackageTransferWatcher::Create(winrt::Windows::ApplicationModel::Package const& unk)
    {
        return winrt::make<PackageTransferWatcher>();
    }
    winrt::Windows::Xbox::Management::Deployment::PackageTransferStatus PackageTransferWatcher::TransferStatus()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Management::Deployment", "Unimplemented: TransferStatus");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::Management::Deployment::PackageTransferType PackageTransferWatcher::TransferType()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Management::Deployment", "Unimplemented: TransferType");
        throw hresult_not_implemented();
    }
    winrt::event_token PackageTransferWatcher::TransferStatusChanged(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher, winrt::Windows::Xbox::Management::Deployment::TransferStatusChangedEventArgs> const& handler)
    {
        return e_TransferStatusChanged.add(handler);
    }
    void PackageTransferWatcher::TransferStatusChanged(winrt::event_token const& token) noexcept
    {
        e_TransferStatusChanged.remove(token);
    }
    winrt::Windows::Foundation::Collections::IVectorView<uint32_t> PackageTransferWatcher::ChunkIds()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Management::Deployment", "Unimplemented: ChunkIds");
        throw hresult_not_implemented();
    }
    winrt::event_token PackageTransferWatcher::ChunkCompleted(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher, winrt::Windows::Xbox::Management::Deployment::ChunkCompletedEventArgs> const& handler)
    {
        return e_ChunkCompleted.add(handler);
    }
    void PackageTransferWatcher::ChunkCompleted(winrt::event_token const& token) noexcept
    {
        e_ChunkCompleted.remove(token);
    }
    winrt::event_token PackageTransferWatcher::ProgressChanged(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher, winrt::Windows::Xbox::Management::Deployment::ProgressChangedEventArgs> const& handler)
    {
        return e_ProgressChanged.add(handler);
    }
    void PackageTransferWatcher::ProgressChanged(winrt::event_token const& token) noexcept
    {
        e_ProgressChanged.remove(token);
    }
    winrt::event_token PackageTransferWatcher::TransferCompleted(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher, winrt::Windows::Xbox::Management::Deployment::TransferCompletedEventArgs> const& handler)
    {
        return e_TransferCompleted.add(handler);
    }
    void PackageTransferWatcher::TransferCompleted(winrt::event_token const& token) noexcept
    {
        e_TransferCompleted.remove(token);
    }
}
