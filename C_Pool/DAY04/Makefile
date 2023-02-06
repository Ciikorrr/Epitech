##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SRC	=	my_strlen.c\
		my_swap.c\
		my_sort_int_array.c\
		my_putstr.c\
		my_evil_str.c\
		my_getnbr.c\
		my_putchar.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libday04.a

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
		$(CFLAGS) libday04.a \
		-lcriterion --coverage -o unit_tests

tests_run: unit_tests
			./unit_tests

.PHONY: all clean fclean re
