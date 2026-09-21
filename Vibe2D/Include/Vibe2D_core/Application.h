#pragma once
#include "Vibe2D_core/core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"

namespace Vibe2D{

    class VIBE2D_API Application
    {
        public: 
            Application();
   virtual ~Application(); //virtual destructor

           void Run();
        
           void OnEvent(Event& e);

        private:
            std::unique_ptr<Window> m_Window;
            bool m_Running = true;
    };

    // To be defined in CLIENT
        Application* CreateApplication();

}