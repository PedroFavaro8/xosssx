#pragma once
#include "Windows.Xbox.ApplicationModel.State.Internal.AumidQuery.g.h"

namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::implementation
{
    struct AumidQuery
    {
        AumidQuery() = default;

        static void GetXboxLiveInfo(hstring const& aumid, uint32_t& titleId, winrt::guid& primaryScid, bool& requireXboxLive);
    };
}
namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::factory_implementation
{
    struct AumidQuery : AumidQueryT<AumidQuery, implementation::AumidQuery>
    {
    };
}