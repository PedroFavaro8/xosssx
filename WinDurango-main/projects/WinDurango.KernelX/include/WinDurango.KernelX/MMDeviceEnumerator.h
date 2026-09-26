#pragma once
#include <mmdeviceapi.h>

class MMDeviceEnumeratorWrapper : IMMDeviceEnumerator
{
  public:
    MMDeviceEnumeratorWrapper(IMMDeviceEnumerator *realEnumerator) : m_realEnumerator(realEnumerator)
    {
        AddRef();
    }

    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, _COM_Outptr_ void __RPC_FAR *__RPC_FAR *ppvObject) override;
    ULONG STDMETHODCALLTYPE AddRef(void) override;
    ULONG STDMETHODCALLTYPE Release(void) override;

    /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumAudioEndpoints(
        /* [annotation][in] */
        _In_ EDataFlow dataFlow,
        /* [annotation][in] */
        _In_ DWORD dwStateMask,
        /* [annotation][out] */
        _Out_ IMMDeviceCollection **ppDevices) override;

    /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDefaultAudioEndpoint(
        /* [annotation][in] */
        _In_ EDataFlow dataFlow,
        /* [annotation][in] */
        _In_ ERole role,
        /* [annotation][out] */
        _Out_ IMMDevice **ppEndpoint) override;

    /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice(
        /* [annotation][in] */
        _In_ LPCWSTR pwstrId,
        /* [annotation][out] */
        _Out_ IMMDevice **ppDevice) override;

    /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RegisterEndpointNotificationCallback(
        /* [annotation][in] */
        _In_ IMMNotificationClient *pClient) override;

    /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnregisterEndpointNotificationCallback(

        /* [annotation][in] */
        _In_ IMMNotificationClient *pClient) override;

    IMMDeviceEnumerator *m_realEnumerator;
    ULONG m_RefCount = 0;
};

MIDL_INTERFACE("8B557ADC-555E-47A0-B223-43477E481DAD")
IMMXboxDeviceEnumerator : public IMMDeviceEnumerator
{
  public:
    virtual HRESULT STDMETHODCALLTYPE GetHdAudioChannelCounts(UINT * pHdmiChannelCount, UINT * pSpdifChannelCount) = 0;
    virtual HRESULT STDMETHODCALLTYPE RegisterChannelCountNotificationCallback(UINT * pClient) = 0;
    virtual HRESULT STDMETHODCALLTYPE UnregisterChannelCountNotificationCallback(UINT * pClient) = 0;
};

class MMXboxDeviceEnumerator : IMMXboxDeviceEnumerator
{
  public:
    MMXboxDeviceEnumerator(IMMDeviceEnumerator *realEnumerator) : m_realEnumerator(realEnumerator)
    {
        AddRef();
    }

    HRESULT STDMETHODCALLTYPE QueryInterface(
        /* [in] */ REFIID riid,
        /* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR *__RPC_FAR *ppvObject) override;

    ULONG STDMETHODCALLTYPE AddRef(void) override;
    ULONG STDMETHODCALLTYPE Release(void) override;

    /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumAudioEndpoints(
        /* [annotation][in] */
        _In_ EDataFlow dataFlow,
        /* [annotation][in] */
        _In_ DWORD dwStateMask,
        /* [annotation][out] */
        _Out_ IMMDeviceCollection **ppDevices) override;

    /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDefaultAudioEndpoint(
        /* [annotation][in] */
        _In_ EDataFlow dataFlow,
        /* [annotation][in] */
        _In_ ERole role,
        /* [annotation][out] */
        _Out_ IMMDevice **ppEndpoint) override;

    /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice(
        /* [annotation][in] */
        _In_ LPCWSTR pwstrId,
        /* [annotation][out] */
        _Out_ IMMDevice **ppDevice) override;

    /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RegisterEndpointNotificationCallback(
        /* [annotation][in] */
        _In_ IMMNotificationClient *pClient) override;

    /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnregisterEndpointNotificationCallback(
        /* [annotation][in] */
        _In_ IMMNotificationClient *pClient) override;

    HRESULT __stdcall GetHdAudioChannelCounts(UINT *pHdmiChannelCount, UINT *pSpdifChannelCount) override;
    HRESULT __stdcall RegisterChannelCountNotificationCallback(UINT *pClient) override;
    HRESULT __stdcall UnregisterChannelCountNotificationCallback(UINT *pClient) override;

    IMMDeviceEnumerator *m_realEnumerator;
    ULONG m_RefCount = 0;
};