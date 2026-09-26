#pragma once
#include <winrt/Windows.Foundation.Collections.h>
#include "Windows.Xbox.Storage.ConnectedStorageSpace.g.h"
#include "Windows.Xbox.Storage.ConnectedStorage.h"
#include "Windows.Xbox.Storage.ConnectedStorageContainer.h"

namespace winrt::Windows::Xbox::Storage::implementation
{
    struct ConnectedStorageSpace : ConnectedStorageSpaceT<ConnectedStorageSpace>
    {
        ConnectedStorageSpace() = default;
        ConnectedStorageSpace(wd::WinRT::ConnectedStorage *connectedStorage)
        {
            m_connectedStorage = connectedStorage;
        }

        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::Storage::ConnectedStorageSpace> GetForUserAsync(winrt::Windows::Xbox::System::User unk);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::Storage::ConnectedStorageSpace> GetForUserAsync(winrt::Windows::Xbox::System::User unk, hstring unka);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::Storage::ConnectedStorageSpace> GetForMachineAsync();
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::Storage::ConnectedStorageSpace> GetForMachineAsync(hstring unk);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::Storage::ConnectedStorageSpace> GetSyncOnDemandForUserAsync(winrt::Windows::Xbox::System::User unk);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::Storage::ConnectedStorageSpace> GetSyncOnDemandForUserAsync(winrt::Windows::Xbox::System::User unk, hstring unka);
        winrt::Windows::Xbox::System::User User();
        hstring ServiceConfigurationId();
        bool IsReadOnly();
        winrt::Windows::Xbox::Storage::ConnectedStorageContainer CreateContainer(hstring const& containerName);
        winrt::Windows::Foundation::IAsyncAction DeleteContainerAsync(hstring containerName);
        winrt::Windows::Xbox::Storage::ContainerInfoQueryResult CreateContainerInfoQuery(hstring const& unk);
        winrt::Windows::Foundation::IAsyncOperation<int32_t> GetRemainingBytesInQuotaAsync();
        winrt::Windows::Foundation::IAsyncOperation<int64_t> GetRemainingBytesInQuota64Async();
        inline static winrt::Windows::Xbox::Storage::ConnectedStorageSpace userStorageSpace = {nullptr};
        inline static winrt::Windows::Xbox::Storage::ConnectedStorageSpace machineStorageSpace = {nullptr};
        inline static winrt::Windows::Xbox::Storage::ConnectedStorageContainer staticContainer = {nullptr};
    private:
        wd::WinRT::ConnectedStorage * m_connectedStorage;
        inline static winrt::Windows::Foundation::Collections::IMap<hstring, winrt::Windows::Xbox::Storage::ConnectedStorageContainer> containers{};
    };
}
namespace winrt::Windows::Xbox::Storage::factory_implementation
{
    struct ConnectedStorageSpace : ConnectedStorageSpaceT<ConnectedStorageSpace, implementation::ConnectedStorageSpace>
    {
    };
}
