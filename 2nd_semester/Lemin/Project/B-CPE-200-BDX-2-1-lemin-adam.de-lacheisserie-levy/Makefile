##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

UTILS = utils

PARSER = parser

ALGORITHME = algorithme

SOURCE_DIR = src/

SRC	=	main.c \
		lemin.c \
		add_name_node.c\
		$(PARSER)/parser.c\
		$(UTILS)/word_array/find_index_separator.c \
		$(UTILS)/word_array/loop_separator.c \
		$(UTILS)/word_array/my_word_array_separator.c \
		$(UTILS)/word_array/nbr_word_separator.c \
		$(UTILS)/word_array/strlen_index_separator.c \
		$(UTILS)/my_str_isnum.c \
		$(UTILS)/add_elem_in_tab.c \
		$(UTILS)/my_strncmp.c \
		$(UTILS)/my_strcmp.c \
		$(UTILS)/my_strdup.c \
		$(UTILS)/my_strlen.c \
		$(UTILS)/length_tab.c \
		$(PARSER)/list.c \
		$(PARSER)/load_file.c

OBJ	=	$(addprefix $(SOURCE_DIR), $(SRC:.c=.o))

NAME	=	lemin

CPPFLAGS = -I ./include

CFLAGS = -Wall -Wextra

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

debug: fclean
debug: CFLAGS  += -ggdb3
debug:	$(NAME)

unit_tests: fclean $(NAME)
		gcc tests/test.c \
		-lcriterion --coverage -o unit_tests -I ./include

tests_run: unit_tests
			./unit_tests

.PHONY: all clean fclean re
