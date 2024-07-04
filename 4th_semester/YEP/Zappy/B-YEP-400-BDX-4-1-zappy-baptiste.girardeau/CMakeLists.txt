cmake_minimum_required(VERSION 3.26)

project(Zappy
        LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SANITIZER "NONE" CACHE STRING "Enable sanitizers")

if (SANITIZER STREQUAL "MEMORY")
    add_link_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
    add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
elseif (SANITIZER STREQUAL "THREAD")
    add_link_options(-fsanitize=thread -fno-omit-frame-pointer)
    add_compile_options(-fsanitize=thread -fno-omit-frame-pointer)
endif ()

add_subdirectory(gui)
add_subdirectory(server)
