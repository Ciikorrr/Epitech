find_package(SFML 2 REQUIRED COMPONENTS graphics CONFIG)

add_subdirectory(vendor)

file(GLOB_RECURSE ZAPPY_GUI_HEADERS CONFIGURE_DEPENDS "gui/*.hpp")
file(GLOB_RECURSE ZAPPY_GUI_SOURCES CONFIGURE_DEPENDS "gui/*.cpp")

add_executable(zappy_gui ${ZAPPY_GUI_HEADERS} ${ZAPPY_GUI_SOURCES})

target_link_libraries(zappy_gui PRIVATE ImGui-SFML sfml-graphics incbin)
target_compile_definitions(zappy_gui PRIVATE SOURCE_DIR="${CMAKE_SOURCE_DIR}")
target_compile_features(zappy_gui PRIVATE cxx_std_20)

target_include_directories(zappy_gui PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
