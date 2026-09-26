#include "Windows.Xbox.Input.Gamepad.h"
#include "WinDurangoWinRT.h"
#include <winrt/base.h>
#include <algorithm>
#include <array>
#include <vector>

HMODULE XInput = nullptr;
typedef DWORD (WINAPI* PFN_XInputGetState)(
    DWORD dwUserIndex,
    XINPUT_STATE* pState
);

typedef DWORD (WINAPI* PFN_XInputGetCapabilities)(
    DWORD dwUserIndex,
    DWORD dwFlags,
    XINPUT_CAPABILITIES* pCapabilities
);

typedef DWORD (WINAPI* PFN_XInputSetState)(
    DWORD dwUserIndex,
    XINPUT_VIBRATION* pVibration
);

PFN_XInputGetState XInput1_3GetState;
PFN_XInputGetCapabilities XInput1_3GetCapabilities;
PFN_XInputSetState XInput1_3SetState;

namespace
{
    bool LoadXInputBackend()
    {
        if (XInput && XInput1_3GetState && XInput1_3GetCapabilities && XInput1_3SetState)
        {
            return true;
        }

        XInput1_3GetState = nullptr;
        XInput1_3GetCapabilities = nullptr;
        XInput1_3SetState = nullptr;

        constexpr const wchar_t* candidates[] = {
            L"xinput1_4.dll", L"xinput1_3.dll", L"xinput9_1_0.dll"};
        for (const auto* name : candidates)
        {
            HMODULE candidate = LoadLibraryW(name);
            if (!candidate)
            {
                continue;
            }

            auto getState = reinterpret_cast<PFN_XInputGetState>(GetProcAddress(candidate, "XInputGetState"));
            auto getCapabilities = reinterpret_cast<PFN_XInputGetCapabilities>(
                GetProcAddress(candidate, "XInputGetCapabilities"));
            auto setState = reinterpret_cast<PFN_XInputSetState>(GetProcAddress(candidate, "XInputSetState"));
            if (getState && getCapabilities && setState)
            {
                XInput = candidate;
                XInput1_3GetState = getState;
                XInput1_3GetCapabilities = getCapabilities;
                XInput1_3SetState = setState;
                return true;
            }
            FreeLibrary(candidate);
        }
        XInput = nullptr;
        return false;
    }
}

namespace winrt::Windows::Xbox::Input::implementation
{
    namespace
    {
        template <typename Enum>
        bool HasFlag(Enum value, Enum flag)
        {
            return (static_cast<uint32_t>(value) & static_cast<uint32_t>(flag)) != 0;
        }

        inline winrt::Windows::Foundation::DateTime ToDateTime(uint64_t millisSinceBoot)
        {
            return winrt::Windows::Foundation::DateTime{
                winrt::Windows::Foundation::TimeSpan{ static_cast<int64_t>(millisSinceBoot * 10000ULL) } };
        }

        struct NavigationReading : winrt::implements<NavigationReading, winrt::Windows::Xbox::Input::INavigationReading>
        {
            NavigationReading(uint64_t controllerId, RawNavigationReading value)
                : id(controllerId), reading(value)
            {
            }

            uint64_t Id()
            {
                return id;
            }

            hstring Type()
            {
                return L"Windows.Xbox.Input.NavigationReading";
            }

            winrt::Windows::Xbox::System::User User()
            {
                return winrt::Windows::Xbox::System::implementation::User::GetUserById(static_cast<uint32_t>(id % 4));
            }

            winrt::Windows::Foundation::DateTime Timestamp()
            {
                return ToDateTime(reading.Timestamp);
            }

            NavigationButtons Buttons()
            {
                return reading.Buttons;
            }

