project(libPySeek)
cmake_minimum_required(VERSION 2.8)

## Request C++11 standard and version
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED True)

## Enable debug message
set (WITH_ADDRESS_SANITIZER false CACHE BOOL "Enable address sanitizer")
set (WITH_DEBUG_VERBOSITY false CACHE BOOL "Enable verbose stdout messages")
#set (default_build_type "Release")

## G++ compiler options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++11 -fPIC")

## Boost lib
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
#include(cmake/boost-python.cmake)

## Find OpenCV
find_package (OpenCV REQUIRED)
find_package(PythonInterp REQUIRED)
find_package(PythonLibs REQUIRED)
find_package(PythonLibs 2)

## Test OpenCV
set(TEST_PYTHON_VERSION "2"
    CACHE STRING "Python version used on tests.")
set_property(CACHE TEST_PYTHON_VERSION PROPERTY STRINGS "3" "2")

if(TEST_PYTHON_VERSION EQUAL 2)
    find_package(PythonLibs 2)
else()
    find_package(PythonLibs 3)
endif()

add_subdirectory (src)
add_subdirectory (example)
