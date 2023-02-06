##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SRC	=	my_strcat.c\
		my_strncat.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libday07.a

CFLAGS = -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	find -name "#*#" -delete -o -name "*~" -delete
	rm -rf *.log \
	rm *.gcno \
	rm *.gcda \
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests

re: fclean all

unit_tests: fclean $(NAME)
		gcc tests/* \
		$(CFLAGS) libday07.a \
		-lcriterion --coverage -o unit_tests

tests_run: unit_tests
			./unit_tests

.PHONY: all clean fclean re
