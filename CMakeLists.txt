cmake_minimum_required(VERSION 3.27)
project(heavy_metal)

set(CMAKE_CXX_STANDARD 23)

FIND_LIBRARY(APPKIT_LIBRARY AppKit)
FIND_LIBRARY(FOUNDATION_LIBRARY Foundation)
FIND_LIBRARY(METAL_KIT_LIBRARY MetalKit)
FIND_LIBRARY(METAL_LIBRARY Metal)

set(APPLE_FRAMEWORKS
        ${APPKIT_LIBRARY}
        ${FOUNDATION_LIBRARY}
        ${METAL_KIT_LIBRARY}
        ${METAL_LIBRARY}
)

include_directories(
        include
        include/platform/metal-cpp
        include/platform/metal-cpp-extensions
)
add_executable(heavy_metal main.cpp include/macos.h)
target_link_libraries(heavy_metal PUBLIC ${APPLE_FRAMEWORKS})
