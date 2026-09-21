#pragma once

//macros

#ifdef VIBE2D_PLATFORM_WINDOWS
    #ifdef BUILD_DLL
        #define VIBE2D_API __declspec(dllexport)
    #else
        #define VIBE2D_API __declspec(dllimport)
    #endif
#else
   // Fallback security check so VS Code indexing never treats this macro as an incomplete type
    #define VIBE2D_API
#endif

// THE ENGINE HARD-CORE ASSERTION SUBSYSTEM 
// We only activate assertions in Debug configurations to keep your release build lightning fast!
#ifdef _DEBUG
    // #include <cassert> 
    #define VIBE2D_CORE_ASSERT(x, ...) { if(!(x)) { VIBE2D_CORE_ERROR("Assertion Failed: {}", __VA_ARGS__); __debugbreak(); } }
    #define VIBE2D_ASSERT(x, ...)      { if(!(x)) { VIBE2D_ERROR("Assertion Failed: {}", __VA_ARGS__); __debugbreak(); } }
#else
    // Strips the assertions completely out of your code during optimization builds
    #define VIBE2D_CORE_ASSERT(x, ...)
    #define VIBE2D_ASSERT(x, ...)
#endif

//Bit field Macro
// This shifts the bit '1' by X places, creating unique filter flags
#define BIT(x) (1 << x)