#pragma once

#include "Vibe2D_core/Window.h"
#include "GLFW/glfw3.h"

namespace Vibe2D
{
    class  WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow();

        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return m_Data.Width; }
        inline unsigned int GetHieght() const override { return m_Data.Hieght; }

        //Window Attributes
        inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();
    private:
        GLFWwindow* m_Window;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Hieght;
            bool VSync;

            EventCallbackFn EventCallback;
        };
        WindowData m_Data;
    };

}