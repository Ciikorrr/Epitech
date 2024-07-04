##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SRC	=	MyCat.cpp


NAME	=	MyCat

CFLAGS = -std=c++20 -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
