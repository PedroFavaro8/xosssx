#pragma once
#include <d3d11.h>
#include <dxgi1_2.h>
#include "exports.h"

namespace wd::common
{
    class WD_API GUI
    {
    public:
        void Initialize(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, IDXGISwapChain1* pSwapchain);

        void Render();
    private:
        void XBNotif(const char* notif_text = "Game Ready", const char* icon = "\xEE\x9F\xBC", const char* bottom_tip = "Hold \xEE\xBB\x8A to Launch");
        ID3D11Device* m_pDevice = nullptr;
        ID3D11DeviceContext* m_pContext = nullptr;
        IDXGISwapChain1* m_pSwapchain = nullptr;
        ID3D11RenderTargetView* m_pRenderTargetView;
        float xbnotif_timer = 5.0f;
        bool xbnotif_show = true;
    };
}