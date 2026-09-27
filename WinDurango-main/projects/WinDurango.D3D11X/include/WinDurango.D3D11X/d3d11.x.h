#pragma once
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "version.lib")
#include "unknown.g.h"
#include "xcom/base.h"
#include <Windows.h>
#include <bitset>
#include <d3d11_4.h>
#include <dxgi1_6.h>
#include <map>
#include <mutex>
#include <algorithm>
#include <cstdint>
#include <DirectXTex.h>
#include "WinDurango.Common/WinDurango.h"
#include "WinDurango.Common/CompatOSVersion.h"

extern std::shared_ptr<wd::common::WinDurango> p_wd;

// We use that to know the OS version.
abi_t g_ABI{};

// Immediate Context fence object.
BOOL m_Fence = TRUE;

// Multimap for placement update
std::multimap<void*, void *> g_ResourceMap;
std::mutex g_ResourceMapMutex;

#pragma comment(lib, "onecore.lib")
#pragma comment(lib, "kernel32.lib")

void GetCombaseVersion()
{
    // Versao vinda do Windows host (ou fallback documentado); nao exige
    // imagem de sistema do console e nao abre dialogo em DllMain.
    const wd::common::CompatOSVersion version = wd::common::ResolveCompatOSVersion();
    g_ABI.Major = version.major;
    g_ABI.Minor = version.minor;
    g_ABI.Build = version.build;
    g_ABI.Revision = version.revision;
}

inline void CalculatePitch(uint32_t Width, uint32_t Height, DXGI_FORMAT Format, uint32_t* pRowPitch, uint32_t* pSlicePitch)
{;
    SIZE_T rowPitch = 0;
    SIZE_T slicePitch = 0;
    DirectX::ComputePitch(Format, Width, Height, rowPitch, slicePitch);

    (*pRowPitch) = rowPitch;
    (*pSlicePitch) = slicePitch;
}

inline bool IsFloatFormat(DXGI_FORMAT Format)
{
    switch (Format)
    {
    case DXGI_FORMAT_R32G32B32A32_FLOAT:
    case DXGI_FORMAT_R32G32B32_FLOAT:
    case DXGI_FORMAT_R16G16B16A16_FLOAT:
    case DXGI_FORMAT_R32G32_FLOAT:
    case DXGI_FORMAT_R11G11B10_FLOAT:
    case DXGI_FORMAT_R16G16_FLOAT:
    case DXGI_FORMAT_R32_FLOAT:
    case DXGI_FORMAT_R16_FLOAT:
        return true;
    default:
        return false;
    }
}

inline bool IsUINTFormat(DXGI_FORMAT Format)
{
    switch (Format)
    {
    case DXGI_FORMAT_R32G32B32A32_UINT:
    case DXGI_FORMAT_R32G32B32_UINT:
    case DXGI_FORMAT_R16G16B16A16_UINT:
    case DXGI_FORMAT_R32G32_UINT:
    case DXGI_FORMAT_R10G10B10A2_UINT:
    case DXGI_FORMAT_R16G16_UINT:
    case DXGI_FORMAT_R32_UINT:
    case DXGI_FORMAT_R16_UINT:
    case DXGI_FORMAT_R8G8B8A8_UINT:
    case DXGI_FORMAT_R8G8_UINT:
    case DXGI_FORMAT_R8_UINT:
        return true;
    default:
        return false;
    }
}

inline bool IsUnormFormat(DXGI_FORMAT Format)
{
    switch (Format)
    {
    case DXGI_FORMAT_R16G16B16A16_UNORM:
    case DXGI_FORMAT_R10G10B10A2_UNORM:
    case DXGI_FORMAT_R8G8B8A8_UNORM:
    case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
    case DXGI_FORMAT_R16G16_UNORM:
    case DXGI_FORMAT_R8G8_UNORM:
    case DXGI_FORMAT_R16_UNORM:
    case DXGI_FORMAT_R8_UNORM:
    case DXGI_FORMAT_A8_UNORM:
    case DXGI_FORMAT_R1_UNORM:
    case DXGI_FORMAT_R8G8_B8G8_UNORM:
    case DXGI_FORMAT_G8R8_G8B8_UNORM:
    case DXGI_FORMAT_B8G8R8A8_UNORM:
        return true;
    default:
        return false;
    }
}

inline bool IsTypelessFormat(DXGI_FORMAT Format)
{
    switch (Format)
    {
    case DXGI_FORMAT_R32G32B32A32_TYPELESS:
    case DXGI_FORMAT_R32G32B32_TYPELESS:
    case DXGI_FORMAT_R16G16B16A16_TYPELESS:
    case DXGI_FORMAT_R32G32_TYPELESS:
    case DXGI_FORMAT_R32G8X24_TYPELESS:
    case DXGI_FORMAT_R10G10B10A2_TYPELESS:
    case DXGI_FORMAT_R8G8B8A8_TYPELESS:
    case DXGI_FORMAT_R16G16_TYPELESS:
    case DXGI_FORMAT_R32_TYPELESS:
    case DXGI_FORMAT_R24G8_TYPELESS:
    case DXGI_FORMAT_R8G8_TYPELESS:
    case DXGI_FORMAT_R16_TYPELESS:
    case DXGI_FORMAT_R8_TYPELESS:
    case DXGI_FORMAT_BC1_TYPELESS:
    case DXGI_FORMAT_BC2_TYPELESS:
    case DXGI_FORMAT_BC3_TYPELESS:
    case DXGI_FORMAT_BC4_TYPELESS:
    case DXGI_FORMAT_BC5_TYPELESS:
    case DXGI_FORMAT_BC6H_TYPELESS:
    case DXGI_FORMAT_BC7_TYPELESS:
    case DXGI_FORMAT_B8G8R8A8_TYPELESS:
    case DXGI_FORMAT_B8G8R8X8_TYPELESS:
        return true;
    default:
        return false;
    }
}
