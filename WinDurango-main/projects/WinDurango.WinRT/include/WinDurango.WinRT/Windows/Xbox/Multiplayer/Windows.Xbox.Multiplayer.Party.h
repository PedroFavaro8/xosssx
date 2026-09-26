#pragma once
#include "Windows.Xbox.Multiplayer.GamePlayer.g.h"
#include "Windows.Xbox.Multiplayer.GamePlayerDeviceGroup.g.h"
#include "Windows.Xbox.Multiplayer.GameSessionReadyEventArgs.g.h"
#include "Windows.Xbox.Multiplayer.PartyStateChangedEventArgs.g.h"
#include "Windows.Xbox.Multiplayer.PartyRosterChangedEventArgs.g.h"
#include "Windows.Xbox.Multiplayer.MatchStatusChangedEventArgs.g.h"
#include "Windows.Xbox.Multiplayer.GamePlayersChangedEventArgs.g.h"
#include "Windows.Xbox.Multiplayer.UserPartyAssociation.g.h"
#include "Windows.Xbox.Multiplayer.Party.g.h"

namespace winrt::Windows::Xbox::Multiplayer::implementation
{
    struct GamePlayer : GamePlayerT<GamePlayer>
    {
        GamePlayer() = default;

        hstring XboxUserId();
        winrt::Windows::Foundation::DateTime LastInvitedTime();
        winrt::Windows::Foundation::DateTime PartyJoinTime();
    };

    struct GamePlayerDeviceGroup : GamePlayerDeviceGroupT<GamePlayerDeviceGroup>
    {
        GamePlayerDeviceGroup() = default;

        winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Multiplayer::GamePlayer> Players();
    };

    struct GameSessionReadyEventArgs : GameSessionReadyEventArgsT<GameSessionReadyEventArgs>
    {
        GameSessionReadyEventArgs() = default;
        GameSessionReadyEventArgs(winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference gameSession) : gameSession(gameSession) {}

        winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference GameSession();
    private:
        winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference gameSession;
    };

    struct PartyStateChangedEventArgs : PartyStateChangedEventArgsT<PartyStateChangedEventArgs>
    {
        PartyStateChangedEventArgs() = default;
        PartyStateChangedEventArgs(winrt::Windows::Xbox::Multiplayer::PartyView partyView) : partyView(partyView) {}

        winrt::Windows::Xbox::Multiplayer::PartyView PartyView();
    private:
        winrt::Windows::Xbox::Multiplayer::PartyView partyView;
    };

    struct PartyRosterChangedEventArgs : PartyRosterChangedEventArgsT<PartyRosterChangedEventArgs>
    {
        PartyRosterChangedEventArgs() = default;
        PartyRosterChangedEventArgs(winrt::Windows::Foundation::Collections::IVectorView<hstring> addedMembers, 
            winrt::Windows::Foundation::Collections::IVectorView<hstring> addedReservedMembers, 
            winrt::Windows::Foundation::Collections::IVectorView<hstring> removedMembers, 
            winrt::Windows::Foundation::Collections::IVectorView<hstring> removedReservedMembers, 
            winrt::Windows::Xbox::Multiplayer::PartyView partyView) : addedReservedMembers(addedReservedMembers), addedMembers(addedMembers),
            removedMembers(removedMembers), removedReservedMembers(removedReservedMembers), partyView(partyView) {}

        winrt::Windows::Foundation::Collections::IVectorView<hstring> AddedMembers();
        winrt::Windows::Foundation::Collections::IVectorView<hstring> AddedReservedMembers();
        winrt::Windows::Foundation::Collections::IVectorView<hstring> RemovedMembers();
        winrt::Windows::Foundation::Collections::IVectorView<hstring> RemovedReservedMembers();
        winrt::Windows::Xbox::Multiplayer::PartyView PartyView();
    private:
        winrt::Windows::Foundation::Collections::IVectorView<hstring> addedMembers;
        winrt::Windows::Foundation::Collections::IVectorView<hstring> addedReservedMembers;
        winrt::Windows::Foundation::Collections::IVectorView<hstring> removedMembers;
        winrt::Windows::Foundation::Collections::IVectorView<hstring> removedReservedMembers;
        winrt::Windows::Xbox::Multiplayer::PartyView partyView;
    };

