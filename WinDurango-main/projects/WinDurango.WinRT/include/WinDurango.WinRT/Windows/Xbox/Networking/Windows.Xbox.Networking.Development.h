#pragma once
#include "Windows.Xbox.Networking.SecureDeviceSocketDescription.g.h"
#include "Windows.Xbox.Networking.Development.g.h"

namespace winrt::Windows::Xbox::Networking::implementation
{
    struct SecureDeviceSocketDescription : SecureDeviceSocketDescriptionT<SecureDeviceSocketDescription>
    {
        SecureDeviceSocketDescription() = default;

        hstring Name();
        winrt::Windows::Xbox::Networking::SecureIpProtocol IpProtocol();
        uint16_t BoundPortRangeLower();
        uint16_t BoundPortRangeUpper();
        winrt::Windows::Xbox::Networking::SecureDeviceSocketUsage AllowedUsages();
    };
    struct Development
    {
        Development() = default;

        static winrt::Windows::Xbox::Networking::SecureDeviceAddress CreateSecureDeviceAddressFromHostNames(winrt::Windows::Xbox::Networking::SecureDeviceId const& secureDeviceId, winrt::Windows::Foundation::Collections::IIterable<winrt::Windows::Networking::HostName> const& hostNames);
        static winrt::Windows::Xbox::Networking::SecureDeviceSocketDescription CreateSecureDeviceSocketDescription(hstring const& name, winrt::Windows::Xbox::Networking::SecureIpProtocol const& secureIpProtocol, uint16_t boundPortRangeLower, uint16_t boundPortRangeUpper, winrt::Windows::Xbox::Networking::SecureDeviceSocketUsage const& allowedUsages);
        static winrt::Windows::Xbox::Networking::SecureDeviceAssociationTemplate CreateSecureDeviceAssociationTemplate(hstring const& name, winrt::Windows::Xbox::Networking::SecureDeviceSocketDescription const& initiatorSecureDeviceSocketDescription, winrt::Windows::Xbox::Networking::SecureDeviceSocketDescription const& acceptorSecureDeviceSocketDescription, winrt::Windows::Xbox::Networking::SecureDeviceAssociationUsage const& allowedUsages, hstring const& relyingParty, winrt::Windows::Foundation::Collections::IIterable<winrt::Windows::Xbox::Networking::ProtocolParserDescription> const& protocolParserDescriptions, winrt::Windows::Foundation::Collections::IIterable<winrt::Windows::Xbox::Networking::QualityOfServiceMetric> const& qualityOfServiceMetricPathPriorities, winrt::Windows::Xbox::Networking::MultiplayerSessionRequirement const& multiplayerSessionRequirement);
    };
}
namespace winrt::Windows::Xbox::Networking::factory_implementation
{
    struct Development : DevelopmentT<Development, implementation::Development>
    {
    };
}