            bool IsUpPressed() { return HasFlag(reading.Buttons, NavigationButtons::Up); }
            bool IsDownPressed() { return HasFlag(reading.Buttons, NavigationButtons::Down); }
            bool IsLeftPressed() { return HasFlag(reading.Buttons, NavigationButtons::Left); }
            bool IsRightPressed() { return HasFlag(reading.Buttons, NavigationButtons::Right); }
            bool IsMenuPressed() { return HasFlag(reading.Buttons, NavigationButtons::Menu); }
            bool IsViewPressed() { return HasFlag(reading.Buttons, NavigationButtons::View); }
            bool IsPreviousPagePressed() { return HasFlag(reading.Buttons, NavigationButtons::PreviousPage); }
            bool IsNextPagePressed() { return HasFlag(reading.Buttons, NavigationButtons::NextPage); }
            bool IsAcceptPressed() { return HasFlag(reading.Buttons, NavigationButtons::Accept); }
            bool IsCancelPressed() { return HasFlag(reading.Buttons, NavigationButtons::Cancel); }
            bool IsXPressed() { return HasFlag(reading.Buttons, NavigationButtons::X); }
            bool IsYPressed() { return HasFlag(reading.Buttons, NavigationButtons::Y); }

        private:
            uint64_t id;
            RawNavigationReading reading;
        };

        RawNavigationReading ToNavigationReading(const RawGamepadReading& gamepad)
        {
            RawNavigationReading navigation{};
            navigation.Timestamp = gamepad.Timestamp;

            const auto buttons = gamepad.Buttons;
            if (HasFlag(buttons, GamepadButtons::DPadUp) || gamepad.LeftThumbstickY > 0.5f)
                navigation.Buttons |= NavigationButtons::Up;
            if (HasFlag(buttons, GamepadButtons::DPadDown) || gamepad.LeftThumbstickY < -0.5f)
                navigation.Buttons |= NavigationButtons::Down;
            if (HasFlag(buttons, GamepadButtons::DPadLeft) || gamepad.LeftThumbstickX < -0.5f)
                navigation.Buttons |= NavigationButtons::Left;
            if (HasFlag(buttons, GamepadButtons::DPadRight) || gamepad.LeftThumbstickX > 0.5f)
                navigation.Buttons |= NavigationButtons::Right;
            if (HasFlag(buttons, GamepadButtons::Menu))
                navigation.Buttons |= NavigationButtons::Menu;
            if (HasFlag(buttons, GamepadButtons::View))
                navigation.Buttons |= NavigationButtons::View;
            if (HasFlag(buttons, GamepadButtons::A))
                navigation.Buttons |= NavigationButtons::Accept;
            if (HasFlag(buttons, GamepadButtons::B))
                navigation.Buttons |= NavigationButtons::Cancel;
            if (HasFlag(buttons, GamepadButtons::X))
                navigation.Buttons |= NavigationButtons::X;
            if (HasFlag(buttons, GamepadButtons::Y))
                navigation.Buttons |= NavigationButtons::Y;

            return navigation;
        }
    }

    winrt::Windows::Xbox::Input::Gamepad GamepadAddedEventArgs::Gamepad()
    {
        return gamepad;
    }

    winrt::Windows::Xbox::Input::Gamepad GamepadRemovedEventArgs::Gamepad()
    {
        return gamepad;
    }

    winrt::Windows::Foundation::DateTime GamepadReading::Timestamp()
    {
        return winrt::Windows::Foundation::DateTime{
            winrt::Windows::Foundation::TimeSpan{ static_cast<int64_t>(reading.Timestamp * 10000ULL) } };
    }

    winrt::Windows::Xbox::Input::GamepadButtons GamepadReading::Buttons()
    {
        return reading.Buttons;
    }

