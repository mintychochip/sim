cmake_minimum_required(VERSION 3.10)
project(Simulator)

# 1. Look for GLFW on your system
find_package(glfw3 REQUIRED)

# 2. Collect ALL source files (including glad.c if it's in src)
file(GLOB SOURCES "src/*.cpp" "src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})

# 3. Tell the compiler where headers are
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# 4. LINK THE LIBRARIES (This fixes the LNK2019 errors)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw opengl32)
