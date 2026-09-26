#pragma once
#include "Windows.Xbox.ApplicationModel.Help.g.h"

namespace winrt::Windows::Xbox::ApplicationModel::implementation
{
    struct Help
    {
        Help() = default;

        static winrt::Windows::Foundation::IAsyncAction Show(winrt::Windows::Xbox::System::User usr);
        static winrt::Windows::Foundation::IAsyncAction ShowForError(hstring unk, hstring unka);
    };
}
namespace winrt::Windows::Xbox::ApplicationModel::factory_implementation
{
    struct Help : HelpT<Help, implementation::Help>
    {
    };
}