    bool GamepadReading::IsDPadUpPressed()
    {
        return (int)reading.Buttons & (int)GamepadButtons::DPadUp;
    }
    bool GamepadReading::IsDPadDownPressed()
    {
        return (int)reading.Buttons & (int)GamepadButtons::DPadDown;
    }
    bool GamepadReading::IsDPadLeftPressed()
    {
        return (int)reading.Buttons & (int)GamepadButtons::DPadLeft;
    }
    bool GamepadReading::IsDPadRightPressed()
    {
        return (int)reading.Buttons & (int)GamepadButtons::DPadRight;
    }
    bool GamepadReading::IsMenuPressed()
    {
        return (int)reading.Buttons & (int)GamepadButtons::Menu;
    }
    bool GamepadReading::IsViewPressed()
    {
        return (int)reading.Buttons & (int)GamepadButtons::View;
    }
    bool GamepadReading::IsLeftThumbstickPressed()
    {
        return (int)reading.Buttons & (int)GamepadButtons::LeftThumbstick;
    }
    bool GamepadReading::IsRightThumbstickPressed()
    {
        return (int)reading.Buttons & (int)GamepadButtons::RightThumbstick;
    }
    bool GamepadReading::IsLeftShoulderPressed()
    {
        return (int)reading.Buttons & (int)GamepadButtons::LeftShoulder;
    }
    bool GamepadReading::IsRightShoulderPressed()
    {
        return (int)reading.Buttons & (int)GamepadButtons::RightShoulder;
    }
    bool GamepadReading::IsAPressed()
    {
        return (int)reading.Buttons & (int)GamepadButtons::A;
    }
    bool GamepadReading::IsBPressed()
    {
        return (int)reading.Buttons & (int)GamepadButtons::B;
    }
    bool GamepadReading::IsXPressed()
    {
        return (int)reading.Buttons & (int)GamepadButtons::X;
    }
    bool GamepadReading::IsYPressed()
    {
        return (int)reading.Buttons & (int)GamepadButtons::Y;
    }
    float GamepadReading::LeftTrigger()
    {
        return reading.LeftTrigger;
    }
    float GamepadReading::RightTrigger()
    {
        return reading.RightTrigger;
    }
    float GamepadReading::LeftThumbstickX()
    {
        return reading.LeftThumbstickX;
    }
    float GamepadReading::LeftThumbstickY()
    {
        return reading.LeftThumbstickY;
    }
    float GamepadReading::RightThumbstickX()
    {
        return reading.RightThumbstickX;
    }
    float GamepadReading::RightThumbstickY()
    {
        return reading.RightThumbstickY;
    }

    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Input::IGamepad> Gamepad::Gamepads()
    {
        auto previous = a_gamepads;
        if (!LoadXInputBackend())
        {
            std::vector<winrt::Windows::Xbox::Input::Gamepad> removedEvents;
            if (previous)
            {
                for (uint32_t i = 0; i < previous.Size(); ++i)
                {
                    auto previousGamepad = previous.GetAt(i);
                    if (previousGamepad)
                    {
                        removedEvents.push_back(previousGamepad.as<winrt::Windows::Xbox::Input::Gamepad>());
                    }
                }
            }
            a_gamepads = winrt::single_threaded_vector<winrt::Windows::Xbox::Input::IGamepad>();
            if (p_wd)
            {
                p_wd->log.Warn("WinDurango::WinRT::Windows.Xbox.Input", "XInput backend unavailable");
            }
            for (const auto& removed : removedEvents)
            {
                e_GamepadRemoved(nullptr, GamepadRemovedEventArgs(removed));
            }
            return a_gamepads.GetView();
        }

        auto current = winrt::single_threaded_vector<winrt::Windows::Xbox::Input::IGamepad>();
        std::array<bool, XUSER_MAX_COUNT> present{};
        std::vector<winrt::Windows::Xbox::Input::Gamepad> addedEvents;
        std::vector<winrt::Windows::Xbox::Input::Gamepad> removedEvents;

        for (DWORD gamepad = 0; gamepad < XUSER_MAX_COUNT; gamepad++)
        {
            XINPUT_CAPABILITIES capabilities{};
            XINPUT_STATE state{};
            const auto XI_cap = XInput1_3GetCapabilities(gamepad, XINPUT_FLAG_GAMEPAD, &capabilities);
            const auto XI_stat = XInput1_3GetState(gamepad, &state);

            if (XI_cap != ERROR_SUCCESS && XI_stat != ERROR_SUCCESS)
            {
                continue;
            }

            present[gamepad] = true;
            winrt::Windows::Xbox::Input::IGamepad existing{nullptr};
            if (previous)
            {
                for (uint32_t i = 0; i < previous.Size(); ++i)
                {
                    auto candidate = previous.GetAt(i);
                    if (candidate && candidate.Id() == gamepad)
                    {
                        existing = candidate;
                        break;
                    }
                }
            }

            if (!existing)
            {
                auto added = winrt::make<Gamepad>(gamepad, true);
                current.Append(added);
                addedEvents.push_back(added);
            }
            else
            {
                current.Append(existing);
            }
        }

        if (previous)
        {
            for (uint32_t i = 0; i < previous.Size(); ++i)
            {
                auto previousGamepad = previous.GetAt(i);
                if (previousGamepad && previousGamepad.Id() < XUSER_MAX_COUNT && !present[previousGamepad.Id()])
                {
                    removedEvents.push_back(previousGamepad.as<winrt::Windows::Xbox::Input::Gamepad>());
                }
            }
        }

        a_gamepads = current;

        for (const auto& added : addedEvents)
        {
            e_GamepadAdded(nullptr, GamepadAddedEventArgs(added));
        }
        for (const auto& removed : removedEvents)
        {
            e_GamepadRemoved(nullptr, GamepadRemovedEventArgs(removed));
        }

        return a_gamepads.GetView();
    }

