##
## EPITECH PROJECT, 2024
## B-OOP-400-BDX-4-1-tekspice-marius.marolleau
## File description:
## Makefile
##

SRC	=			src/Parser/Parser.cpp\
				src/arcade.cpp\
				src/Core/Core.cpp\
				src/Graphic/Ncurses/NcursesModule.cpp\
				src/Graphic/SFML/SfmlModule.cpp\
				src/Graphic/ADisplayModule.cpp\
				src/Graphic/SDL2/Sdl2Module.cpp\
				src/Game/Snake/SnakeModule.cpp\
				src/Game/Nibbler/NibblerModule.cpp\
				src/Game/AGameModule.cpp

SRC_MAIN	=	src/main.cpp


CPPFLAGS	=	-I./src/

CXX	=	g++

CXXFLAGS	=	 -W -Wall -Wextra -std=c++20 -lncurses -lSDL2 -lSDL2_image -lSDL2 -lSDL2_ttf -lsfml-graphics -lsfml-window -lsfml-system

OBJ	=	$(addprefix $(SOURCE_DIR), $(SRC:.cpp=.o)) $(SRC_MAIN:.cpp=.o)

NAME	=	arcade

NAME_TESTS	=	unit_tests

all: $(NAME) graphicals games

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS)

debug: fclean
debug: CFLAGS += -ggdb3
debug: $(NAME)

clean:
	rm -f lib/arcade*
	rm $(OBJ) -f

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests*

re: fclean all

core: $(NAME)

games:
	make -C src/Game/Snake
	make -C src/Game/Nibbler

graphicals:
	make -C src/Graphic/Ncurses
	make -C src/Graphic/SDL2
	make -C src/Graphic/SFML

.PHONY: all clean fclean re debug graphicals games core