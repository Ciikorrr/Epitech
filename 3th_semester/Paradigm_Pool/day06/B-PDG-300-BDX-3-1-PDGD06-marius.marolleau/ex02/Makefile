##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SRC	=	StupidUnitConverter.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	StupidUnitConverter

CFLAGS = -std=c++20 -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