    winrt::event_token Gamepad::GamepadAdded(winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::Input::GamepadAddedEventArgs> const& handler)
    {
        return e_GamepadAdded.add(handler);
    }

    void Gamepad::GamepadAdded(winrt::event_token const& token) noexcept
    {
        e_GamepadAdded.remove(token);
    }

    winrt::event_token Gamepad::GamepadRemoved(winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::Input::GamepadRemovedEventArgs> const& handler)
    {
        return e_GamepadRemoved.add(handler);
    }

    void Gamepad::GamepadRemoved(winrt::event_token const& token) noexcept
    {
        e_GamepadRemoved.remove(token);
    }

    uint64_t Gamepad::Id()
    {
        return id;
    }

    hstring Gamepad::Type()
    {
        return L"Windows.Xbox.Input.Gamepad";
    }

    winrt::Windows::Xbox::System::User Gamepad::User()
    {
        return winrt::Windows::Xbox::System::implementation::User::GetUserById(static_cast<uint32_t>(Id() % 4));
    }

    winrt::Windows::Xbox::Input::INavigationReading Gamepad::GetNavigationReading()
    {
        return winrt::make<NavigationReading>(id, ToNavigationReading(GetRawCurrentReading())).as<winrt::Windows::Xbox::Input::INavigationReading>();
    }

    winrt::Windows::Xbox::Input::RawNavigationReading Gamepad::GetRawNavigationReading()
    {
        return ToNavigationReading(GetRawCurrentReading());
    }

    void Gamepad::SetVibration(winrt::Windows::Xbox::Input::GamepadVibration const& value)
    {
        if (!gamepad || !XInput1_3SetState || id >= XUSER_MAX_COUNT)
        {
            return;
        }

        XINPUT_VIBRATION Vibration{};
        const auto toMotorLevel = [](float level) {
            return static_cast<WORD>(std::clamp(level, 0.0f, 1.0f) * 65535.0f);
        };
        Vibration.wLeftMotorSpeed = toMotorLevel(value.LeftMotorLevel);
        Vibration.wRightMotorSpeed = toMotorLevel(value.RightMotorLevel);
        XInput1_3SetState(id, &Vibration);
    }

    winrt::Windows::Xbox::Input::GamepadReading Gamepad::GetCurrentReading()
    {
        return winrt::make<implementation::GamepadReading>(GetRawCurrentReading());
    }

