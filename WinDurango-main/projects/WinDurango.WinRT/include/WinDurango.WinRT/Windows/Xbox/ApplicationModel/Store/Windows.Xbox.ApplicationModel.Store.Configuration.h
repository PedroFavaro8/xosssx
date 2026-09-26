#pragma once
#include "Windows.Xbox.ApplicationModel.Store.Configuration.g.h"

namespace winrt::Windows::Xbox::ApplicationModel::Store::implementation
{
    struct Configuration
    {
        Configuration() = default;

        static hstring MarketplaceId();
    };
}
namespace winrt::Windows::Xbox::ApplicationModel::Store::factory_implementation
{
    struct Configuration : ConfigurationT<Configuration, implementation::Configuration>
    {
    };
}
