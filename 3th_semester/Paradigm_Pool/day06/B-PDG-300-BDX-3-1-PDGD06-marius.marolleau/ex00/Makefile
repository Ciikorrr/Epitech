##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SRC	=	Z.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	Z

CFLAGS = -std=c++20 -Wall -Wextra -Werror


all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f unit_tests*

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re