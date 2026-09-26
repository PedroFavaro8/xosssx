#include "Windows.Xbox.Media.GameTransportControls.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::Media::implementation
{
    hstring GameTransportControls::Title()
    {
        return _title;
    }

    void GameTransportControls::Title(hstring const &value)
    {
        _title = value;
    }

    hstring GameTransportControls::Subtitle()
    {
        return _subtitle;
    }

    void GameTransportControls::Subtitle(hstring const &value)
    {
        _subtitle = value;
    }

    winrt::Windows::Xbox::Media::GamePlaybackStatus GameTransportControls::PlaybackStatus()
    {
        return _playbackStatus;
    }

    void GameTransportControls::PlaybackStatus(winrt::Windows::Xbox::Media::GamePlaybackStatus const &value)
    {
        _playbackStatus = value;
    }

    Windows::Xbox::Media::SoundLevel GameTransportControls::SoundLevel()
    {
        return Windows::Xbox::Media::SoundLevel::Full;
    }

    bool GameTransportControls::IsEnabled()
    {
        return _isEnabled;
    }

    void GameTransportControls::IsEnabled(bool value)
    {
        _isEnabled = value;
    }

    bool GameTransportControls::IsPlayEnabled()
    {
        return _isPlayEnabled;
    }

    void GameTransportControls::IsPlayEnabled(bool value)
    {
        _isPlayEnabled = value;
    }

    bool GameTransportControls::IsPauseEnabled()
    {
        return _isPauseEnabled;
    }

    void GameTransportControls::IsPauseEnabled(bool value)
    {
        _isPauseEnabled = value;
    }

    bool GameTransportControls::IsMenuEnabled()
    {
        return _isMenuEnabled;
    }

    void GameTransportControls::IsMenuEnabled(bool value)
    {
        _isMenuEnabled = value;
    }

    bool GameTransportControls::IsViewEnabled()
    {
        return _isViewEnabled;
    }

    void GameTransportControls::IsViewEnabled(bool value)
    {
        _isViewEnabled = value;
    }

    bool GameTransportControls::IsBackEnabled()
    {
        return _isBackEnabled;
    }

    void GameTransportControls::IsBackEnabled(bool value)
    {
        _isBackEnabled = value;
    }

    winrt::event_token GameTransportControls::ButtonPressed(
        Windows::Foundation::TypedEventHandler<
            winrt::Windows::Xbox::Media::GameTransportControls,
            winrt::Windows::Xbox::Media::GameTransportControlsButtonPressedEventArgs> const &handler)
    {
        return {};
    }

    void GameTransportControls::ButtonPressed(winrt::event_token const &token)
    {

    }

    winrt::event_token GameTransportControls::PropertyChanged(
        Windows::Foundation::TypedEventHandler<
            winrt::Windows::Xbox::Media::GameTransportControls,
            winrt::Windows::Xbox::Media::GameTransportControlsPropertyChangedEventArgs> const &handler)
    {
        return {};
    }

    void GameTransportControls::PropertyChanged(winrt::event_token const &token)
    {

    }
} // namespace winrt::Windows::Xbox::Media::implementation
