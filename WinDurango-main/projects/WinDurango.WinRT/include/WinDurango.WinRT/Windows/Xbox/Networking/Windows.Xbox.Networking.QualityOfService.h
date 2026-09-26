#pragma once
#include "Windows.Xbox.Networking.QualityOfServiceMeasurement.g.h"
#include "Windows.Xbox.Networking.MeasureQualityOfServiceResult.g.h"
#include "Windows.Xbox.Networking.QualityOfService.g.h"

namespace winrt::Windows::Xbox::Networking::implementation
{
    struct QualityOfServiceMeasurement : QualityOfServiceMeasurementT<QualityOfServiceMeasurement>
    {
        QualityOfServiceMeasurement() = default;

        winrt::Windows::Xbox::Networking::QualityOfServiceMeasurementStatus Status();
        winrt::Windows::Xbox::Networking::QualityOfServiceMetric Metric();
        winrt::Windows::Foundation::IPropertyValue MetricValue();
        winrt::Windows::Xbox::Networking::SecureDeviceAddress SecureDeviceAddress();
    };
    struct MeasureQualityOfServiceResult : MeasureQualityOfServiceResultT<MeasureQualityOfServiceResult>
    {
        MeasureQualityOfServiceResult() = default;

        winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Networking::QualityOfServiceMeasurement> Measurements();
        winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Networking::QualityOfServiceMeasurement> GetMeasurementsForDevice(winrt::Windows::Xbox::Networking::SecureDeviceAddress const& address);
        winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Xbox::Networking::QualityOfServiceMeasurement> GetMeasurementsForMetric(winrt::Windows::Xbox::Networking::QualityOfServiceMetric const& metric);
        winrt::Windows::Xbox::Networking::QualityOfServiceMeasurement GetMeasurement(winrt::Windows::Xbox::Networking::SecureDeviceAddress const& address, winrt::Windows::Xbox::Networking::QualityOfServiceMetric const& metric);
    };
    struct QualityOfService
    {
        QualityOfService() = default;

        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::Networking::MeasureQualityOfServiceResult> MeasureQualityOfServiceAsync(winrt::Windows::Foundation::Collections::IIterable<winrt::Windows::Xbox::Networking::SecureDeviceAddress> addresses, winrt::Windows::Foundation::Collections::IIterable<winrt::Windows::Xbox::Networking::QualityOfServiceMetric> metrics, uint32_t timeoutInMilliseconds, uint32_t numberOfProbes);
        static void PublishPrivatePayload(array_view<uint8_t const> payload);
        static void ClearPrivatePayload();
        static void ConfigureQualityOfService(uint32_t maxSimultaneousProbeConnections, bool constrainSystemBandwidthUp, bool constrainSystemBandwidthDown);
    };
}
namespace winrt::Windows::Xbox::Networking::factory_implementation
{
    struct QualityOfService : QualityOfServiceT<QualityOfService, implementation::QualityOfService>
    {
    };
}
