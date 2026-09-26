#pragma once
#include <winrt/Windows.Foundation.Collections.h>
#include "Windows.Xbox.Networking.SecureDeviceAddressFactory.g.h"
#include "Windows.Xbox.Networking.SecureDeviceAddress.g.h"

namespace winrt::Windows::Xbox::Networking::implementation
{
    struct SecureDeviceAddressFactory : SecureDeviceAddressFactoryT<SecureDeviceAddressFactory>
    {
        SecureDeviceAddressFactory() = default;

        winrt::Windows::Xbox::Networking::SecureDeviceAddress CreateAddressFromBuffer(winrt::Windows::Storage::Streams::IBuffer const& buffer);
    };
    struct SecureDeviceAddress : SecureDeviceAddressT<SecureDeviceAddress>
    {
        SecureDeviceAddress() = default;

        static uint32_t CompareBuffers(winrt::Windows::Storage::Streams::IBuffer const& buffer1, winrt::Windows::Storage::Streams::IBuffer const& buffer2);
        static uint32_t CompareBytes(array_view<uint8_t const> bytes1, array_view<uint8_t const> bytes2);
        static winrt::Windows::Xbox::Networking::SecureDeviceAddress FromBytes(array_view<uint8_t const> bytes);
        static winrt::Windows::Xbox::Networking::SecureDeviceAddress GetLocal();
        static winrt::Windows::Xbox::Networking::SecureDeviceAddress CreateDedicatedServerAddress(hstring const& hostnameOrAddress);
        static winrt::Windows::Xbox::Networking::SecureDeviceAddress FromBase64String(hstring const& base64String);
        winrt::event_token BufferChanged(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Networking::SecureDeviceAddress, winrt::Windows::Foundation::IInspectable> const& handler);
        void BufferChanged(winrt::event_token const& token) noexcept;
        winrt::Windows::Storage::Streams::IBuffer GetBuffer();
        int32_t Compare(winrt::Windows::Xbox::Networking::SecureDeviceAddress const& secureDeviceAddress);
        hstring GetBase64String();
        bool IsLocal();
        winrt::Windows::Xbox::Networking::NetworkAccessType NetworkAccessType();
    private:
        winrt::event<winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Networking::SecureDeviceAddress, winrt::Windows::Foundation::IInspectable>> e_BufferChanged;
    };
}
namespace winrt::Windows::Xbox::Networking::factory_implementation
{
    struct SecureDeviceAddress : SecureDeviceAddressT<SecureDeviceAddress, implementation::SecureDeviceAddress>
    {
    };
}
