#include "Windows.Xbox.Input.BiometricUser.h"

namespace winrt::Windows::Xbox::Input::implementation
{
    uint32_t BiometricUserChangedEventArgs::BiometricUserId()
    {
        return id;
    }
}
