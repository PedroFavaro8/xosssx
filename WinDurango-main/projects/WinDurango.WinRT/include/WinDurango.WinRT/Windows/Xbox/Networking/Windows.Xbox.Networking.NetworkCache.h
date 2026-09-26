#pragma once
#include "Windows.Xbox.Networking.NetworkCache.g.h"

namespace winrt::Windows::Xbox::Networking::implementation
{
    struct NetworkCache
    {
        NetworkCache() = default;

        static void SetNetworkCacheForUsers(winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::System::User> const& pUsers);
        static void ClearNetworkCache();
    };
}
namespace winrt::Windows::Xbox::Networking::factory_implementation
{
    struct NetworkCache : NetworkCacheT<NetworkCache, implementation::NetworkCache>
    {
    };
}
