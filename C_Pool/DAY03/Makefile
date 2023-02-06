##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SRC	=	my_isneg.c \
		my_print_alpha.c \
		my_print_comb.c \
		my_print_comb2.c \
		my_print_digits.c \
		my_print_revalpha.c \
		my_put_nbr.c \
		my_putchar.c \
		my_putstr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libday03.a

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
		$(CFLAGS) libday03.a \
		-lcriterion --coverage -o unit_tests

tests_run: unit_tests
			./unit_tests

.PHONY: all clean fclean re
