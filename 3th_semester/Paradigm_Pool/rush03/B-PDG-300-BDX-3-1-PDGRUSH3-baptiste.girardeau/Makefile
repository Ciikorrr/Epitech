##
## EPITECH PROJECT, 2024
## rush3
## File description:
## Makefile
##

SRC				:=	Src/main.cpp \
					Src/Core/Core.cpp \
					Src/Modules/BaseModule.cpp \
					Src/Modules/Battery/Battery.cpp \
					Src/Modules/Cpu/Cpu.cpp \
					Src/Modules/Memory/Memory.cpp \
					Src/Modules/OS/DateTime.cpp \
					Src/Modules/OS/Host.cpp \
					Src/Modules/OS/Os.cpp \
					Src/Parse/FileParser.cpp \
					Src/Parse/ValueParser.cpp \
					Src/Ui/Display/Debug/DebugDisplay.cpp \
					Src/Ui/Display/Imgui/ImguiDisplay.cpp \
					Src/Ui/Display/Ncurses/NcursesDisplay.cpp \
					Src/Ui/Display/SFML/SfmlDisplay.cpp \
					Src/Ui/Display/SFML/SfmlOperations.cpp \
					Src/Ui/Widgets/HistogramWidget.cpp \
					Src/Ui/Widgets/TextWidget.cpp \
					Src/Ui/Widgets/WidgetStack.cpp \

IMGUI_SRC		:= 	Libs/imgui/imgui.cpp \
					Libs/imgui/imgui_draw.cpp \
					Libs/imgui/imgui_widgets.cpp \
					Libs/imgui/imgui_tables.cpp \
					Libs/imgui/backends/imgui_impl_opengl3.cpp \
					Libs/imgui/backends/imgui_impl_glfw.cpp \

RELEASE_OUT		:= 	MyGKrellm
DEBUG_OUT		:= 	MyGKrellm_debug

BUILD_DIR		:=  build
RELEASE_DIR 	:= 	build/release
DEBUG_DIR		:= 	build/debug

CXX 			?= 	g++
CXXFLAGS		+=	-std=c++20 -MMD -MP
LDFLAGS			:= -lncurses -lsfml-graphics -lsfml-window -lsfml-system \
					$(if $(IMGUI_BACKEND), -lglfw -lGL,)

RELEASE_OBJ 	:= 	$(addprefix $(RELEASE_DIR)/,$(SRC:.cpp=.o)) \
					$(if $(IMGUI_BACKEND), $(addprefix $(RELEASE_DIR)/,$(IMGUI_SRC:.cpp=.o)),)
RELEASE_FLAGS	:=	-O3 $(if $(IMGUI_BACKEND), -DIMGUI_BACKEND -iquoteLibs,)

DEBUG_OBJ		:= 	$(addprefix $(DEBUG_DIR)/,$(SRC:.cpp=.o)) \
					$(if $(IMGUI_BACKEND), $(addprefix $(DEBUG_DIR)/,$(IMGUI_SRC:.cpp=.o)),)
SANITIZERS		:=	-fsanitize=address,undefined
DEBUG_FLAGS		:=	-g3 -Wall -Wextra -Wpedantic -Wshadow \
					$(if $(NO_SANITIZE),, $(SANITIZERS)) \
					$(if $(IMGUI_BACKEND), -DIMGUI_BACKEND -iquoteLibs,)

all: release

-include $(RELEASE_OBJ:.o=.d)
-include $(DEBUG_OBJ:.o=.d)

## BUILD ##

release: $(RELEASE_OUT)
debug: $(DEBUG_OUT)

$(RELEASE_OUT): CXXFLAGS += $(RELEASE_FLAGS)
$(RELEASE_OUT): $(RELEASE_OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

$(DEBUG_OUT): CXXFLAGS += $(DEBUG_FLAGS)
$(DEBUG_OUT): $(DEBUG_OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

## OBJECTS ##

$(RELEASE_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) -o $@ -c $< $(CXXFLAGS)

$(DEBUG_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) -o $@ -c $< $(CXXFLAGS)

## RUN ##

run: release
	@./$(RELEASE_OUT)

run_debug: debug
	@./$(DEBUG_OUT)

## CLEANING ##

clean:
	$(RM) -r $(BUILD_DIR)

fclean: clean
	$(RM) $(RELEASE_OUT) $(DEBUG_OUT)

re: fclean all

.PHONY: all release debug run run_debug clean fclean re help
