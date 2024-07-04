include_directories(include src/parseArguments/flags)

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(zappy_server ${SOURCES})
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")