##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SRC	=	add_boat.c\
		check_caracters.c\
		check_position.c\
		check_script.c\
		create_map.c\
		show_map.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmap.a

CFLAGS = -Wall -Wextra

CPPFLAGS = -I ../../include

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp libmap.h ../../include/
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

.PHONY: all clean fclean re
