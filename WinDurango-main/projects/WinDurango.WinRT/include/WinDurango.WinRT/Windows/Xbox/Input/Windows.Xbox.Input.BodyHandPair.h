#pragma once
#include "Windows.Xbox.Input.BodyHandPair.g.h"

namespace winrt::Windows::Xbox::Input::implementation
{
    struct BodyHandPair : BodyHandPairT<BodyHandPair>
    {
        BodyHandPair() = default;

        uint64_t BodyTrackingId();
        void BodyTrackingId(uint64_t value);
        winrt::Windows::Xbox::Input::HandType HandType();
        void HandType(winrt::Windows::Xbox::Input::HandType const& value);
    private:
        winrt::Windows::Xbox::Input::HandType handType = winrt::Windows::Xbox::Input::HandType::LEFT;
        uint64_t trackingID = 0;
    };
}
namespace winrt::Windows::Xbox::Input::factory_implementation
{
    struct BodyHandPair : BodyHandPairT<BodyHandPair, implementation::BodyHandPair>
    {
    };
}
