#pragma once
#include "Windows.Xbox.Multiplayer.PartyMember.g.h"
#include "Windows.Xbox.Multiplayer.PartyMemberDeviceGroup.g.h"
#include "Windows.Xbox.Multiplayer.PartyView.g.h"

namespace winrt::Windows::Xbox::Multiplayer::implementation
{
    struct PartyMember : PartyMemberT<PartyMember>
    {
        PartyMember() = default;

        hstring XboxUserId();
        bool IsLocal();
        winrt::Windows::Foundation::DateTime JoinTime();
    };

    struct PartyMemberDeviceGroup : PartyMemberDeviceGroupT<PartyMemberDeviceGroup>
    {
        PartyMemberDeviceGroup() = default;

        winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Multiplayer::PartyMember> Members();
    };

    struct PartyView : PartyViewT<PartyView>
    {
        PartyView() = default;

        static winrt::Windows::Xbox::Multiplayer::SuppressGameSessionReadyToastMode SuppressGameSessionReadyToastMode();
        static void SuppressGameSessionReadyToastMode(winrt::Windows::Xbox::Multiplayer::SuppressGameSessionReadyToastMode const& value);
        winrt::Windows::Foundation::Collections::IVectorView<hstring> ReservedMembers();
        winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Multiplayer::PartyMember> Members();
        winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Multiplayer::PartyMemberDeviceGroup> MembersGroupedByDevice();
        winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference MatchSession();
        winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference GameSession();
        bool IsPartyInAnotherTitle();
    private:
        static winrt::Windows::Xbox::Multiplayer::SuppressGameSessionReadyToastMode suppressGameSessionReadyToast;
    };
}
namespace winrt::Windows::Xbox::Multiplayer::factory_implementation
{
    struct PartyView : PartyViewT<PartyView, implementation::PartyView>
    {
    };
}
