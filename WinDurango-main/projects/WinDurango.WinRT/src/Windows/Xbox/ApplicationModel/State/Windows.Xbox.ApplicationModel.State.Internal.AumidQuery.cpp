#include "Windows.Xbox.ApplicationModel.State.Internal.AumidQuery.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::implementation
{
    void AumidQuery::GetXboxLiveInfo(hstring const& aumid, uint32_t& titleId, winrt::guid& primaryScid, bool& requireXboxLive)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: GetXboxLiveInfo");
        throw hresult_not_implemented();
    }
}
