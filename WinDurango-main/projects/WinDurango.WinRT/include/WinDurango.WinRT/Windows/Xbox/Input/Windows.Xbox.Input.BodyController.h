#pragma once
#include "Windows.Xbox.Input.BodyController.g.h"
#include "Windows.Xbox.Input.BodyControllerAddedEventArgs.g.h"
#include "Windows.Xbox.Input.BodyControllerRemovedEventArgs.g.h"
#include "Windows.Xbox.Input.BodyControllerReading.g.h"
#include "Windows.Xbox.Input.BodyControllerReadingChangedEventArgs.g.h"

namespace winrt::Windows::Xbox::Input::implementation
{
    struct BodyControllerAddedEventArgs : BodyControllerAddedEventArgsT<BodyControllerAddedEventArgs>
    {
        BodyControllerAddedEventArgs() = default;
        BodyControllerAddedEventArgs(winrt::Windows::Xbox::Input::BodyController controller) : controller(controller) {}

        winrt::Windows::Xbox::Input::BodyController BodyController();
    private:
        winrt::Windows::Xbox::Input::BodyController controller;
    };

    struct BodyControllerRemovedEventArgs : BodyControllerRemovedEventArgsT<BodyControllerRemovedEventArgs>
    {
        BodyControllerRemovedEventArgs() = default;
        BodyControllerRemovedEventArgs(winrt::Windows::Xbox::Input::BodyController controller) : controller(controller) {}

        winrt::Windows::Xbox::Input::BodyController BodyController();
    private:
        winrt::Windows::Xbox::Input::BodyController controller;
    };

    struct BodyControllerReading : BodyControllerReadingT<BodyControllerReading>
    {
        BodyControllerReading() = default;
        BodyControllerReading(winrt::Windows::Foundation::DateTime time, bool isLeanTracked, float leanX, float leanY)
            : time(time), isLeanTracked(isLeanTracked), leanX(leanX), leanY(leanY) {}

        winrt::Windows::Foundation::DateTime Timestamp();
        bool IsLeanTracked();
        float LeanX();
        float LeanY();
    private:
        winrt::Windows::Foundation::DateTime time;
        bool isLeanTracked = false;
        float leanX = 0.0f;
        float leanY = 1.0f;
    };

    struct BodyControllerReadingChangedEventArgs : BodyControllerReadingChangedEventArgsT<BodyControllerReadingChangedEventArgs>
    {
        BodyControllerReadingChangedEventArgs() = default;
        BodyControllerReadingChangedEventArgs(winrt::Windows::Xbox::Input::BodyControllerReading reading) : reading(reading) {}

        winrt::Windows::Xbox::Input::BodyControllerReading Reading();
    private:
        winrt::Windows::Xbox::Input::BodyControllerReading reading;
    };

    struct BodyController : BodyControllerT<BodyController>
    {
        BodyController() = default;
        BodyController(uint64_t id) : id(id) {}

        uint64_t Id();
        hstring Type();
        winrt::Windows::Xbox::System::User User();
        uint32_t BiometricUserId();
        winrt::event_token BiometricUserChanged(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Input::BodyController, winrt::Windows::Xbox::Input::BiometricUserChangedEventArgs> const& handler);
        void BiometricUserChanged(winrt::event_token const& token) noexcept;
        winrt::Windows::Xbox::Input::BodyControllerReading GetCurrentReading();
        void GetCurrentReading(winrt::Windows::Xbox::Input::BodyControllerReading const& value);
        winrt::event_token ReadingChanged(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Xbox::Input::BodyController, winrt::Windows::Xbox::Input::BodyControllerReadingChangedEventArgs> const& handler);
        void ReadingChanged(winrt::event_token const& token) noexcept;
    private:
        uint64_t id = 0;
    };
}
namespace winrt::Windows::Xbox::Input::factory_implementation
{
    struct BodyController : BodyControllerT<BodyController, implementation::BodyController>
    {
    };
}
