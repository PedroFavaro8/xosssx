#include "Windows.Xbox.Networking.NetworkCache.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::Networking::implementation
{
    void NetworkCache::SetNetworkCacheForUsers(winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::System::User> const& pUsers)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: SetNetworkCacheForUsers");
        throw hresult_not_implemented();
    }
    void NetworkCache::ClearNetworkCache()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: ClearNetworkCache");
        throw hresult_not_implemented();
    }
}
