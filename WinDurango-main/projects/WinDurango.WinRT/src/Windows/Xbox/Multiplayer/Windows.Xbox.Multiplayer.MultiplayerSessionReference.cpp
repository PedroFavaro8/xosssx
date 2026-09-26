#include "Windows.Xbox.Multiplayer.MultiplayerSessionReference.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::Multiplayer::implementation
{
    winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference MultiplayerSessionReferenceFactory::CreateMultiplayerSessionReference(hstring const& unk, hstring const& unka, hstring const& unkb)
    {
        return winrt::make<implementation::MultiplayerSessionReference>();
    }
    hstring MultiplayerSessionReference::SessionName()
    {
        return L"Session";
    }
    hstring MultiplayerSessionReference::ServiceConfigurationId()
    {
        return L"1";
    }
    hstring MultiplayerSessionReference::SessionTemplateName()
    {
        return L"SessionTemplateName";
    }
}
