##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

WORD_ARRAY = word_array

SOURCE_DIR = src/

SRC	=	main.c\
		$(WORD_ARRAY)/find_index_separator.c\
		$(WORD_ARRAY)/my_word_array_separator.c\
		$(WORD_ARRAY)/strlen_index_separator.c\
		$(WORD_ARRAY)/my_strlen_index.c\
		$(WORD_ARRAY)/my_alphanum.c\
		$(WORD_ARRAY)/my_nbr_mot.c\
		$(WORD_ARRAY)/nbr_word_separator.c\
		$(WORD_ARRAY)/loop_separator.c

OBJ	=	$(addprefix $(SOURCE_DIR), $(SRC:.c=.o))

NAME	=	my_exec2

CPPFLAGS = -I ./include

CFLAGS = -Wall -Wextra -ggdb3

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

clean:
	find -name "#*#" -delete -o -name "*~" -delete
	rm -f $(OBJ)
	rm -f unit_tests*

fclean:	clean
	rm -f $(NAME)


re: fclean all

unit_tests: fclean $(NAME)
		gcc tests/test.c \
		-lcriterion --coverage -o unit_tests -I ./include

tests_run: unit_tests
			./unit_tests

.PHONY: all clean fclean re
