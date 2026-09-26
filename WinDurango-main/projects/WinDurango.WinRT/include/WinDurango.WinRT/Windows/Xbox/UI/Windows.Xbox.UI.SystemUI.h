#pragma once
#include "Windows.Xbox.UI.WebAuthenticationResult.g.h"
#include "Windows.Xbox.UI.SystemUI.g.h"

namespace winrt::Windows::Xbox::UI::implementation
{
    struct WebAuthenticationResult : WebAuthenticationResultT<WebAuthenticationResult>
    {
        WebAuthenticationResult() = default;

        hstring ResponseData();
        winrt::Windows::Xbox::UI::WebAuthenticationStatus ResponseStatus();
        uint32_t ResponseErrorDetail();
    };
    
    struct SystemUI
    {
        SystemUI() = default;

        static winrt::Windows::Foundation::IAsyncAction ShowEpgAsync(winrt::Windows::Xbox::System::User requestingUser, winrt::Windows::Foundation::Collections::IIterable<winrt::Windows::Foundation::Collections::IKeyValuePair<hstring, winrt::Windows::Foundation::IInspectable>> propertySet);
        static winrt::Windows::Foundation::IAsyncAction ShowMiniguideAsync(winrt::Windows::Xbox::System::User requestingUser);
        static winrt::Windows::Foundation::IAsyncAction ShowProfileCardAsync(winrt::Windows::Xbox::System::User requestingUser, hstring targetXuid);
        static winrt::Windows::Foundation::IAsyncAction ShowSendInvitesAsync(winrt::Windows::Xbox::System::User requestingUser);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::UI::AccountPickerResult> ShowAccountPickerAsync(winrt::Windows::Xbox::Input::Controller controller, winrt::Windows::Xbox::UI::AccountPickerOptions options);
        static winrt::Windows::Foundation::IAsyncOperation<hstring> ShowVirtualKeyboardAsync(hstring defaultText, hstring titleText, hstring descriptionText, winrt::Windows::Xbox::UI::VirtualKeyboardInputScope inputScope);
        static winrt::Windows::Foundation::IAsyncAction LaunchPartyAsync(winrt::Windows::Xbox::System::User requestingUser);
        static winrt::Windows::Foundation::IAsyncAction LaunchAchievementsAsync(winrt::Windows::Xbox::System::User requestingUser, uint32_t titleId);
        static winrt::Windows::Foundation::IAsyncAction ShowPartyAndSendPartyInvitesAsync(winrt::Windows::Xbox::System::User requestingUser, winrt::Windows::Foundation::Collections::IVectorView<hstring> recipientUserIdList);
        static winrt::Windows::Foundation::IAsyncAction ShowCreateLookingForGroupAsync(winrt::Windows::Xbox::System::User requestingUser, winrt::Windows::Foundation::Collections::IVectorView<hstring> preselectedTags, hstring preselectedDescription, uint32_t defaultNeedCount);
        static winrt::Windows::Foundation::IAsyncAction ShowUserLookingForGroupsAsync(winrt::Windows::Xbox::System::User requestingUser);
        static winrt::Windows::Foundation::IAsyncAction ShowLookingForGroupResultsAsync(winrt::Windows::Xbox::System::User requestingUser, winrt::Windows::Foundation::Collections::IVectorView<hstring> tags);
        static winrt::Windows::Foundation::IAsyncAction ShowSendMultiplayerActivityGameInvites(winrt::Windows::Xbox::System::User requestingUser, uint32_t titleId);
        static winrt::Windows::Foundation::IAsyncAction ShowStateShareAsync(winrt::Windows::Xbox::System::User requestingUser, uint32_t xblTitleId, hstring linkToken);
        static winrt::Windows::Foundation::IAsyncAction LaunchKinectSetupAsync(winrt::Windows::Xbox::System::User requestingUser);
        static winrt::Windows::Foundation::IAsyncAction LaunchRecentPlayersAsync(winrt::Windows::Xbox::System::User requestingUser);
        static winrt::Windows::Foundation::IAsyncAction SnapDefaultBroadcastApp(winrt::Windows::Xbox::System::User requestingUser);
        static winrt::Windows::Foundation::IAsyncAction ShowComposeMessageAsync(winrt::Windows::Xbox::System::User requestingUser, hstring defaultMessageText, winrt::Windows::Foundation::Collections::IVector<hstring> recipientUserIdList);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::UI::AddRemoveFriendResult> ShowAddRemoveFriendAsync(winrt::Windows::Xbox::System::User requestingUser, hstring targetUserId);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<hstring>> ShowPeoplePickerAsync(winrt::Windows::Xbox::System::User requestingUser, hstring promptText, winrt::Windows::Foundation::Collections::IVectorView<hstring> selectFromUserIdList, winrt::Windows::Foundation::Collections::IVectorView<hstring> preselectedUserIdList, uint32_t minimumSelectionCount, uint32_t maximumSelectionCount);
        static winrt::Windows::Foundation::IAsyncOperation<bool> TrySnapSelf();
        static winrt::Windows::Foundation::IAsyncOperation<bool> TrySnapOther(winrt::Windows::Foundation::Uri snapTargetUri, winrt::Windows::Xbox::System::User user);
        static winrt::Windows::Foundation::IAsyncAction ShowMiniguideWithCommandAsync(winrt::Windows::Xbox::System::User requestingUser, winrt::Windows::Xbox::UI::MiniguideCommand initialCommand);
        static winrt::Windows::Foundation::IAsyncOperation<hstring> ShowVirtualKeyboardWithOptionsAsync(winrt::Windows::Xbox::UI::KeyboardOptions options);
        static winrt::Windows::Foundation::IAsyncAction ShowSendGameInvitesAsync(winrt::Windows::Xbox::System::User requestingUser, winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference sessionReferenceToInviteTo, hstring customActivationContext);
        static winrt::Windows::Foundation::IAsyncAction ShowSendGameInvitesWithDisplayTextAsync(winrt::Windows::Xbox::System::User requestingUser, winrt::Windows::Xbox::Multiplayer::MultiplayerSessionReference sessionReferenceToInviteTo, hstring inviteDisplayTextId, hstring customActivationContext);
        static void SetNotificationPositionHint(winrt::Windows::Xbox::UI::NotificationPositionHint const& value);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::UI::WebAuthenticationResult> AuthenticateWithCallbackUriAsync(winrt::Windows::Xbox::System::User requestingUser, winrt::Windows::Xbox::UI::WebAuthenticationOptions options, winrt::Windows::Foundation::Uri requestUri, winrt::Windows::Foundation::Uri callbackUri);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::UI::WebAuthenticationResult> AuthenticateWithoutCallbackUriAsync(winrt::Windows::Xbox::System::User requestingUser, winrt::Windows::Xbox::UI::WebAuthenticationOptions options, winrt::Windows::Foundation::Uri requestUri);
        static winrt::Windows::Foundation::Uri GetCurrentApplicationCallbackUri(winrt::Windows::Xbox::System::User const& requestingUser);
    };
}
namespace winrt::Windows::Xbox::UI::factory_implementation
{
    struct SystemUI : SystemUIT<SystemUI, implementation::SystemUI>
    {
    };
}
