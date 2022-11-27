cmake_minimum_required(VERSION 3.12)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{CMAKE_TOOLCHAIN_FILE})
   set(CMAKE_TOOLCHAIN_FILE $ENV{CMAKE_TOOLCHAIN_FILE})
endif()

project(DLA02_build)
find_package(OpenImageIO CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

add_executable(DLA02)
Target_sources(DLA02 PRIVATE src/main.cpp
                           src/Image.cpp
                           src/Walker.cpp
                           include/Image.h
                           include/RGBA.h
                           include/Walker.h
)

target_link_libraries(DLA02 PRIVATE OpenImageIO::OpenImageIO OpenImageIO::OpenImageIO fmt::fmt-header-only)