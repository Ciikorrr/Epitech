##
## EPITECH PROJECT, 2024
## B-OOP-400-BDX-4-1-tekspice-marius.marolleau
## File description:
## Makefile
##

SRC	=	externSDL/displaySDL.cpp	\
		externSDL/initWindowSDL.cpp	\
		externSDL/userInputSDL.cpp	\
		externSDL/Display.cpp	\
		externSDL/displaySDLNibbler.cpp	\

NAME	=	arcade_sdl2.so

CXX	=	g++

CPPFLAGS	=	-I./../../Game/Snake/

all:
	$(CXX) -shared -fPIC -o $(NAME) $(SRC) $(CPPFLAGS)
	mv $(NAME) ../../../lib/

.PHONY: all