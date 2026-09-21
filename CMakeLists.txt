cmake_minimum_required(VERSION 3.22)
project(Vibe2D_Ecosystem VERSION 1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Forces all subprojects to output directly to your build/bin folder structure
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# =========================================================================
# CENTRALIZED ECOSYSTEM LOCATION MAPPING
# =========================================================================
set(GRAPHICS_ROOT "C:/Developer/Graphics")
link_directories("${GRAPHICS_ROOT}/lib")

# CRITICAL FIX: Push this definition globally to ALL subprojects in the workspace!
# This ensures Sandbox_app.cpp can see the 'int main' block inside EntryPoint.h!
add_compile_definitions(VIBE2D_PLATFORM_WINDOWS)

# Register the subfolders
add_subdirectory(Vibe2D)
add_subdirectory(Sandbox)
