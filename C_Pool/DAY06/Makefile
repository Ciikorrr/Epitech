##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SRC	= 	my_strcpy.c\
		my_strncpy.c\
		my_revstr.c\
		my_strcmp.c\
		my_strncmp.c\
		my_strncpy.c\
		my_strupcase.c\
		my_strlowcase.c\
		my_strcapitalize.c\
		my_str_isalpha.c\
		my_str_isnum.c\
		my_str_islower.c\
		my_str_isupper.c\
		my_str_isprintable.c\
		my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libday06.a

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
		$(CFLAGS) libday06.a \
		-lcriterion --coverage -o unit_tests

tests_run: unit_tests
			./unit_tests

.PHONY: all clean fclean re
