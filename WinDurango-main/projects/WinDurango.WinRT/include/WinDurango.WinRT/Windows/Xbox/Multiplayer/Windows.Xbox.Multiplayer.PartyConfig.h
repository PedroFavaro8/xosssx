#pragma once
#include "Windows.Xbox.Multiplayer.PartyChatMember.g.h"
#include "Windows.Xbox.Multiplayer.PartyChatView.g.h"
#include "Windows.Xbox.Multiplayer.PartyConfig.g.h"

namespace winrt::Windows::Xbox::Multiplayer::implementation
{
    struct PartyChatMember : PartyChatMemberT<PartyChatMember>
    {
        PartyChatMember() = default;
        PartyChatMember(hstring userId, uint8_t isLocal) : userId(userId), isLocal(isLocal) {}

        hstring XboxUserId();
        uint8_t IsLocal();
    private:
        hstring userId;
        uint8_t isLocal;
    };

    struct PartyChatView : PartyChatViewT<PartyChatView>
    {
        PartyChatView() = default;

        winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Multiplayer::PartyChatMember> Members();
    };

    struct PartyConfig
    {
        PartyConfig() = default;

        static bool SuppressGameSessionReadyToast();
        static void SuppressGameSessionReadyToast(bool value);
        static winrt::Windows::Xbox::Multiplayer::SuppressGameSessionReadyToastMode SuppressGameSessionReadyToastMode();
        static void SuppressGameSessionReadyToastMode(winrt::Windows::Xbox::Multiplayer::SuppressGameSessionReadyToastMode const& value);
    };
}
namespace winrt::Windows::Xbox::Multiplayer::factory_implementation
{
    struct PartyConfig : PartyConfigT<PartyConfig, implementation::PartyConfig>
    {
    };
}
