#pragma once
#include "Windows.Xbox.System.AudioDeviceInfo.g.h"
#include "Windows.Xbox.System.AudioDeviceAddedEventArgs.g.h"
#include "Windows.Xbox.System.AudioDeviceChangedEventArgs.g.h"
#include "Windows.Xbox.System.AudioDeviceRemovedEventArgs.g.h"

namespace winrt::Windows::Xbox::System::implementation
{
    struct AudioDeviceAddedEventArgs : AudioDeviceAddedEventArgsT<AudioDeviceAddedEventArgs>
    {
        AudioDeviceAddedEventArgs() = default;
        AudioDeviceAddedEventArgs(winrt::Windows::Xbox::System::User aUser, 
            winrt::Windows::Xbox::System::AudioDeviceInfo aAudioDevice) : user(aUser), audioDevice(aAudioDevice) {};

        winrt::Windows::Xbox::System::User User();
        winrt::Windows::Xbox::System::AudioDeviceInfo AudioDevice();
    private:
        winrt::Windows::Xbox::System::User user;
        winrt::Windows::Xbox::System::AudioDeviceInfo audioDevice;
    };

    struct AudioDeviceChangedEventArgs : AudioDeviceChangedEventArgsT<AudioDeviceChangedEventArgs>
    {
        AudioDeviceChangedEventArgs() = default;
        AudioDeviceChangedEventArgs(winrt::Windows::Xbox::System::User aUser, 
            winrt::Windows::Xbox::System::AudioDeviceInfo aAudioDevice) : user(aUser), audioDevice(aAudioDevice) {};

        winrt::Windows::Xbox::System::User User();
        winrt::Windows::Xbox::System::AudioDeviceInfo AudioDevice();
    private:
        winrt::Windows::Xbox::System::User user;
        winrt::Windows::Xbox::System::AudioDeviceInfo audioDevice;
    };

    struct AudioDeviceRemovedEventArgs : AudioDeviceRemovedEventArgsT<AudioDeviceRemovedEventArgs>
    {
        AudioDeviceRemovedEventArgs() = default;
        AudioDeviceRemovedEventArgs(winrt::Windows::Xbox::System::User aUser, 
            winrt::Windows::Xbox::System::AudioDeviceInfo aAudioDevice) : user(aUser), audioDevice(aAudioDevice) {};

        winrt::Windows::Xbox::System::User User();
        winrt::Windows::Xbox::System::AudioDeviceInfo AudioDevice();
    private:
        winrt::Windows::Xbox::System::User user;
        winrt::Windows::Xbox::System::AudioDeviceInfo audioDevice;
    };

    struct AudioDeviceInfo : AudioDeviceInfoT<AudioDeviceInfo>
    {
        AudioDeviceInfo() = default;
        AudioDeviceInfo(hstring Id, winrt::Windows::Xbox::System::AudioDeviceType audioDeviceType,
            winrt::Windows::Xbox::System::AudioDeviceSharing audioDeviceSharing,
            winrt::Windows::Xbox::System::AudioDeviceCategory audioDeviceCategory, bool muted) 
            : id(Id), deviceType(audioDeviceType), sharing(audioDeviceSharing), deviceCategory(audioDeviceCategory), isMuted(muted) {};

        hstring Id();
        winrt::Windows::Xbox::System::AudioDeviceType DeviceType();
        winrt::Windows::Xbox::System::AudioDeviceSharing Sharing();
        winrt::Windows::Xbox::System::AudioDeviceCategory DeviceCategory();
        bool IsMicrophoneMuted();
    private:
        hstring id = L"";
        winrt::Windows::Xbox::System::AudioDeviceType deviceType = winrt::Windows::Xbox::System::AudioDeviceType::Capture;
        winrt::Windows::Xbox::System::AudioDeviceSharing sharing = winrt::Windows::Xbox::System::AudioDeviceSharing::Exclusive;
        winrt::Windows::Xbox::System::AudioDeviceCategory deviceCategory = winrt::Windows::Xbox::System::AudioDeviceCategory::Communications;
        bool isMuted = true;
    };
}
