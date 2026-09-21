cmake_minimum_required(VERSION 3.22)
project(SandboxGame LANGUAGES CXX C)

# Compile your sandbox game launcher app
add_executable(Sandbox src/Sandbox_app.cpp)

# Point Sandbox directly to your engine Include folder (Capital 'I'!)
target_include_directories(Sandbox PRIVATE "${CMAKE_SOURCE_DIR}/Vibe2D/Include")

# Link against your Engine library DLL
target_link_libraries(Sandbox PRIVATE Vibe2D)
