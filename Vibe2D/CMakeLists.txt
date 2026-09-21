cmake_minimum_required(VERSION 3.22)
project(Vibe2D_Engine LANGUAGES CXX C)

# Gather your engine headers and sources explicitly
set(ENGINE_SOURCES
    "src/vibepch.cpp"
    "src/Vibe2D_core/Application.cpp"
    "src/Vibe2D_core/Log.cpp"
    "src/Vibe2D_core/WindowsWindow.cpp"
)

# Compile third-party infrastructure (GLAD, ImGui)
add_library(Vibe2D_ThirdParty STATIC
    "${GRAPHICS_ROOT}/lib/glad.c"
    "${GRAPHICS_ROOT}/include/imgui/imgui.cpp"
    "${GRAPHICS_ROOT}/include/imgui/imgui_draw.cpp"
    "${GRAPHICS_ROOT}/include/imgui/imgui_tables.cpp"
    "${GRAPHICS_ROOT}/include/imgui/imgui_widgets.cpp"
    "${GRAPHICS_ROOT}/include/imgui/backends/imgui_impl_glfw.cpp"
    "${GRAPHICS_ROOT}/include/imgui/backends/imgui_impl_opengl3.cpp"
)
target_include_directories(Vibe2D_ThirdParty PUBLIC "${GRAPHICS_ROOT}/include")
target_include_directories(Vibe2D_ThirdParty PUBLIC "${GRAPHICS_ROOT}/include/imgui")
target_include_directories(Vibe2D_ThirdParty PUBLIC "${GRAPHICS_ROOT}/include/imgui/backends")

# Build your Engine Shared Library Target DLL
add_library(Vibe2D SHARED ${ENGINE_SOURCES})

# Forces CMake to compile Vibe2D_ThirdParty BEFORE trying to link Vibe2D
add_dependencies(Vibe2D Vibe2D_ThirdParty)

# Automatically precompiles vibepch.h and links it to all engine sources
target_precompile_headers(Vibe2D PRIVATE src/vibepch.h)

# Triggers the DLL build attributes
target_compile_definitions(Vibe2D PRIVATE BUILD_DLL)

# =========================================================================
# CRITICAL PATHING FIX: EXPOSE THE CAPITALIZED 'Include' DIRECTORY SUBTREE
# =========================================================================
target_include_directories(Vibe2D PUBLIC Include) # FIXED: Capital 'I' to match disk structure!
target_include_directories(Vibe2D PUBLIC src)
# This explicitly locks down the pathing bounds relative to your Vibe2D engine folder directory!
target_include_directories(Vibe2D PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Include")
target_include_directories(Vibe2D PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(Vibe2D PUBLIC "${GRAPHICS_ROOT}/include")
target_include_directories(Vibe2D PUBLIC "${GRAPHICS_ROOT}/include/imgui")
target_include_directories(Vibe2D PUBLIC "${GRAPHICS_ROOT}/include/imgui/backends")

target_link_directories(Vibe2D PRIVATE "${GRAPHICS_ROOT}/lib")

set(WINDOWS_DRIVERS gdi32 user32 kernel32 shell32)
set(CORE_OPENGL_LIBS Vibe2D_ThirdParty glfw3 opengl32 assimp)
set(SFML_AUDIO_LIBS sfml-audio sfml-system)

target_link_libraries(Vibe2D PUBLIC
    ${CORE_OPENGL_LIBS}
    ${SFML_AUDIO_LIBS}
    ${WINDOWS_DRIVERS}
)
