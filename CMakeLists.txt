cmake_minimum_required(VERSION 3.10)
project(Simulator)

# Ensure C++17 or higher for modern features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Collect sources
# IMPORTANT: Make sure glad.c is actually inside your src/ folder!
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})

# 2. Include paths
target_include_directories(${PROJECT_NAME} PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# 3. Linking
# 'opengl32' is required on Windows. 
# If glfw3 is installed via a package manager, this works:
find_package(glfw3 REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw opengl32)

# If you get a "glfw3Config.cmake not found" error, 
# you might need to link the library file directly instead of using find_package.
