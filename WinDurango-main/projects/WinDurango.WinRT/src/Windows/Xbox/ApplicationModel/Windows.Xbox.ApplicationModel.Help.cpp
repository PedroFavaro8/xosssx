#include "Windows.Xbox.ApplicationModel.Help.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::ApplicationModel::implementation
{
    winrt::Windows::Foundation::IAsyncAction Help::Show(winrt::Windows::Xbox::System::User usr)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::Core", "Unimplemented: Show");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction Help::ShowForError(hstring unk, hstring unka)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::ApplicationModel::Core", "Unimplemented: ShowForError");
        throw hresult_not_implemented();
    }
}
