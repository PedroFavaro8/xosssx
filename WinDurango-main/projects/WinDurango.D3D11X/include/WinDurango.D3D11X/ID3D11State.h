#pragma once
#include "d3d11_x.g.h"

template <abi_t ABI> class D3D11SamplerState : public gfx::ID3D11SamplerState<ABI>
{
  public:
    ID3D11SamplerState *m_pFunction = nullptr;

    D3D11SamplerState(ID3D11SamplerState *pState)
    {
        m_pFunction = pState;
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
    // ID3D11DeviceChild
    //
    void GetDevice(gfx::ID3D11Device<ABI> **ppDevice);
    HRESULT GetPrivateData(_GUID const &guid, uint32_t *pDataSize, void *pData);
    HRESULT SetPrivateData(_GUID const &guid, uint32_t DataSize, void const *pData);
    HRESULT SetPrivateDataInterface(_GUID const &guid, IUnknown const *pData);
    HRESULT SetPrivateDataInterfaceGraphics(_GUID const &guid, xbox::IGraphicsUnknown<ABI> const *pData);
    HRESULT SetName(LPCWSTR pName)
    {
        return S_OK;
    }

    //
    // ID3D11SamplerState
    //
    void GetDesc(D3D11_SAMPLER_DESC *pDesc);
    void GetDescX(gfx::D3D11X_SAMPLER_DESC *pDesc);
};

#undef ABI_INTERFACE
#define ABI_INTERFACE(ABI) D3D11SamplerState<ABI>
D3D11_DECLARE_ABI_TEMPLATES(extern);

template <abi_t ABI> class D3D11RasterizerState : public gfx::ID3D11RasterizerState<ABI>
{
  public:
    ID3D11RasterizerState *m_pFunction = nullptr;

    D3D11RasterizerState(ID3D11RasterizerState *pState)
    {
        m_pFunction = pState;
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
    // ID3D11DeviceChild
    //
    void GetDevice(gfx::ID3D11Device<ABI> **ppDevice);
    HRESULT GetPrivateData(_GUID const &guid, uint32_t *pDataSize, void *pData);
    HRESULT SetPrivateData(_GUID const &guid, uint32_t DataSize, void const *pData);
    HRESULT SetPrivateDataInterface(_GUID const &guid, IUnknown const *pData);
    HRESULT SetPrivateDataInterfaceGraphics(_GUID const &guid, xbox::IGraphicsUnknown<ABI> const *pData);
    HRESULT SetName(LPCWSTR pName)
    {
        return S_OK;
    }

    //
    // ID3D11RasterizerState
    //
    void GetDesc(D3D11_RASTERIZER_DESC *pDesc);
};

#undef ABI_INTERFACE
#define ABI_INTERFACE(ABI) D3D11RasterizerState<ABI>
D3D11_DECLARE_ABI_TEMPLATES(extern);

template <abi_t ABI> class D3D11BlendState : public gfx::ID3D11BlendState<ABI>
{
  public:
    ID3D11BlendState *m_pFunction = nullptr;

    D3D11BlendState(ID3D11BlendState *pState)
    {
        m_pFunction = pState;
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
    // ID3D11DeviceChild
    //
    void GetDevice(gfx::ID3D11Device<ABI> **ppDevice);
    HRESULT GetPrivateData(_GUID const &guid, uint32_t *pDataSize, void *pData);
    HRESULT SetPrivateData(_GUID const &guid, uint32_t DataSize, void const *pData);
    HRESULT SetPrivateDataInterface(_GUID const &guid, IUnknown const *pData);
    HRESULT SetPrivateDataInterfaceGraphics(_GUID const &guid, xbox::IGraphicsUnknown<ABI> const *pData);
    HRESULT SetName(LPCWSTR pName)
    {
        return S_OK;
    }

    //
    // ID3D11BlendState
    //
    void GetDesc(D3D11_BLEND_DESC *pDesc);
};

#undef ABI_INTERFACE
#define ABI_INTERFACE(ABI) D3D11BlendState<ABI>
D3D11_DECLARE_ABI_TEMPLATES(extern);

template <abi_t ABI> class D3D11DepthStencilState : public gfx::ID3D11DepthStencilState<ABI>
{
  public:
    ID3D11DepthStencilState *m_pFunction = nullptr;

    D3D11DepthStencilState(ID3D11DepthStencilState *pState)
    {
        m_pFunction = pState;
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
    // ID3D11DeviceChild
    //
    void GetDevice(gfx::ID3D11Device<ABI> **ppDevice);
    HRESULT GetPrivateData(_GUID const &guid, uint32_t *pDataSize, void *pData);
    HRESULT SetPrivateData(_GUID const &guid, uint32_t DataSize, void const *pData);
    HRESULT SetPrivateDataInterface(_GUID const &guid, IUnknown const *pData);
    HRESULT SetPrivateDataInterfaceGraphics(_GUID const &guid, xbox::IGraphicsUnknown<ABI> const *pData);
    HRESULT SetName(LPCWSTR pName)
    {
        return S_OK;
    }

    //
    // ID3D11DepthStencilState
    //
    void GetDesc(D3D11_DEPTH_STENCIL_DESC *pDesc);
    void GetDescX(D3D11_DEPTH_STENCIL_DESC *pDesc);
};

#undef ABI_INTERFACE
#define ABI_INTERFACE(ABI) D3D11DepthStencilState<ABI>
D3D11_DECLARE_ABI_TEMPLATES(extern);