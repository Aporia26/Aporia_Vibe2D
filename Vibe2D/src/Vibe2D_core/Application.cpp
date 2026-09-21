#include "vibepch.h"

#include "Vibe2D_core/Application.h"
#include "Vibe2D_core/log.h"
#include "Events/ApplicationEvent.h"
#include "GLFW/glfw3.h"

namespace Vibe2D{

void Application::OnEvent(Event& e)
    {
        // Simple placeholder: We just log the event text to verify it's working!
        VIBE2D_CORE_TRACE("{}", e.ToString());
    }


Application::Application()
{
    m_Window = std::unique_ptr<Window>(Window::Create());

    // This maps the window's internal functional callback variable straight to our OnEvent handler.
    // It prevents the 'std::bad_function_call' crash by ensuring the pointer is never empty!
     m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
}
Application::~Application()
{

}

void Application::Run()
{
    while(m_Running)
    {
        glClearColor(0.2f,0.2f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        m_Window->OnUpdate();

    }
}

}