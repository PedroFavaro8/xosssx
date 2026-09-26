#pragma once
#include "Windows.Xbox.Chat.Format.g.h"

namespace winrt::Windows::Xbox::Chat::implementation
{
    struct Format : FormatT<Format>
    {
        Format() = default;

        void BitsPerSample(uint32_t value);
        uint32_t BitsPerSample();
        uint32_t Bitrate();
        void ChannelCount(uint32_t value);
        uint32_t ChannelCount();
        void SampleRate(uint32_t value);
        uint32_t SampleRate();
        void Subtype(winrt::guid const& value);
        winrt::guid Subtype();
    private:
        uint32_t bitsPerSample;
        uint32_t channelCount;
        uint32_t sampleRate;
        winrt::guid subtype;
    };
}
namespace winrt::Windows::Xbox::Chat::factory_implementation
{
    struct Format : FormatT<Format, implementation::Format>
    {
    };
}
