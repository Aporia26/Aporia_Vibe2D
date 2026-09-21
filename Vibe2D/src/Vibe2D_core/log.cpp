#include "vibepch.h"

#include "Vibe2D_core/log.h"
#include <spdlog/sinks/stdout_color_sinks.h> // Handles custom color patterns inside OS terminals


namespace Vibe2D{

     // Allocate the smart pointers sitting inside static memory pool locations
    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init()
    {
        // Set standard colored print tracking format patterns:
                    // [Timestamp] [LoggerName]: Message
        spdlog::set_pattern("%^[%T] %n: %v%$");

        // 1. Initialize your internal Engine Logger
        s_CoreLogger = spdlog::stdout_color_mt("VIBE2D");
        s_CoreLogger->set_level(spdlog::level::trace);
        
        // 2. Initialize your Sandbox Client Game Logger
        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }


}