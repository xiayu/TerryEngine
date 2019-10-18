cmake_minimum_required(VERSION 3.5)

project(Terry)
if(WIN32)
	add_definitions(-DTR_PLATFORM_WINDOW)
endif()
# https://stackoverflow.com/questions/24460486/cmake-build-type-is-not-being-used-in-cmakelists-txt
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)
# cmake -G"Visual Studio 14 2015 Win64"


message("Generated with config types: ${CMAKE_CONFIGURATION_TYPES}")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_SUPPRESS_REGENERATION true)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(Terry)
add_subdirectory (SanBox)