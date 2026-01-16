#pragma once

class WindowBase;

namespace Manager
{
    namespace Data
    {
        inline WindowBase* CurrentWindow = nullptr;
        inline float NextSizeX = 300.0f;
        inline float NextSizeY = 300.0f;
    }

    void Initialize();
    void SetNextSize(float Width, float Height);
    void ClearWindow();
    void SwitchWindow(WindowBase* NewWindow);
    void Render();
}
