#pragma once
#include <winrt/Windows.Foundation.Collections.h>
#include "Windows.Xbox.Networking.SecureDeviceAssociation.g.h"

namespace winrt::Windows::Xbox::Networking::implementation
{
    struct SecureDeviceAssociation : SecureDeviceAssociationT<SecureDeviceAssociation>
    {
        SecureDeviceAssociation() = default;

        static winrt::Windows::Xbox::Networking::SecureDeviceAssociation GetAssociationBySocketAddressBytes(array_view<uint8_t const> remoteSocketAddressBytes, array_view<uint8_t const> localSocketAddressBytes);
        static winrt::Windows::Xbox::Networking::SecureDeviceAssociation GetAssociationByHostNamesAndPorts(winrt::Windows::Networking::HostName const& remoteHostName, hstring const& remotePort, winrt::Windows::Networking::HostName const& localHostName, hstring const& localPort);
        winrt::event_token StateChanged(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Networking::SecureDeviceAssociation, winrt::Windows::Xbox::Networking::SecureDeviceAssociationStateChangedEventArgs> const& handler);
        void StateChanged(winrt::event_token const& token) noexcept;
        winrt::Windows::Foundation::IAsyncAction DestroyAsync();
        com_array<uint8_t> GetRemoteSocketAddressBytes();
        com_array<uint8_t> GetLocalSocketAddressBytes();
        winrt::Windows::Xbox::Networking::SecureDeviceAssociationState State();
        winrt::Windows::Xbox::Networking::SecureDeviceAssociationTemplate Template();
        winrt::Windows::Xbox::Networking::SecureDeviceAddress RemoteSecureDeviceAddress();
        winrt::Windows::Networking::HostName RemoteHostName();
        hstring RemotePort();
        winrt::Windows::Networking::HostName LocalHostName();
        hstring LocalPort();
    private:
        winrt::event<winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Networking::SecureDeviceAssociation, winrt::Windows::Xbox::Networking::SecureDeviceAssociationStateChangedEventArgs>> e_StateChanged;
    };
}
namespace winrt::Windows::Xbox::Networking::factory_implementation
{
    struct SecureDeviceAssociation : SecureDeviceAssociationT<SecureDeviceAssociation, implementation::SecureDeviceAssociation>
    {
    };
}
