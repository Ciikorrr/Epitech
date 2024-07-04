##
## EPITECH PROJECT, 2024
## B-OOP-400-BDX-4-1-tekspice-marius.marolleau
## File description:
## Makefile
##

SRC	=	externSFML/initWindowSFML.cpp	\
		externSFML/handleInputsSFML.cpp	\
		externSFML/displaySnakeSFML.cpp	\
		externSFML/displayNibblerSFML.cpp	\
		externSFML/SFMLMenu.cpp	\

NAME	=	arcade_sfml.so

CXX	=	g++

CPPFLAGS	=	-I./../../Game/Snake/

all:
	$(CXX) -shared -fPIC -o $(NAME) $(SRC) $(CPPFLAGS)
	mv $(NAME) ../../../lib/

.PHONY: all