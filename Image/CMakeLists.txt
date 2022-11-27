# make min wersion 3.12
cmake_minimum_required(VERSION 3.12)

# this is to make vcpkg work.
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{CMAKE_TOOLCHAIN_FILE})
   set(CMAKE_TOOLCHAIN_FILE $ENV{CMAKE_TOOLCHAIN_FILE})
endif()

# add our project
project(Image_build CXX)

# set some project values
set(CMAKE_CXX_STANDARD 17)
find_package(OpenImageIO CONFIG REQUIRED)
#find_package(IlmBase CONFIG REQUIRED)
#find_package(OpenEXR CONFIG REQUIRED)

# add the executable name for this program 
add_executable(Image)
include_directories(include)

# add source files for my project
target_sources(Image PRIVATE ${CMAKE_SOURCE_DIR}/src/main.cpp
                              ${CMAKE_SOURCE_DIR}/src/Image.cpp
                              ${CMAKE_SOURCE_DIR}/include/Image.h
                              ${CMAKE_SOURCE_DIR}/include/RGBA.h
)
target_link_libraries(Image PRIVATE OpenImageIO::OpenImageIO OpenImageIO::OpenImageIO_Util)

## Add testing stuff
find_package(GTest CONFIG REQUIRED)
include(GoogleTest)
enable_testing()
add_executable(ImageTests)
include_directories(include)
target_sources(ImageTests PRIVATE tests/RGBATests.cpp
                              ${CMAKE_SOURCE_DIR}/tests/ImageTests.cpp
                              ${CMAKE_SOURCE_DIR}/src/Image.cpp
                              ${CMAKE_SOURCE_DIR}/include/Image.h
                              ${CMAKE_SOURCE_DIR}/include/RGBA.h
)

target_link_libraries(ImageTests PRIVATE GTest::gtest GTest::gtest_main)
target_link_libraries(ImageTests PRIVATE OpenImageIO::OpenImageIO OpenImageIO::OpenImageIO_Util)

gtest_discover_tests(ImageTests)