    winrt::Windows::Xbox::Input::RawGamepadReading Gamepad::GetRawCurrentReading()
    {
        XINPUT_STATE xiState = {};
        RawGamepadReading reading = {};
        reading.Timestamp = GetTickCount64();

        std::pair<WORD, GamepadButtons> const buttons[] = {
            {XINPUT_GAMEPAD_DPAD_UP, GamepadButtons::DPadUp},
            {XINPUT_GAMEPAD_DPAD_DOWN, GamepadButtons::DPadDown},
            {XINPUT_GAMEPAD_DPAD_LEFT, GamepadButtons::DPadLeft},
            {XINPUT_GAMEPAD_DPAD_RIGHT, GamepadButtons::DPadRight},
            {XINPUT_GAMEPAD_START, GamepadButtons::Menu},
            {XINPUT_GAMEPAD_BACK, GamepadButtons::View},
            {XINPUT_GAMEPAD_LEFT_THUMB, GamepadButtons::LeftThumbstick},
            {XINPUT_GAMEPAD_RIGHT_THUMB, GamepadButtons::RightThumbstick},
            {XINPUT_GAMEPAD_LEFT_SHOULDER, GamepadButtons::LeftShoulder},
            {XINPUT_GAMEPAD_RIGHT_SHOULDER, GamepadButtons::RightShoulder},
            {XINPUT_GAMEPAD_A, GamepadButtons::A},
            {XINPUT_GAMEPAD_B, GamepadButtons::B},
            {XINPUT_GAMEPAD_X, GamepadButtons::X},
            {XINPUT_GAMEPAD_Y, GamepadButtons::Y},
        };

        if (gamepad && XInput1_3GetState && id < XUSER_MAX_COUNT && XInput1_3GetState(id, &xiState) == ERROR_SUCCESS)
        {
            for (int i = 0; i < ARRAYSIZE(buttons); i++)
            {
                if (xiState.Gamepad.wButtons & buttons[i].first)
                {
                    reading.Buttons |= buttons[i].second;
                }
            }

            reading.LeftTrigger = xiState.Gamepad.bLeftTrigger / 255.f;
            reading.RightTrigger = xiState.Gamepad.bRightTrigger / 255.f;
            reading.LeftThumbstickX = xiState.Gamepad.sThumbLX / 32768.f;
            reading.LeftThumbstickY = xiState.Gamepad.sThumbLY / 32768.f;
            reading.RightThumbstickX = xiState.Gamepad.sThumbRX / 32768.f;
            reading.RightThumbstickY = xiState.Gamepad.sThumbRY / 32768.f;
        }

        SHORT kb_wm = 0;
        SHORT kb_am = 0;
        SHORT kb_sm = 0;
        SHORT kb_dm = 0;
        SHORT kb_a = 0;
        SHORT kb_b = 0;
        SHORT kb_x = 0;
        SHORT kb_y = 0;
        SHORT kb_up = 0;
        SHORT kb_down = 0;
        SHORT kb_left = 0;
        SHORT kb_right = 0;
        SHORT kb_menu = 0;
        SHORT kb_view = 0;
        SHORT kb_lt = 0;
        SHORT kb_rt = 0;
        SHORT kb_ls = 0;
        SHORT kb_rs = 0;
        SHORT kb_rtr = 0;
        SHORT kb_ltr = 0;

        if (p_wd && p_wd->config.jsonData().contains("keyboard") && p_wd->config["keyboard"].is_object()) 
        {
            if (p_wd->config["keyboard"].contains("WM") && p_wd->config["keyboard"]["WM"].is_number())
            {
                kb_wm = p_wd->config["keyboard"]["WM"];
            }
            if (p_wd->config["keyboard"].contains("AM") && p_wd->config["keyboard"]["AM"].is_number())
            {
                kb_am = p_wd->config["keyboard"]["AM"];
            }
            if (p_wd->config["keyboard"].contains("SM") && p_wd->config["keyboard"]["SM"].is_number())
            {
                kb_sm = p_wd->config["keyboard"]["SM"];
            }
            if (p_wd->config["keyboard"].contains("DM") && p_wd->config["keyboard"]["DM"].is_number())
            {
                kb_dm = p_wd->config["keyboard"]["DM"];
            }
            if (p_wd->config["keyboard"].contains("A") && p_wd->config["keyboard"]["A"].is_number())
            {
                kb_a = p_wd->config["keyboard"]["A"];
            }
            if (p_wd->config["keyboard"].contains("B") && p_wd->config["keyboard"]["B"].is_number())
            {
                kb_b = p_wd->config["keyboard"]["B"];
            }
            if (p_wd->config["keyboard"].contains("X") && p_wd->config["keyboard"]["X"].is_number())
            {
                kb_x = p_wd->config["keyboard"]["X"];
            }
            if (p_wd->config["keyboard"].contains("Y") && p_wd->config["keyboard"]["Y"].is_number())
            {
                kb_y = p_wd->config["keyboard"]["Y"];
            }
            if (p_wd->config["keyboard"].contains("Up") && p_wd->config["keyboard"]["Up"].is_number())
            {
                kb_up = p_wd->config["keyboard"]["Up"];
            }
            if (p_wd->config["keyboard"].contains("Down") && p_wd->config["keyboard"]["Down"].is_number())
            {
                kb_down = p_wd->config["keyboard"]["Down"];
            }
            if (p_wd->config["keyboard"].contains("Left") && p_wd->config["keyboard"]["Left"].is_number())
            {
                kb_left = p_wd->config["keyboard"]["Left"];
            }
            if (p_wd->config["keyboard"].contains("Right") && p_wd->config["keyboard"]["Right"].is_number())
            {
                kb_right = p_wd->config["keyboard"]["Right"];
            }
            if (p_wd->config["keyboard"].contains("Menu") && p_wd->config["keyboard"]["Menu"].is_number())
            {
                kb_menu = p_wd->config["keyboard"]["Menu"];
            }
            if (p_wd->config["keyboard"].contains("View") && p_wd->config["keyboard"]["View"].is_number())
            {
                kb_view = p_wd->config["keyboard"]["View"];
            }
            if (p_wd->config["keyboard"].contains("LeftThumb") && p_wd->config["keyboard"]["LeftThumb"].is_number())
            {
                kb_lt = p_wd->config["keyboard"]["LeftThumb"];
            }
            if (p_wd->config["keyboard"].contains("RightThumb") && p_wd->config["keyboard"]["RightThumb"].is_number())
            {
                kb_rt = p_wd->config["keyboard"]["RightThumb"];
            }
            if (p_wd->config["keyboard"].contains("LeftShoulder") && p_wd->config["keyboard"]["LeftShoulder"].is_number())
            {
                kb_ls = p_wd->config["keyboard"]["LeftShoulder"];
            }
            if (p_wd->config["keyboard"].contains("RightShoulder") && p_wd->config["keyboard"]["RightShoulder"].is_number())
            {
                kb_rs = p_wd->config["keyboard"]["RightShoulder"];
            }
            if (p_wd->config["keyboard"].contains("LeftTrigger") && p_wd->config["keyboard"]["LeftTrigger"].is_number())
            {
                kb_ltr = p_wd->config["keyboard"]["LeftTrigger"];
            }
            if (p_wd->config["keyboard"].contains("RightTrigger") && p_wd->config["keyboard"]["RightTrigger"].is_number())
            {
                kb_rtr = p_wd->config["keyboard"]["RightTrigger"];
            }
        }

        float lx = 0.0f;
        float ly = 0.0f;

        if (GetAsyncKeyState(kb_wm) & 0x8000) {
            ly = 1.0f;
        }

        if (GetAsyncKeyState(kb_am) & 0x8000) {
            lx = -1.0f;
        }

        if (GetAsyncKeyState(kb_sm) & 0x8000) {
            ly = -1.0;
        }

        if (GetAsyncKeyState(kb_dm) & 0x8000) {
            lx = 1.0f;
        }

        lx = std::clamp(lx, -1.0f, 1.0f);
        ly = std::clamp(ly, -1.0f, 1.0f);

        if (lx != 0.0f || ly != 0.0f) {
            reading.LeftThumbstickX = lx;
            reading.LeftThumbstickY = ly;
        }

        if (GetAsyncKeyState(kb_a) & 0x8000) {
            reading.Buttons |= GamepadButtons::A;
        }
        if (GetAsyncKeyState(kb_b) & 0x8000) {
            reading.Buttons |= GamepadButtons::B;
        }
        if (GetAsyncKeyState(kb_x) & 0x8000) {
            reading.Buttons |= GamepadButtons::X;
        }
        if (GetAsyncKeyState(kb_y) & 0x8000) {
            reading.Buttons |= GamepadButtons::Y;
        }
        if (GetAsyncKeyState(kb_up) & 0x8000) {
            reading.Buttons |= GamepadButtons::DPadUp;
        }
        if (GetAsyncKeyState(kb_down) & 0x8000) {
            reading.Buttons |= GamepadButtons::DPadDown;
        }
        if (GetAsyncKeyState(kb_left) & 0x8000) {
            reading.Buttons |= GamepadButtons::DPadLeft;
        }
        if (GetAsyncKeyState(kb_right) & 0x8000) {
            reading.Buttons |= GamepadButtons::DPadRight;
        }
        if (GetAsyncKeyState(kb_menu) & 0x8000) {
            reading.Buttons |= GamepadButtons::Menu;
        }
        if (GetAsyncKeyState(kb_view) & 0x8000) {
            reading.Buttons |= GamepadButtons::View;
        }
        if (GetAsyncKeyState(kb_lt) & 0x8000) {
            reading.Buttons |= GamepadButtons::LeftThumbstick;
        }
        if (GetAsyncKeyState(kb_rt) & 0x8000) {
            reading.Buttons |= GamepadButtons::RightThumbstick;
        }
        if (GetAsyncKeyState(kb_ls) & 0x8000) {
            reading.Buttons |= GamepadButtons::LeftShoulder;
        }
        if (GetAsyncKeyState(kb_rs) & 0x8000) {
            reading.Buttons |= GamepadButtons::RightShoulder;
        }

        if (GetAsyncKeyState(kb_ltr) & 0x8000) {
            reading.LeftTrigger = 1.0f;
        }
        if (GetAsyncKeyState(kb_rtr) & 0x8000) {
            reading.RightTrigger = 1.0f;
        }

        //Toggles the mouse lock
        const bool f9Pressed = (GetAsyncKeyState(VK_F9) & 0x8000) != 0;
        if (f9Pressed && !m_PreviousF9)
        {
            m_IsMouseLockEnabled = !m_IsMouseLockEnabled;
        }
        m_PreviousF9 = f9Pressed;

        if (m_IsMouseLockEnabled)
        {
            POINT MousePosition{};
            GetCursorPos(&MousePosition);

            if (firstFrame)
            {
                prev = MousePosition;
                firstFrame = false;
            }

            const int dx = MousePosition.x - prev.x;
            const int dy = MousePosition.y - prev.y;

            deltaSumX += dx;
            deltaSumY += dy;
            prev = MousePosition;

            const int centerX = GetSystemMetrics(SM_CXSCREEN) / 2;
            const int centerY = GetSystemMetrics(SM_CYSCREEN) / 2;

            SetCursorPos(centerX, centerY);

            prev.x = centerX;
            prev.y = centerY;

            auto sign = [](float v) { return (v > 0) - (v < 0); };
        
            float x = -std::exp((-1.0f / 5.0f) * std::abs(deltaSumX)) + 1.0f;
            float y = -std::exp((-1.0f / 5.0f) * std::abs(deltaSumY)) + 1.0f;

            x *= sign(deltaSumX);
            y *= -sign(deltaSumY);

            if (x != 0 || y != 0)
            {
                reading.RightThumbstickX = std::clamp(x, -1.0f, 1.0f);
                reading.RightThumbstickY = std::clamp(y, -1.0f, 1.0f);
            }

            deltaSumX = 0.0f;
            deltaSumY = 0.0f;
        }

        return reading;
    }

    winrt::event<winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::Input::GamepadAddedEventArgs>> Gamepad::e_GamepadAdded{};
    winrt::event<winrt::Windows::Foundation::EventHandler<winrt::Windows::Xbox::Input::GamepadRemovedEventArgs>> Gamepad::e_GamepadRemoved{};
    winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Xbox::Input::IGamepad> Gamepad::a_gamepads;
}
