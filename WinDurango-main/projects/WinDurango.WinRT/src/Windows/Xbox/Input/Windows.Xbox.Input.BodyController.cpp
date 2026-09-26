#include "Windows.Xbox.Input.BodyController.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::Input::implementation
{
    winrt::Windows::Xbox::Input::BodyController BodyControllerAddedEventArgs::BodyController()
    {
        return controller;
    }
    winrt::Windows::Xbox::Input::BodyController BodyControllerRemovedEventArgs::BodyController()
    {
        return controller;
    }

    winrt::Windows::Foundation::DateTime BodyControllerReading::Timestamp()
    {
        return time;
    }

    bool BodyControllerReading::IsLeanTracked()
    {
        return isLeanTracked;
    }

    float BodyControllerReading::LeanX()
    {
        return leanX;
    }

    float BodyControllerReading::LeanY()
    {
        return leanY;
    }

    winrt::Windows::Xbox::Input::BodyControllerReading BodyControllerReadingChangedEventArgs::Reading()
    {
        return reading;
    }

    uint64_t BodyController::Id()
    {
        return id;
    }

    hstring BodyController::Type()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Input", "Unimplemented: Type");
        throw hresult_not_implemented();
    }

    winrt::Windows::Xbox::System::User BodyController::User()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Input", "Unimplemented: User");
        throw hresult_not_implemented();
    }

    uint32_t BodyController::BiometricUserId()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Input", "Unimplemented: BiometricUserId");
        throw hresult_not_implemented();
    }

    winrt::event_token BodyController::BiometricUserChanged(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Input::BodyController, winrt::Windows::Xbox::Input::BiometricUserChangedEventArgs> const& handler)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Input", "Unimplemented: add_BiometricUserChanged");
        throw hresult_not_implemented();
    }

    void BodyController::BiometricUserChanged(winrt::event_token const& token) noexcept
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Input", "Unimplemented: remove_BiometricUserChanged");
        throw hresult_not_implemented();
    }

    winrt::Windows::Xbox::Input::BodyControllerReading BodyController::GetCurrentReading()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Input", "Unimplemented: put_GetCurrentReading");
        throw hresult_not_implemented();
    }

    void BodyController::GetCurrentReading(winrt::Windows::Xbox::Input::BodyControllerReading const& value)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Input", "Unimplemented: set_GetCurrentReading");
        throw hresult_not_implemented();
    }

    winrt::event_token BodyController::ReadingChanged(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Input::BodyController, winrt::Windows::Xbox::Input::BodyControllerReadingChangedEventArgs> const& handler)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Input", "Unimplemented: add_ReadingChanged");
        throw hresult_not_implemented();
    }

    void BodyController::ReadingChanged(winrt::event_token const& token) noexcept
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Input", "Unimplemented: remove_ReadingChanged");
        throw hresult_not_implemented();
    }
}
