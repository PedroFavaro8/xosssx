#pragma once
#include "Windows.Xbox.UI.Accessibility.g.h"

namespace winrt::Windows::Xbox::UI::implementation
{
    struct Accessibility
    {
        Accessibility() = default;

        static void SetSpeechToTextPositionHint(winrt::Windows::Xbox::UI::SpeechToTextPositionHint const& position);
        static void SendSpeechToTextString(hstring const& speakerName, hstring const& content, winrt::Windows::Xbox::UI::SpeechToTextType const& type);
        static uint32_t BeginSpeechToTextHypothesisString(hstring const& speakerName, hstring const& content, winrt::Windows::Xbox::UI::SpeechToTextType const& type);
        static void UpdateSpeechToTextHypothesisString(uint32_t hypthesisId, hstring const& content);
        static void FinalizeSpeechToTextHypothesisString(uint32_t hypthesisId, hstring const& content);
        static void CancelSpeechToTextHypothesisString(uint32_t hypthesisId);
        static void ClearSpeechToTextStrings();
        static void SendSpeechToTextStringWithColor(hstring const& speakerName, hstring const& content, winrt::Windows::Xbox::UI::SpeechToTextType const& type, winrt::Windows::UI::Color const& speakerColor);
    };
}
namespace winrt::Windows::Xbox::UI::factory_implementation
{
    struct Accessibility : AccessibilityT<Accessibility, implementation::Accessibility>
    {
    };
}
