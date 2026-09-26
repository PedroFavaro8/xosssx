#include "Windows.Xbox.Chat.ChatParticipant.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::Chat::implementation
{
    ChatParticipant::ChatParticipant(winrt::Windows::Xbox::System::User const& user)
    {

    }
    winrt::Windows::Xbox::System::User ChatParticipant::User()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Chat::ChatParticipant", "Unimplemented: User");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::Chat::ChatParticipantTypes ChatParticipant::ParticipantType()
    {
        return participantType;
    }
    void ChatParticipant::ParticipantType(winrt::Windows::Xbox::Chat::ChatParticipantTypes const& value)
    {
        participantType = value;
    }
    float ChatParticipant::Volume()
    {
        return volume;
    }
    void ChatParticipant::Volume(float value)
    {
        volume = value;
    }
    void ChatParticipant::SynthesizeTextMessageAsAudioBuffers(hstring const& message, winrt::Windows::Media::SpeechSynthesis::VoiceInformation const& voice)
    {

    }
}
