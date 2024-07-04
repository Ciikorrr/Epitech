##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

TO_TEST = string_1.c\
		string_2.c\
		string_3.c\
		string_4.c\
		string_5.c\
		string_6.c\

SRC	=	string_1.c\
		string_2.c\
		string_3.c\
		string_4.c\
		string_5.c\
		string_6.c\
		my_word_array_separator.c\
		find_index_separator.c\
		loop_separator.c\
		my_alphanum.c\
		nbr_word_separator.c\
		strlen_index_separator.c\
		tab_length.c

OBJ    =    $(SRC:.c=.o)

NAME    =    libstring.a

all:    $(NAME)

$(NAME):	$(OBJ)
	ar rc $@ $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f vgcore*
	rm -f *.gcno
	rm -f *.gcda
	rm -f a.out
	rm -f coding-style*

fclean:	clean
	rm -f $(NAME)


unit_tests : fclean all
		gcc tests/test.c\
		$(TO_TEST)\
		-lcriterion --coverage -o unit_tests -L. -lstring -ggdb3

tests_run : unit_tests
			./unit_tests

re: fclean all
.PHONY: all clean fclean
