#pragma once
#include "Windows.Xbox.Multiplayer.MultiplayerSessionReferenceFactory.g.h"
#include "Windows.Xbox.Multiplayer.MultiplayerSessionReference.g.h"

namespace winrt::Windows::Xbox::Multiplayer::implementation
{
    struct MultiplayerSessionReferenceFactory : MultiplayerSessionReferenceFactoryT<MultiplayerSessionReferenceFactory>
    {
        MultiplayerSessionReferenceFactory() = default;

        winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference CreateMultiplayerSessionReference(hstring const& unk, hstring const& unka, hstring const& unkb);
    };

    struct MultiplayerSessionReference : MultiplayerSessionReferenceT<MultiplayerSessionReference>
    {
        MultiplayerSessionReference() = default;

        hstring SessionName();
        hstring ServiceConfigurationId();
        hstring SessionTemplateName();
    };
}
namespace winrt::Windows::Xbox::Multiplayer::factory_implementation
{
    struct MultiplayerSessionReference : MultiplayerSessionReferenceT<MultiplayerSessionReference, implementation::MultiplayerSessionReference>
    {
    };
}
