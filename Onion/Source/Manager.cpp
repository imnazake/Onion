#include "Global.h"

void Manager::Initialize()
{
    Data::CurrentWindow = new MainWindow();
}

void Manager::SetNextSize(const float Width, const float Height)
{
    Data::NextSizeX = Width;
    Data::NextSizeY = Height;
}

void Manager::ClearWindow()
{
    delete Data::CurrentWindow;
}

void Manager::SwitchWindow(WindowBase* NewWindow)
{
    Data::CurrentWindow = NewWindow;
}

void Manager::Render()
{
    const ImVec2 WindowSize = { Data::NextSizeX, Data::NextSizeY };
    //ImGui::SetNextWindowSize(WindowSize);
    ImGui::SetNextWindowPos({ GetSystemMetrics(SM_CXSCREEN) / 2 - WindowSize.x / 2, GetSystemMetrics(SM_CYSCREEN) / 2 - WindowSize.y / 2 }, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowBgAlpha(1.0f);

    constexpr ImGuiWindowFlags WindowFlags = ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize;
    static bool bDraw = true;
    ImGui::Begin("  ", &bDraw, WindowFlags);

    Data::CurrentWindow->Render();

    ImGui::End();

    if (!bDraw)
        Global::bRequestingExit = true;
}