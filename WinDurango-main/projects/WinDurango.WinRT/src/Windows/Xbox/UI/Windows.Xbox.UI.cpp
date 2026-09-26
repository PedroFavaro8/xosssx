#include "Windows.Xbox.UI.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::UI::implementation
{
    winrt::Windows::Xbox::UI::FirmwareUpdateStatus FirmwareUpdateResult::Status()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: Status");
        throw hresult_not_implemented();
    }
    uint64_t FirmwareUpdateResult::ControllerIdUpdated()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: ControllerIdUpdated");
        throw hresult_not_implemented();
    }
    bool NetworkTroubleshooterResult::ConnectedToLive()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: ConnectedToLive");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IPropertySet NetworkTroubleshooterResult::AllResults()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: AllResults");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::UI::ShareContentDestination ShareContentResult::Destination()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: Destination");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::System::User SignUpResult::User()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: User");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IPropertySet SignUpResult::Properties()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: Properties");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::System::User SignUpResult::SystemUser()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::UI", "Unimplemented: SystemUser");
        throw hresult_not_implemented();
    }
}
