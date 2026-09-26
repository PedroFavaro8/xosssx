#pragma once
#include "d3d11_x.g.h"

template <abi_t ABI> class D3D11DeviceChild : public gfx::ID3D11DeviceChild<ABI>
{
  public:
    //
    // IUnknown
    //
    HRESULT QueryInterface(REFIID riid, void **ppvObject);
    ULONG AddRef();
    ULONG Release();

    //
    // ID3D11DeviceChild
    //
    void GetDevice(gfx::ID3D11Device<ABI> **ppDevice);
    HRESULT GetPrivateData(_GUID const &guid, uint32_t *pDataSize, void *pData);
    HRESULT SetPrivateData(_GUID const &guid, uint32_t DataSize, void const *pData);
    HRESULT SetPrivateDataInterface(_GUID const &guid, IUnknown const *pData);
    HRESULT SetPrivateDataInterfaceGraphics(_GUID const &guid, xbox::IGraphicsUnknown<ABI> const *pData);
};

#undef ABI_INTERFACE
#define ABI_INTERFACE(ABI) D3D11DeviceChild<ABI>
D3D11_DECLARE_ABI_TEMPLATES(extern);
