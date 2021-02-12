cmake_minimum_required(VERSION 3.16)

project(InputManager)

set(CMAKE_CXX_STANDARD 20)

#### Source

include_directories(Include)

# Source Files
file(GLOB_RECURSE SOURCE_FILES
        Src/*.c
        Src/*.cpp)

#### LIB

#GLFW
set(GLFW_DIR ThirdParty/glfw)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(${GLFW_DIR})
include_directories(${GLFW_DIR}/include)

set(LIB glfw)

add_executable(InputManager ${SOURCE_FILES})
target_link_libraries(InputManager ${LIB})