    struct MatchStatusChangedEventArgs : MatchStatusChangedEventArgsT<MatchStatusChangedEventArgs>
    {
        MatchStatusChangedEventArgs() = default;
        MatchStatusChangedEventArgs(winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference matchSession, 
            winrt::Windows::Xbox::Multiplayer::MatchStatus matchStatus) : matchSession(matchSession), matchStatus(matchStatus) {}

        winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference MatchSession();
        winrt::Windows::Xbox::Multiplayer::MatchStatus MatchStatus();
    private:
        winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference matchSession;
        winrt::Windows::Xbox::Multiplayer::MatchStatus matchStatus;
    };

    struct GamePlayersChangedEventArgs : GamePlayersChangedEventArgsT<GamePlayersChangedEventArgs>
    {
        GamePlayersChangedEventArgs() = default;
        GamePlayersChangedEventArgs(winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference gameSession, 
            winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Multiplayer::GamePlayer> availablePlayers, 
            winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Multiplayer::GamePlayerDeviceGroup> availablePlayersGroupedByDevice) :
            gameSession(gameSession), availablePlayers(availablePlayers), availablePlayersGroupedByDevice(availablePlayersGroupedByDevice) {}

        winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference GameSession();
        winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Multiplayer::GamePlayer> AvailablePlayers();
        winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Multiplayer::GamePlayerDeviceGroup> AvailablePlayersGroupedByDevice();
    private:
        winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference gameSession;
        winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Multiplayer::GamePlayer> availablePlayers;
        winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Multiplayer::GamePlayerDeviceGroup> availablePlayersGroupedByDevice;
    };

    struct UserPartyAssociation : UserPartyAssociationT<UserPartyAssociation>
    {
        UserPartyAssociation() = default;
        UserPartyAssociation(winrt::Windows::Foundation::Collections::IVectorView<hstring> queriedXboxUserIds, hstring partyId) : queriedXboxUserIds(queriedXboxUserIds), partyId(partyId) {}

        winrt::Windows::Foundation::Collections::IVectorView<hstring> QueriedXboxUserIds();
        hstring PartyId();
    private:
        winrt::Windows::Foundation::Collections::IVectorView<hstring> queriedXboxUserIds;
        hstring partyId;
    };

    struct Party
    {
        Party() = default;

