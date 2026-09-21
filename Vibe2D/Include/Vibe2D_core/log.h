#pragma once


#include "core.h"
#include <spdlog/spdlog.h>

namespace Vibe2D{

class VIBE2D_API Log
{
    public:
        static void Init(); // Sets up coloring rules, formatting patterns, and logging streams

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;

};

}

    // Engine Core Logger Macros
#define VIBE2D_CORE_TRACE(...)    ::Vibe2D::Log::GetCoreLogger()->trace(__VA_ARGS__) //put our macro(...) to actual function(va args)
#define VIBE2D_CORE_INFO(...)     ::Vibe2D::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VIBE2D_CORE_WARN(...)     ::Vibe2D::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VIBE2D_CORE_ERROR(...)    ::Vibe2D::Log::GetCoreLogger()->error(__VA_ARGS__)

    // Client Game Logger Macros
#define VIBE2D_TRACE(...)         ::Vibe2D::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VIBE2D_INFO(...)          ::Vibe2D::Log::GetClientLogger()->info(__VA_ARGS__)
#define VIBE2D_WARN(...)          ::Vibe2D::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VIBE2D_ERROR(...)         ::Vibe2D::Log::GetClientLogger()->error(__VA_ARGS__)

