#pragma once
#include "Windows.Xbox.UI.AddRemoveFriendResult.g.h"
#include "Windows.Xbox.UI.CloudStreamingSystemUI.g.h"

namespace winrt::Windows::Xbox::UI::implementation
{
    struct AddRemoveFriendResult : AddRemoveFriendResultT<AddRemoveFriendResult>
    {
        AddRemoveFriendResult() = default;

        winrt::Windows::Xbox::UI::AddRemoveFriendResultStatus Status();
    };

    struct CloudStreamingSystemUI
    {
        CloudStreamingSystemUI() = default;

        static bool ShouldRemoteSystemUI(winrt::Windows::Xbox::UI::CloudStreamingSystemUIType const& type);
        static winrt::Windows::Foundation::IAsyncOperation<hstring> RemoteShowVirtualKeyboardAsync(hstring titleText, hstring descriptionText, hstring defaultText, winrt::Windows::Xbox::UI::VirtualKeyboardInputScope inputScope, uint32_t maxLength, bool lengthIndicatorVisibility, uint32_t lengthIndicatorThreshold);
        static winrt::Windows::Foundation::IAsyncOperation<uint32_t> RemoteShowMessageDialogAsync(hstring titleText, hstring contentText, winrt::Windows::Xbox::UI::MessageDialogOptions options, hstring commandLabel1, hstring commandLabel2, hstring commandLabel3, uint32_t defaultIndex, uint32_t cancelIndex);
        static winrt::Windows::Foundation::IAsyncOperation<hstring> RemoteShowPurchaseAsync(hstring xuid, hstring productId, hstring desiredItemTypes, hstring name, hstring extendedJsonData, hstring cv, winrt::Windows::Xbox::UI::RemotedPurchaseScenarioType scenario);
        static winrt::Windows::Foundation::IAsyncAction RemoteShowApplicationAsync(hstring uri);
        static winrt::Windows::Foundation::IAsyncOperation<bool> RemoteShowTimerExtensionAsync(hstring appId, uint32_t minutesLeft, bool isAppBlocked);
        static void SetCloudStreamingServiceForTest(winrt::Windows::Foundation::IInspectable const& cloudStreamingService);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::UI::PrivilegeCheckResult> RemoteCheckPrivilegesAsync(winrt::Windows::Xbox::System::User user, winrt::Windows::Foundation::Collections::IVectorView<uint32_t> privilegeIds, bool attemptResolution, hstring friendlyDisplay);
        static winrt::Windows::Foundation::IAsyncAction RemoteShowProfileCardAsync(winrt::Windows::Xbox::System::User requestingUser, hstring targetXuid);
        static winrt::Windows::Foundation::IAsyncAction RemoteLaunchAchievementsAsync(winrt::Windows::Xbox::System::User requestingUser, uint32_t titleId);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::UI::AddRemoveFriendResult> RemoteAddRemoveFriendAsync(winrt::Windows::Xbox::System::User requestingUser, hstring targetUserId);
        static winrt::Windows::Foundation::IAsyncAction RemoteLaunchPartyAsync(winrt::Windows::Xbox::System::User requestingUser, winrt::Windows::Foundation::Collections::IVectorView<hstring> inviteUserIdList);
        static winrt::Windows::Foundation::IAsyncAction RemoteShowComposeMessageAsync(winrt::Windows::Xbox::System::User requestingUser, hstring defaultMessageText, winrt::Windows::Foundation::Collections::IVector<hstring> recipientUserIdList);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<hstring>> RemotePeoplePickerAsync(winrt::Windows::Xbox::System::User requestingUser, hstring promptText, winrt::Windows::Foundation::Collections::IVectorView<hstring> selectFromXuidList, winrt::Windows::Foundation::Collections::IVectorView<hstring> preselectedXuidList, uint32_t minimumSelectionCount, uint32_t maximumSelectionCount);
        static bool ShouldRemoteAllProtocolActivations();
        static bool ShouldBlockMultipleTCUIClientTransactions();
        static winrt::Windows::Foundation::IAsyncAction RemoteShowFeedbackAsync();
        static winrt::Windows::Foundation::IAsyncAction RemoteShowMicrophoneSettingsAsync();
        static winrt::Windows::Foundation::IAsyncAction RemoteToggleMuteAsync();
        static winrt::Windows::Foundation::IAsyncOperation<bool> RemoteShowPrivilegeBlockedAsync(winrt::Windows::Xbox::System::User user, uint32_t privilegeId, uint32_t titleId, winrt::Windows::Foundation::Collections::IPropertySet customOptions);
        static winrt::Windows::Foundation::IAsyncAction RemoteShowGameTimeAsync(hstring aumid, uint32_t notificationType, uint32_t secondsLeft, bool canRequestMoreTime, bool suppressNotification);
        static winrt::Windows::Foundation::IAsyncAction RemoteShowSendInvitesAsync(winrt::Windows::Xbox::System::User requestingUser);
        static winrt::Windows::Foundation::IAsyncAction RemoteShowSendGameInvitesAsync(winrt::Windows::Xbox::System::User requestingUser, winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference sessionReferenceToInviteTo, hstring inviteDisplayTextId, hstring customActivationContext);
        static winrt::Windows::Foundation::IAsyncAction RemoteShowSendMultiplayerActivityInvitesAsync(winrt::Windows::Xbox::System::User requestingUser, uint32_t titleId);
        static winrt::Windows::Foundation::IAsyncAction RemoteShowStateShareAsync(winrt::Windows::Xbox::System::User requestingUser, uint32_t xblTitleId, hstring linkToken);
    };
}
namespace winrt::Windows::Xbox::UI::factory_implementation
{
    struct CloudStreamingSystemUI : CloudStreamingSystemUIT<CloudStreamingSystemUI, implementation::CloudStreamingSystemUI>
    {
    };
}
