#pragma once
#include "Windows.Xbox.Storage.ContainerInfoQueryResult.g.h"

namespace wd::WinRT
{
    class ConnectedStorage;
}

namespace winrt::Windows::Xbox::Storage::implementation
{
    struct ContainerInfoQueryResult : ContainerInfoQueryResultT<ContainerInfoQueryResult>
    {
        ContainerInfoQueryResult() = default;
        ContainerInfoQueryResult(hstring containerNamePrefix, wd::WinRT::ConnectedStorage *connectedStorage)
        {
            this->containerNamePrefix = containerNamePrefix;
            m_connectedStorage = connectedStorage;
        }

        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Storage::ContainerInfo>> GetContainerInfoAsync(uint32_t unk, uint32_t unka);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Storage::ContainerInfo>> GetContainerInfoAsync();
        winrt::Windows::Foundation::IAsyncOperation<uint32_t> GetItemCountAsync();
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Storage::ContainerInfo2>> GetContainerInfo2Async(uint32_t unk, uint32_t unka);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Storage::ContainerInfo2>> GetContainerInfo2Async();

    private:
        hstring containerNamePrefix;
        wd::WinRT::ConnectedStorage *m_connectedStorage = nullptr;
    };
}
