#pragma once
#include "Windows.Xbox.Storage.BlobInfoQueryResult.g.h"
#include "Windows.Xbox.Storage.ConnectedStorageContainer.g.h"
#include "Windows.Xbox.Storage.ConnectedStorage.h"

namespace wd::WinRT
{
    class ConnectedStorage;
}

namespace winrt::Windows::Xbox::Storage::implementation
{
    struct BlobInfoQueryResult : BlobInfoQueryResultT<BlobInfoQueryResult>
    {
        BlobInfoQueryResult() = default;
        BlobInfoQueryResult(hstring parent, hstring prefix, wd::WinRT::ConnectedStorage *connectedStorage)
        {
            this->parentName = parent;
            this->prefix = prefix;
            m_connectedStorage = connectedStorage;
        }

        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Storage::BlobInfo>> GetBlobInfoAsync(uint32_t unk, uint32_t unka);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Storage::BlobInfo>> GetBlobInfoAsync();
        winrt::Windows::Foundation::IAsyncOperation<uint32_t> GetItemCountAsync();

    private:
        hstring parentName;
        hstring prefix;
        wd::WinRT::ConnectedStorage *m_connectedStorage = nullptr;
    };

    struct ConnectedStorageContainer : ConnectedStorageContainerT<ConnectedStorageContainer>
    {
        ConnectedStorageContainer() = default;
        ConnectedStorageContainer(hstring name, wd::WinRT::ConnectedStorage *storage);

        hstring Name();
        winrt::Windows::Xbox::Storage::ConnectedStorageSpace OwningSpace();
        winrt::Windows::Foundation::IAsyncAction SubmitUpdatesAsync(winrt::Windows::Foundation::Collections::IMapView<hstring, winrt::Windows::Storage::Streams::IBuffer> unk, winrt::Windows::Foundation::Collections::IIterable<hstring> unka);
        winrt::Windows::Foundation::IAsyncAction ReadAsync(winrt::Windows::Foundation::Collections::IMapView<hstring, winrt::Windows::Storage::Streams::IBuffer> unk);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IMapView<hstring, winrt::Windows::Storage::Streams::IBuffer>> GetAsync(winrt::Windows::Foundation::Collections::IIterable<hstring> unk);
        winrt::Windows::Foundation::IAsyncAction SubmitPropertySetUpdatesAsync(winrt::Windows::Foundation::Collections::IPropertySet unk, winrt::Windows::Foundation::Collections::IIterable<hstring> unka);
        winrt::Windows::Foundation::IAsyncAction SubmitUpdatesAsync(winrt::Windows::Foundation::Collections::IMapView<hstring, winrt::Windows::Storage::Streams::IBuffer> unk, winrt::Windows::Foundation::Collections::IIterable<hstring> unka, hstring unkaa);
        winrt::Windows::Foundation::IAsyncAction SubmitPropertySetUpdatesAsync(winrt::Windows::Foundation::Collections::IPropertySet unk, winrt::Windows::Foundation::Collections::IIterable<hstring> unka, hstring unkaa);
        winrt::Windows::Xbox::Storage::BlobInfoQueryResult CreateBlobInfoQuery(hstring const& unk);
        wd::WinRT::ConnectedStorage *m_connectedStorage = nullptr;
        winrt::hstring m_storagePath;
        winrt::hstring containerName;
    };
}
