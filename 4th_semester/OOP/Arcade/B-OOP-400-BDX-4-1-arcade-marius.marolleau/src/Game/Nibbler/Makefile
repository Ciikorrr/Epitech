##
## EPITECH PROJECT, 2024
## B-OOP-400-BDX-4-1-tekspice-marius.marolleau
## File description:
## Makefile
##

SRC	=	externNibbler/nibblerAlgo.cpp	\

NAME	=	arcade_nibbler.so

CXX	=	g++

CPPFLAGS	=	-I./../../Game/Nibbler/

all:
	$(CXX) -shared -fPIC -o $(NAME) $(SRC) $(CPPFLAGS)
	mv $(NAME) ../../../lib/

.PHONY: all