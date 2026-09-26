#pragma once
#include "d3d11_x.g.h"

template <abi_t ABI> class DXGIDevice2 : public gfx::IDXGIDevice2<ABI>
{
public:
    IDXGIDevice2 *m_pFunction{};
    DXGIDevice2(::IDXGIDevice2 *pDevice)
    {
        m_pFunction = pDevice;
        if (this->m_RefCount != 0)
            this->m_RefCount = 0;
        InterlockedIncrement(&this->m_RefCount);
    }

    //
    // IUnknown
    //
    HRESULT QueryInterface(REFIID riid, void **ppvObject);
    ULONG AddRef();
    ULONG Release();

    //
    // IDXGIObject
    //
    HRESULT SetPrivateData(GUID const &Name, uint32_t DataSize, void const *pData);
    HRESULT SetPrivateDataInterface(GUID const &Name, IUnknown const *pUnknown);
    HRESULT SetPrivateDataInterfaceGraphics(_GUID const &Name, xbox::IGraphicsUnknown<ABI> const *pData);
    HRESULT GetPrivateData(_GUID const &Name, UINT *pDataSize, void *pData);
    HRESULT GetParent(_GUID const &riid, void **ppParent);

    //
    // IDXGIDevice
    //
    HRESULT GetAdapter(gfx::IDXGIAdapter<ABI> **pAdapter);
    HRESULT CreateSurface(DXGI_SURFACE_DESC const *pDesc, uint32_t NumSurfaces, DXGI_USAGE Usage,
                          DXGI_SHARED_RESOURCE const *pSharedResource, IDXGISurface **ppSurface);
    HRESULT QueryResourceResidency(xbox::IGraphicsUnknown<ABI> **ppResources, DXGI_RESIDENCY *pResidencyStatus,
                                   uint32_t NumResources);
    HRESULT SetGPUThreadPriority(int Priority);
    HRESULT GetGPUThreadPriority(int *pPriority);

    //
    // IDXGIDevice1
    //
    HRESULT SetMaximumFrameLatency(uint32_t MaxLatency);
    HRESULT GetMaximumFrameLatency(uint32_t *pMaxLatency);

    //
    // IDXGIDevice2
    //
    HRESULT OfferResources(uint32_t NumResources, IDXGIResource *const *ppResources,
                           DXGI_OFFER_RESOURCE_PRIORITY Priority);
    HRESULT ReclaimResources(uint32_t NumResources, IDXGIResource *const *ppResources, bool *pDiscarded);
    HRESULT EnqueueSetEvent(void *hEvent);
};

#undef ABI_INTERFACE
#define ABI_INTERFACE(ABI) DXGIDevice2<ABI>
D3D11_DECLARE_ABI_TEMPLATES(extern);