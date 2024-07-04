find_package(SFML 2 REQUIRED COMPONENTS graphics CONFIG)
find_package(OpenGL REQUIRED)

# imgui: https://github.com/ocornut/imgui/tree/docking
# imgui-sfml: https://github.com/SFML/imgui-sfml/tree/2.6.x
# incbin: https://github.com/graphitemaster/incbin

set(INCBIN_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/incbin)
add_library(incbin INTERFACE)
target_include_directories(incbin INTERFACE ${INCBIN_INCLUDE_DIR})

# imgui and imgui-sfml are interdependant because of the custom `imconfig.h`
# file required by imgui-sfml, so both are bundled in the imgui-sfml library

set(IMGUI_SOURCES
    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/imgui_stdlib.cpp
)

set(IMGUI_SFML_SOURCES
    imgui-sfml/imgui-SFML.cpp
)

set(IMGUI_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui)
set(IMGUI_SFML_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui-sfml)

add_library(ImGui-SFML ${IMGUI_SOURCES} ${IMGUI_SFML_SOURCES})

target_link_libraries(ImGui-SFML PRIVATE sfml-graphics OpenGL::GL)
target_compile_features(ImGui-SFML PRIVATE cxx_std_11)
target_include_directories(ImGui-SFML PUBLIC ${IMGUI_INCLUDE_DIR} ${IMGUI_SFML_INCLUDE_DIR})
