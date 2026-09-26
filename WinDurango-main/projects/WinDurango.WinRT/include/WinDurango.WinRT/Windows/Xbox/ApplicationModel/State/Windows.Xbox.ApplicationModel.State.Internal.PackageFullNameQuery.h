#pragma once
#include "Windows.Xbox.ApplicationModel.State.Internal.PackageFullNameQuery.g.h"

namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::implementation
{
    struct PackageFullNameQuery
    {
        PackageFullNameQuery() = default;

        static bool IsInbox(hstring const& packageFullName);
        static bool IsEra(hstring const& packageFullName);
        static winrt::Windows::Xbox::ApplicationModel::State::Internal::PackageContentType GetContentType(hstring const& packageFullName);
        static bool IsGameCore(hstring const& packageFullName);
    };
}
namespace winrt::Windows::Xbox::ApplicationModel::State::Internal::factory_implementation
{
    struct PackageFullNameQuery : PackageFullNameQueryT<PackageFullNameQuery, implementation::PackageFullNameQuery>
    {
    };
}
