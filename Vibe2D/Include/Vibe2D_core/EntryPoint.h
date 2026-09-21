#pragma once
#include "Vibe2D_core/Core.h"
#include "Vibe2D_core/Application.h"
#include "Vibe2D_core/log.h"

#ifdef VIBE2D_PLATFORM_WINDOWS

namespace Vibe2D{
extern Application* CreateApplication();
}

int main(int argc, char** argv)
{
   
    Vibe2D::Log::Init();
   VIBE2D_CORE_WARN("Logging System Initialized! ");
//int a=11;
  VIBE2D_INFO("Welcome to Vibe2D Physics Engine!");

    auto app = Vibe2D::CreateApplication();
    app->Run();
    delete app;

    return 0;
}

#endif
