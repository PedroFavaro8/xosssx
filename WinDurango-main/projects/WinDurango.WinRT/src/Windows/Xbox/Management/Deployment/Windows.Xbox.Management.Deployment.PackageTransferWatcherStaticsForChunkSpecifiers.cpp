#include "Windows.Xbox.Management.Deployment.PackageTransferWatcherStaticsForChunkSpecifiers.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::Management::Deployment::implementation
{
    winrt::Windows::Xbox::Management::Deployment::PackageTransferWatcher PackageTransferWatcherStaticsForChunkSpecifiers::CreateForChunkSpecifiers(winrt::Windows::ApplicationModel::Package const& unk, winrt::Windows::Xbox::Management::Deployment::ChunkSpecifiers const& unka)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Management::Deployment", "Unimplemented: CreateForChunkSpecifiers");
        throw hresult_not_implemented();
    }
}