        static winrt::Windows::Foundation::IAsyncAction RegisterGameSessionAsync(winrt::Windows::Xbox::System::User actingUser, winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference sessionReference);
        static winrt::Windows::Foundation::IAsyncAction RegisterMatchSessionAsync(winrt::Windows::Xbox::System::User actingUser, winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference sessionReference);
        static winrt::Windows::Foundation::IAsyncAction InviteToPartyAsync(winrt::Windows::Xbox::System::User actingUser, winrt::Windows::Foundation::Collections::IVectorView<hstring> usersToInvite);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::Multiplayer::PartyView> GetPartyViewAsync();
        static winrt::Windows::Foundation::IAsyncAction AddLocalUsersAsync(winrt::Windows::Xbox::System::User actingUser, winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::System::User> localUsersToAdd);
        static winrt::Windows::Foundation::IAsyncAction PullInactivePlayersAsync(winrt::Windows::Xbox::System::User actingUser, winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference sessionReference);
        static winrt::Windows::Foundation::IAsyncAction PullReservedPlayersAsync(winrt::Windows::Xbox::System::User actingUser, winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference sessionReference);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Multiplayer::GamePlayer>> GetAvailableGamePlayersAsync(winrt::Windows::Xbox::System::User actingUser);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Multiplayer::GamePlayerDeviceGroup>> GetAvailableGamePlayersGroupedByDeviceAsync(winrt::Windows::Xbox::System::User actingUser);
        static winrt::Windows::Foundation::IAsyncAction SwitchPartyTitleAsync(winrt::Windows::Xbox::System::User actingUser);
        static winrt::event_token GameSessionReady(winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::Multiplayer::GameSessionReadyEventArgs> const& handler);
        static void GameSessionReady(winrt::event_token const& token) noexcept;
        static winrt::event_token PartyStateChanged(winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::Multiplayer::PartyStateChangedEventArgs> const& handler);
        static void PartyStateChanged(winrt::event_token const& token) noexcept;
        static winrt::event_token PartyRosterChanged(winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::Multiplayer::PartyRosterChangedEventArgs> const& handler);
        static void PartyRosterChanged(winrt::event_token const& token) noexcept;
        static winrt::event_token MatchStatusChanged(winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::Multiplayer::MatchStatusChangedEventArgs> const& handler);
        static void MatchStatusChanged(winrt::event_token const& token) noexcept;
        static winrt::event_token GamePlayersChanged(winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::Multiplayer::GamePlayersChangedEventArgs> const& handler);
        static void GamePlayersChanged(winrt::event_token const& token) noexcept;
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::Multiplayer::PartyView> GetPartyViewAsyncEx(winrt::Windows::Xbox::Multiplayer::PartyFlags flags);
        static winrt::Windows::Foundation::IAsyncAction RemoveLocalUsersAsync(winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::System::User> localUsersToRemove);
        static hstring PartyId();
        static winrt::Windows::Foundation::IAsyncAction DisassociateGameSessionAsync(winrt::Windows::Xbox::System::User actingUser, winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference sessionReferenceToDisassociate);
        static winrt::Windows::Foundation::IAsyncAction RegisterGameSessionCompareAsync(winrt::Windows::Xbox::System::User actingUser, winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference sessionReference, winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference sessionReferenceComparand);
        static winrt::Windows::Foundation::IAsyncAction RegisterMatchSessionCompareAsync(winrt::Windows::Xbox::System::User actingUser, winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference sessionReference, winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference sessionReferenceComparand);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Multiplayer::UserPartyAssociation>> GetUserPartyAssociationsAsync(winrt::Windows::Xbox::System::User actingUser, winrt::Windows::Foundation::Collections::IVectorView<hstring> targetXboxUserIds);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::Multiplayer::PartyView> GetPartyViewByPartyIdAsync(winrt::Windows::Xbox::System::User actingUser, hstring partyId);
        static winrt::Windows::Foundation::IAsyncAction JoinPartyByIdAsync(winrt::Windows::Xbox::System::User actingUser, hstring partyId);
        static winrt::Windows::Xbox::Multiplayer::SessionJoinability Joinability();
        static void Joinability(winrt::Windows::Xbox::Multiplayer::SessionJoinability const& value);
    private:
        static winrt::event<winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::Multiplayer::GameSessionReadyEventArgs>> e_GameSessionReady;
        static winrt::event<winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::Multiplayer::PartyStateChangedEventArgs>> e_PartyStateChanged;
        static winrt::event<winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::Multiplayer::PartyRosterChangedEventArgs>> e_PartyRosterChanged;
        static winrt::event<winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::Multiplayer::MatchStatusChangedEventArgs>> e_MatchStatusChanged;
        static winrt::event<winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::Multiplayer::GamePlayersChangedEventArgs>> e_GamePlayersChanged;
        static winrt::Windows::Xbox::Multiplayer::SessionJoinability sessionJoinability;
    };
}
namespace winrt::Windows::Xbox::Multiplayer::factory_implementation
{
    struct Party : PartyT<Party, implementation::Party>
    {
    };
}
