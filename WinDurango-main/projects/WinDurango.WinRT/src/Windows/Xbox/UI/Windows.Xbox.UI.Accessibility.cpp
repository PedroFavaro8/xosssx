#include "Windows.Xbox.UI.Accessibility.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::UI::implementation
{
    void Accessibility::SetSpeechToTextPositionHint(winrt::Windows::Xbox::UI::SpeechToTextPositionHint const& position)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: SetSpeechToTextPositionHint");
        throw hresult_not_implemented();
    }
    void Accessibility::SendSpeechToTextString(hstring const& speakerName, hstring const& content, winrt::Windows::Xbox::UI::SpeechToTextType const& type)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: SendSpeechToTextString");
        throw hresult_not_implemented();
    }
    uint32_t Accessibility::BeginSpeechToTextHypothesisString(hstring const& speakerName, hstring const& content, winrt::Windows::Xbox::UI::SpeechToTextType const& type)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: BeginSpeechToTextHypothesisString");
        throw hresult_not_implemented();
    }
    void Accessibility::UpdateSpeechToTextHypothesisString(uint32_t hypthesisId, hstring const& content)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: UpdateSpeechToTextHypothesisString");
        throw hresult_not_implemented();
    }
    void Accessibility::FinalizeSpeechToTextHypothesisString(uint32_t hypthesisId, hstring const& content)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: FinalizeSpeechToTextHypothesisString");
        throw hresult_not_implemented();
    }
    void Accessibility::CancelSpeechToTextHypothesisString(uint32_t hypthesisId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: CancelSpeechToTextHypothesisString");
        throw hresult_not_implemented();
    }
    void Accessibility::ClearSpeechToTextStrings()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: ClearSpeechToTextStrings");
        throw hresult_not_implemented();
    }
    void Accessibility::SendSpeechToTextStringWithColor(hstring const& speakerName, hstring const& content, winrt::Windows::Xbox::UI::SpeechToTextType const& type, winrt::Windows::UI::Color const& speakerColor)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: SendSpeechToTextStringWithColor");
        throw hresult_not_implemented();
    }
}
