#include "Windows.Xbox.ApplicationModel.State.Internal.ProtocolQuery.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::implementation
{
    winrt::Windows::Foundation::Collections::IVectorView<hstring> ProtocolQuery::FindAumidsForScheme(hstring const& scheme)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::State", "Unimplemented: FindAumidsForScheme");
        throw hresult_not_implemented();
    }
}
