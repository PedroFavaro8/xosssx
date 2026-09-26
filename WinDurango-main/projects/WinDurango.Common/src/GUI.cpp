#include <backends/imgui_impl_dx11.h>
#include <imgui_impl_uwp.h>
#include <imgui.h>
#include "GUI.h"

namespace wd::common
{    
    void GUI::Initialize(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, IDXGISwapChain1* pSwapchain)
    {
        m_pDevice = pDevice;
        m_pContext = pContext;
        m_pSwapchain = pSwapchain;
        ID3D11Texture2D* pBackBuffer = nullptr;
        m_pSwapchain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
        m_pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &m_pRenderTargetView);
        if (pBackBuffer) pBackBuffer->Release();

        ImGui::CreateContext();

        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.IniFilename = "imgui.ini";
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        ImFont* mainFont = io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/Bahnschrift.ttf", 18.0f);

        ImFontConfig config;
        config.MergeMode = true;
        config.GlyphOffset.y = 4.0f;

        static const ImWchar icon_ranges[] = { 0xE7FC, 0xF11B, 0 };
        static const ImWchar icon_ranges2[] = { 0xE782, 0xE782, 0 };
        static const ImWchar icon_ranges3[] = { 0xE2AF, 0xE2AF, 0 };
        io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\segmdl2.ttf", 18.0f, &config, icon_ranges);
        io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\segmdl2.ttf", 30.0f, &config, icon_ranges3);
        io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\segmdl2.ttf", 30.0f, &config, icon_ranges2);

        ImGui_ImplUwp_InitForCurrentView();
        ImGui_ImplDX11_Init(m_pDevice, m_pContext);
    }

    void GUI::Render()
    {
        ImGui_ImplDX11_NewFrame();
        //ImGui_ImplUwp_NewFrame(); //technically we use a HWND swap chain so this isn't needed? (breaks Forza Motorsport 5 and doesn't seems to make a difference)

        ID3D11Texture2D* pBackBuffer = nullptr;
        m_pSwapchain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
        if (pBackBuffer)
        {
            D3D11_TEXTURE2D_DESC desc;
            pBackBuffer->GetDesc(&desc);
            ImGui::GetIO().DisplaySize = ImVec2((float)desc.Width, (float)desc.Height);
            pBackBuffer->Release();
        }

        ImGui::NewFrame();

        if (xbnotif_show) {
            xbnotif_timer -= ImGui::GetIO().DeltaTime;
            if (xbnotif_timer <= 0.0f) 
            {
                xbnotif_timer = false;
            } else /* IDK, but is this how the code should be structured?? */
            {
                float alpha = xbnotif_timer < 1.0f ? xbnotif_timer : 1.0f;
                ImGui::PushStyleVar(ImGuiStyleVar_Alpha, alpha);
                XBNotif();
                ImGui::PopStyleVar();
            }
        }

        ImGui::Render();
        m_pContext->OMSetRenderTargets(1, &m_pRenderTargetView, nullptr);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    }

    void GUI::XBNotif(const char* notif_text, const char* icon, const char* bottom_tip) 
    {
        ImVec4 tipColor = ImVec4(64.0f/255.0f, 158.0f/255.0f, 254.0f/255.0f, 1.0f);
        ImVec4 color = ImVec4(38/255.0f, 145/255.0f, 253/255.0f, 1.0f);
        ImGuiWindowFlags flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoDecoration;
        
        ImGuiViewport* vp = ImGui::GetMainViewport();

        ImVec2 windowPos;
        windowPos.x = ImGui::GetIO().DisplaySize.x * 0.5f;
        windowPos.y = ImGui::GetIO().DisplaySize.y * 0.95f;

        ImGui::SetNextWindowPos(windowPos, ImGuiCond_Always, ImVec2(0.5f, 1.0f));

        ImGui::PushStyleColor(ImGuiCol_WindowBg, tipColor);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 3.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(12, 12)); 
        ImGui::SetNextWindowSize(ImVec2(370, 60));

        ImGui::Begin("NotificationTip", nullptr, flags);
        
        ImVec2 pos = ImGui::GetWindowPos();

        ImVec2 p = ImGui::GetCursorScreenPos();
        float size = 38.0f;

        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        draw_list->AddRectFilled(p, ImVec2(p.x + size, p.y + size), IM_COL32(31, 73, 117, 255));

        const char* text = icon;
        ImVec2 text_size = ImGui::CalcTextSize(text);
        ImVec2 text_pos = ImVec2(
            p.x + (size - text_size.x) / 2, 
            p.y + (size - text_size.y) / 2
        );
        draw_list->AddText(text_pos, IM_COL32(255, 255, 255, 255), text);

        ImVec2 notif_pos = ImVec2(
            text_pos.x + 40, 
            text_pos.y
        );
        draw_list->AddText(notif_pos, IM_COL32(255, 255, 255, 255), notif_text);

        ImGui::End();

        ImGui::PopStyleColor();
        ImGui::PopStyleVar(3);

        float windowEndY = pos.y + 50;

        ImGui::SetNextWindowPos({pos.x, windowEndY});
        ImGui::PushStyleColor(ImGuiCol_WindowBg, color);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 3.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(15, 15)); 
        ImGui::SetNextWindowSize(ImVec2(370, 40));

        ImGui::Begin("Notification", nullptr, flags);
        
        ImGui::Text(bottom_tip);

        ImGui::End();

        ImGui::PopStyleColor();
        ImGui::PopStyleVar(3);
    }
}