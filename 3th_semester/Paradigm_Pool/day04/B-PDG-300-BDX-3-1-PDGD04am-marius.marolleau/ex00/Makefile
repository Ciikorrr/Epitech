##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SRC	=	z.c

OBJ	=	$(SRC:.c=.o)

NAME	=	z

CFLAGS = -std=gnu17 -Wall -Wextra


all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f unit_tests*

fclean:	clean
	rm -f $(NAME)

re: fclean all

unit_tests: fclean $(NAME)
		gcc tests/test.c src/hidenp.c src/my_strlen.c src/error.c \
		-lcriterion --coverage -o unit_tests -I ./include

tests_run: unit_tests
			./unit_tests

.PHONY: all clean fclean re
