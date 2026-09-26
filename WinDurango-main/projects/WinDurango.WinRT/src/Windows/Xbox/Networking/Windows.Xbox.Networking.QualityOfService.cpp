#include "Windows.Xbox.Networking.QualityOfService.h"
#include "WinDurangoWinRT.h"

namespace winrt::Windows::Xbox::Networking::implementation
{
    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Networking::QualityOfServiceMeasurement> MeasureQualityOfServiceResult::Measurements()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: Measurements");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Networking::QualityOfServiceMeasurement> MeasureQualityOfServiceResult::GetMeasurementsForDevice(winrt::Windows::Xbox::Networking::SecureDeviceAddress const& address)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: GetMeasurementsForDevice");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Networking::QualityOfServiceMeasurement> MeasureQualityOfServiceResult::GetMeasurementsForMetric(winrt::Windows::Xbox::Networking::QualityOfServiceMetric const& metric)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: GetMeasurementsForMetric");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::Networking::QualityOfServiceMeasurement MeasureQualityOfServiceResult::GetMeasurement(winrt::Windows::Xbox::Networking::SecureDeviceAddress const& address, winrt::Windows::Xbox::Networking::QualityOfServiceMetric const& metric)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: GetMeasurement");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::Networking::QualityOfServiceMeasurementStatus QualityOfServiceMeasurement::Status()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: Status");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::Networking::QualityOfServiceMetric QualityOfServiceMeasurement::Metric()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: Metric");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IPropertyValue QualityOfServiceMeasurement::MetricValue()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: MetricValue");
        throw hresult_not_implemented();
    }
    winrt::Windows::Xbox::Networking::SecureDeviceAddress QualityOfServiceMeasurement::SecureDeviceAddress()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: SecureDeviceAddress");
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::Networking::MeasureQualityOfServiceResult> QualityOfService::MeasureQualityOfServiceAsync(winrt::Windows::Foundation::Collections::IIterable<winrt::Windows::Xbox::Networking::SecureDeviceAddress> addresses, winrt::Windows::Foundation::Collections::IIterable<winrt::Windows::Xbox::Networking::QualityOfServiceMetric> metrics, uint32_t timeoutInMilliseconds, uint32_t numberOfProbes)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: MeasureQualityOfServiceAsync");
        throw hresult_not_implemented();
    }
    void QualityOfService::PublishPrivatePayload(array_view<uint8_t const> payload)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: PublishPrivatePayload");
        throw hresult_not_implemented();
    }
    void QualityOfService::ClearPrivatePayload()
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: ClearPrivatePayload");
        throw hresult_not_implemented();
    }
    void QualityOfService::ConfigureQualityOfService(uint32_t maxSimultaneousProbeConnections, bool constrainSystemBandwidthUp, bool constrainSystemBandwidthDown)
    {
        p_wd->log.Warn("WinDurango::WinRT::Windows::Xbox::Networking", "Unimplemented: ConfigureQualityOfService");
        throw hresult_not_implemented();
    }
}
