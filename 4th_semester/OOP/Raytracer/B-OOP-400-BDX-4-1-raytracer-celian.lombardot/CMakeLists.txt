cmake_minimum_required(VERSION 3.10)

project(RayTracer)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -ffast-math")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src/
    src/math
    src/parser
    src/factory
    src/composite
    src/raytracer
    src/raytracer/lights
    src/raytracer/shapes
)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(raytracer ${SOURCES})

target_link_libraries(raytracer PRIVATE config++)
include(FindPkgConfig)
pkg_search_module(SFML 2.5.1 REQUIRED sfml-all)
target_include_directories(raytracer PRIVATE ${SFML_INCLUDE_DIRS})
target_link_libraries(raytracer PRIVATE ${SFML_LIBRARIES})
