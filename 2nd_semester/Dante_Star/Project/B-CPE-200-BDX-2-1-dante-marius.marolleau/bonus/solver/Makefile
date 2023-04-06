##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SOURCE_DIR = src/

UTILS_DIR = utils

SRC	=	main.c  						\
		error_handling.c				\
		do_solver.c						\
		movement.c						\
		go_back.c 						\
		free_tab.c						\
		map.c 							\
		fill_tab.c 						\
		init_struct.c 					\
		$(UTILS_DIR)/my_strlen.c		\
		$(UTILS_DIR)/my_putchar.c		\
		$(UTILS_DIR)/my_putstr.c		\
		$(UTILS_DIR)/file_to_str.c		\
		$(UTILS_DIR)/biggest_line.c		\
		$(UTILS_DIR)/print_tab.c		\
		$(UTILS_DIR)/info_tab.c			\
		$(UTILS_DIR)/print_char_by_char.c\
		$(UTILS_DIR)/my_strdup.c

OBJ	=	$(addprefix $(SOURCE_DIR), $(SRC:.c=.o))

NAME	=	solver

CPPFLAGS = -I ./include

CFLAGS = -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	find -name "#*#" -delete -o -name "*~" -delete
	find -name "vgcore.*" -delete
	rm -f $(OBJ)
	rm -f unit_tests*

fclean:	clean
	rm -f $(NAME)

debug: fclean
debug: CFLAGS += -ggdb3
debug: $(NAME)

re: fclean all

.PHONY: all clean fclean re unit_tests
