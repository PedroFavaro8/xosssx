#pragma once
#include "Windows.Xbox.UI.KeyboardOptions.g.h"

namespace winrt::Windows::Xbox::UI::implementation
{
    struct KeyboardOptions : KeyboardOptionsT<KeyboardOptions>
    {
        KeyboardOptions() = default;

        hstring DefaultText();
        void DefaultText(hstring const& value);
        hstring TitleText();
        void TitleText(hstring const& value);
        hstring DescriptionText();
        void DescriptionText(hstring const& value);
        uint32_t MaxLength();
        void MaxLength(uint32_t value);
        bool LengthIndicatorVisibility();
        void LengthIndicatorVisibility(bool value);
        uint32_t LengthIndicatorThreshold();
        void LengthIndicatorThreshold(uint32_t value);
        winrt::Windows::Xbox::UI::VirtualKeyboardInputScope InputScope();
        void InputScope(winrt::Windows::Xbox::UI::VirtualKeyboardInputScope const& value);
    };
}
namespace winrt::Windows::Xbox::UI::factory_implementation
{
    struct KeyboardOptions : KeyboardOptionsT<KeyboardOptions, implementation::KeyboardOptions>
    {
    };
}
