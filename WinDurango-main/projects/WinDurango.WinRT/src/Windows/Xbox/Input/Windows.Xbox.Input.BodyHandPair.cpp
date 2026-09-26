#include "Windows.Xbox.Input.BodyHandPair.h"

namespace winrt::Windows::Xbox::Input::implementation
{
    uint64_t BodyHandPair::BodyTrackingId()
    {
        return trackingID;
    }

    void BodyHandPair::BodyTrackingId(uint64_t value)
    {
        trackingID = value;
    }

    winrt::Windows::Xbox::Input::HandType BodyHandPair::HandType()
    {
        return handType;
    }

    void BodyHandPair::HandType(winrt::Windows::Xbox::Input::HandType const& value)
    {
        handType = value;
    }
}
