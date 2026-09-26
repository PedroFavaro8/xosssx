#include "Windows.Xbox.Networking.SecureDeviceAssociation.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::Networking::implementation
{
    winrt::Windows::Xbox::Networking::SecureDeviceAssociation SecureDeviceAssociation::GetAssociationBySocketAddressBytes(array_view<uint8_t const> remoteSocketAddressBytes, array_view<uint8_t const> localSocketAddressBytes)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: GetAssociationBySocketAddressBytes");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::Networking::SecureDeviceAssociation SecureDeviceAssociation::GetAssociationByHostNamesAndPorts(winrt::Windows::Networking::HostName const& remoteHostName, hstring const& remotePort, winrt::Windows::Networking::HostName const& localHostName, hstring const& localPort)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: GetAssociationByHostNamesAndPorts");
        throw hresult_not_implemented();
    }
    winrt::event_token SecureDeviceAssociation::StateChanged(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Networking::SecureDeviceAssociation, winrt::Windows::Xbox::Networking::SecureDeviceAssociationStateChangedEventArgs> const& handler)
    {
        return e_StateChanged.add(handler);
    }
    void SecureDeviceAssociation::StateChanged(winrt::event_token const& token) noexcept
    {
        e_StateChanged.remove(token);
    }
    winrt::Windows::Foundation::IAsyncAction SecureDeviceAssociation::DestroyAsync()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: DestroyAsync");
        throw hresult_not_implemented();
    }
    com_array<uint8_t> SecureDeviceAssociation::GetRemoteSocketAddressBytes()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: GetRemoteSocketAddressBytes");
        throw hresult_not_implemented();
    }
    com_array<uint8_t> SecureDeviceAssociation::GetLocalSocketAddressBytes()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: GetLocalSocketAddressBytes");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::Networking::SecureDeviceAssociationState SecureDeviceAssociation::State()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: State");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::Networking::SecureDeviceAssociationTemplate SecureDeviceAssociation::Template()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: Template");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::Networking::SecureDeviceAddress SecureDeviceAssociation::RemoteSecureDeviceAddress()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: RemoteSecureDeviceAddress");
        throw hresult_not_implemented();
    }
    winrt::Windows::Networking::HostName SecureDeviceAssociation::RemoteHostName()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: RemoteHostName");
        throw hresult_not_implemented();
    }
    hstring SecureDeviceAssociation::RemotePort()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: RemotePort");
        throw hresult_not_implemented();
    }
    winrt::Windows::Networking::HostName SecureDeviceAssociation::LocalHostName()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: LocalHostName");
        throw hresult_not_implemented();
    }
    hstring SecureDeviceAssociation::LocalPort()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: LocalPort");
        throw hresult_not_implemented();
    }
}
