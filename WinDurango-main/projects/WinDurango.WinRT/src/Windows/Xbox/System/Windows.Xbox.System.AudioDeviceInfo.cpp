#include "Windows.Xbox.System.AudioDeviceInfo.h"

namespace winrt::Windows::Xbox::System::implementation
{
    winrt::Windows::Xbox::System::User AudioDeviceAddedEventArgs::User()
    {
        return user;
    }

    winrt::Windows::Xbox::System::AudioDeviceInfo AudioDeviceAddedEventArgs::AudioDevice()
    {
        return audioDevice;
    }

    winrt::Windows::Xbox::System::User AudioDeviceChangedEventArgs::User()
    {
        return user;
    }

    winrt::Windows::Xbox::System::AudioDeviceInfo AudioDeviceChangedEventArgs::AudioDevice()
    {
        return audioDevice;
    }

    winrt::Windows::Xbox::System::User AudioDeviceRemovedEventArgs::User()
    {
        return user;
    }

    winrt::Windows::Xbox::System::AudioDeviceInfo AudioDeviceRemovedEventArgs::AudioDevice()
    {
        return audioDevice;
    }

    hstring AudioDeviceInfo::Id()
    {
        return id;
    }

    winrt::Windows::Xbox::System::AudioDeviceType AudioDeviceInfo::DeviceType()
    {
        return deviceType;
    }

    winrt::Windows::Xbox::System::AudioDeviceSharing AudioDeviceInfo::Sharing()
    {
        return sharing;
    }

    winrt::Windows::Xbox::System::AudioDeviceCategory AudioDeviceInfo::DeviceCategory()
    {
        return deviceCategory;
    }

    bool AudioDeviceInfo::IsMicrophoneMuted()
    {
        return isMuted;
    }
}
