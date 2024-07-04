##
## EPITECH PROJECT, 2024
## B-OOP-400-BDX-4-1-tekspice-marius.marolleau
## File description:
## Makefile
##

SRC	=	externNcurses/displayNcurses.cpp	\
		externNcurses/initWindowNcurses.cpp	\
		externNcurses/userInputSnakeNcurses.cpp	\
		externNcurses/NcursesMenu.cpp	\
		externNcurses/displayNcursesNibbler.cpp	\

NAME	=	arcade_ncurses.so

CXX	=	g++

CPPFLAGS	=	-I./../../Game/Snake/

all:
	$(CXX) -shared -fPIC -o $(NAME) $(SRC) $(CPPFLAGS)
	mv $(NAME) ../../../lib/

.PHONY: all