#pragma once
#include "Windows.Xbox.ApplicationModel.State.Internal.ProtocolQuery.g.h"

namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::implementation
{
    struct ProtocolQuery
    {
        ProtocolQuery() = default;

        static winrt::Windows::Foundation::Collections::IVectorView<hstring> FindAumidsForScheme(hstring const& scheme);
    };
}
namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::factory_implementation
{
    struct ProtocolQuery : ProtocolQueryT<ProtocolQuery, implementation::ProtocolQuery>
    {
    };
}
