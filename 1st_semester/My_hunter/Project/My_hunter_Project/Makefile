##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SRC	=	src/main.c \
		src/func_my_hunter/my_hunter.c \
		src/func_my_hunter/bonus.c \
		src/func_my_hunter/menu.c \
		src/my/my_putstr.c \
		src/my/my_putchar.c \
		src/func_my_hunter/int_to_str.c \
		src/my/my_strncmp.c \
		src/func_my_hunter/functions_divers.c\
		src/func_my_hunter/destroy_function.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

all:	$(NAME)

CPPFLAGS = -I ./include -g

$(NAME):	$(LIB) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) -lcsfml-graphics \
	-lcsfml-system -lcsfml-window
$(LIB):
	make -C lib/my

clean:
	find -name "#*#" -delete -o -name "*~" -delete
	rm $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
