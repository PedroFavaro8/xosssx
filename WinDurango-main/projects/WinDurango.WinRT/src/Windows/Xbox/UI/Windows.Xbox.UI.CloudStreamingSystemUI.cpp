#include "Windows.Xbox.UI.CloudStreamingSystemUI.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::UI::implementation
{
    bool CloudStreamingSystemUI::ShouldRemoteSystemUI(winrt::Windows::Xbox::UI::CloudStreamingSystemUIType const& type)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: ShouldRemoteSystemUI");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> CloudStreamingSystemUI::RemoteShowVirtualKeyboardAsync(hstring titleText, hstring descriptionText, hstring defaultText, winrt::Windows::Xbox::UI::VirtualKeyboardInputScope inputScope, uint32_t maxLength, bool lengthIndicatorVisibility, uint32_t lengthIndicatorThreshold)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteShowVirtualKeyboardAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<uint32_t> CloudStreamingSystemUI::RemoteShowMessageDialogAsync(hstring titleText, hstring contentText, winrt::Windows::Xbox::UI::MessageDialogOptions options, hstring commandLabel1, hstring commandLabel2, hstring commandLabel3, uint32_t defaultIndex, uint32_t cancelIndex)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteShowMessageDialogAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> CloudStreamingSystemUI::RemoteShowPurchaseAsync(hstring xuid, hstring productId, hstring desiredItemTypes, hstring name, hstring extendedJsonData, hstring cv, winrt::Windows::Xbox::UI::RemotedPurchaseScenarioType scenario)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteShowPurchaseAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction CloudStreamingSystemUI::RemoteShowApplicationAsync(hstring uri)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteShowApplicationAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<bool> CloudStreamingSystemUI::RemoteShowTimerExtensionAsync(hstring appId, uint32_t minutesLeft, bool isAppBlocked)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteShowTimerExtensionAsync");
        throw hresult_not_implemented();
    }
    void CloudStreamingSystemUI::SetCloudStreamingServiceForTest(winrt::Windows::Foundation::IInspectable const& cloudStreamingService)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: SetCloudStreamingServiceForTest");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::UI::PrivilegeCheckResult> CloudStreamingSystemUI::RemoteCheckPrivilegesAsync(winrt::Windows::Xbox::System::User user, winrt::Windows::Foundation::Collections::IVectorView<uint32_t> privilegeIds, bool attemptResolution, hstring friendlyDisplay)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteCheckPrivilegesAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction CloudStreamingSystemUI::RemoteShowProfileCardAsync(winrt::Windows::Xbox::System::User requestingUser, hstring targetXuid)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteShowProfileCardAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction CloudStreamingSystemUI::RemoteLaunchAchievementsAsync(winrt::Windows::Xbox::System::User requestingUser, uint32_t titleId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteLaunchAchievementsAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::UI::AddRemoveFriendResult> CloudStreamingSystemUI::RemoteAddRemoveFriendAsync(winrt::Windows::Xbox::System::User requestingUser, hstring targetUserId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteAddRemoveFriendAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction CloudStreamingSystemUI::RemoteLaunchPartyAsync(winrt::Windows::Xbox::System::User requestingUser, winrt::Windows::Foundation::Collections::IVectorView<hstring> inviteUserIdList)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteLaunchPartyAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction CloudStreamingSystemUI::RemoteShowComposeMessageAsync(winrt::Windows::Xbox::System::User requestingUser, hstring defaultMessageText, winrt::Windows::Foundation::Collections::IVector<hstring> recipientUserIdList)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteShowComposeMessageAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<hstring>> CloudStreamingSystemUI::RemotePeoplePickerAsync(winrt::Windows::Xbox::System::User requestingUser, hstring promptText, winrt::Windows::Foundation::Collections::IVectorView<hstring> selectFromXuidList, winrt::Windows::Foundation::Collections::IVectorView<hstring> preselectedXuidList, uint32_t minimumSelectionCount, uint32_t maximumSelectionCount)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemotePeoplePickerAsync");
        throw hresult_not_implemented();
    }
    bool CloudStreamingSystemUI::ShouldRemoteAllProtocolActivations()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: ShouldRemoteAllProtocolActivations");
        throw hresult_not_implemented();
    }
    bool CloudStreamingSystemUI::ShouldBlockMultipleTCUIClientTransactions()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: ShouldBlockMultipleTCUIClientTransactions");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction CloudStreamingSystemUI::RemoteShowFeedbackAsync()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteShowFeedbackAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction CloudStreamingSystemUI::RemoteShowMicrophoneSettingsAsync()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteShowMicrophoneSettingsAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction CloudStreamingSystemUI::RemoteToggleMuteAsync()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteToggleMuteAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<bool> CloudStreamingSystemUI::RemoteShowPrivilegeBlockedAsync(winrt::Windows::Xbox::System::User user, uint32_t privilegeId, uint32_t titleId, winrt::Windows::Foundation::Collections::IPropertySet customOptions)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteShowPrivilegeBlockedAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction CloudStreamingSystemUI::RemoteShowGameTimeAsync(hstring aumid, uint32_t notificationType, uint32_t secondsLeft, bool canRequestMoreTime, bool suppressNotification)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteShowGameTimeAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction CloudStreamingSystemUI::RemoteShowSendInvitesAsync(winrt::Windows::Xbox::System::User requestingUser)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteShowSendInvitesAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction CloudStreamingSystemUI::RemoteShowSendGameInvitesAsync(winrt::Windows::Xbox::System::User requestingUser, winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference sessionReferenceToInviteTo, hstring inviteDisplayTextId, hstring customActivationContext)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteShowSendGameInvitesAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction CloudStreamingSystemUI::RemoteShowSendMultiplayerActivityInvitesAsync(winrt::Windows::Xbox::System::User requestingUser, uint32_t titleId)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteShowSendMultiplayerActivityInvitesAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncAction CloudStreamingSystemUI::RemoteShowStateShareAsync(winrt::Windows::Xbox::System::User requestingUser, uint32_t xblTitleId, hstring linkToken)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: RemoteShowStateShareAsync");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::UI::AddRemoveFriendResultStatus AddRemoveFriendResult::Status()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: Status");
        throw hresult_not_implemented();
    }
}
