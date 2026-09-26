#pragma once
#include "Windows.Xbox.UI.FirmwareUpdateResult.g.h"
#include "Windows.Xbox.UI.NetworkTroubleshooterResult.g.h"
#include "Windows.Xbox.UI.ShareContentResult.g.h"
#include "Windows.Xbox.UI.SignUpResult.g.h"

namespace winrt::Windows::Xbox::UI::implementation
{
    struct FirmwareUpdateResult : FirmwareUpdateResultT<FirmwareUpdateResult>
    {
        FirmwareUpdateResult() = default;

        winrt::Windows::Xbox::UI::FirmwareUpdateStatus Status();
        uint64_t ControllerIdUpdated();
    };

    struct NetworkTroubleshooterResult : NetworkTroubleshooterResultT<NetworkTroubleshooterResult>
    {
        NetworkTroubleshooterResult() = default;

        bool ConnectedToLive();
        winrt::Windows::Foundation::Collections::IPropertySet AllResults();
    };

    struct ShareContentResult : ShareContentResultT<ShareContentResult>
    {
        ShareContentResult() = default;

        winrt::Windows::Xbox::UI::ShareContentDestination Destination();
    };

    struct SignUpResult : SignUpResultT<SignUpResult>
    {
        SignUpResult() = default;

        winrt::Windows::Xbox::System::User User();
        winrt::Windows::Foundation::Collections::IPropertySet Properties();
        winrt::Windows::Xbox::System::User SystemUser();
    };
}
