#pragma once
#include "Windows.Xbox.Input.BiometricUserChangedEventArgs.g.h"

namespace winrt::Windows::Xbox::Input::implementation
{
    struct BiometricUserChangedEventArgs : BiometricUserChangedEventArgsT<BiometricUserChangedEventArgs>
    {
        BiometricUserChangedEventArgs() = default;
        BiometricUserChangedEventArgs(uint32_t id) : id(id) {}

        uint32_t BiometricUserId();
    private:
        uint32_t id = 0;
    };
}
