#pragma once
#include "Windows.Xbox.Services.XboxLiveConfiguration.g.h"

namespace winrt::Windows::Xbox::Services::implementation
{
    struct XboxLiveConfiguration
    {
        XboxLiveConfiguration() = default;

        static hstring TitleId();
        static hstring PrimaryServiceConfigId();
        static hstring SandboxId();
    };
}

namespace winrt::Windows::Xbox::Services::factory_implementation
{
    struct XboxLiveConfiguration : XboxLiveConfigurationT<XboxLiveConfiguration, implementation::XboxLiveConfiguration>
    {
    };
}