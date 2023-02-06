##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SRC	=	src/main.c \
		src/my_bsq.c \
		src/is_square_of_size.c \
		lib/my/my_show_word_array.c \
		lib/my/my_putstr.c\
		src/info_tab.c \
		src/file_to_str.c\
		src/biggest_line.c\
		src/my_putchar.c \
		src/my_strlen.c \
		src/my_getnbr.c \
		src/generate.c	\
		src/error.c \
		src/my_strcmp.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

all:	$(NAME)

CPPFLAGS = -I ./include -g

$(NAME):	$(LIB) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS)
$(LIB):
	make -C lib/my

clean:
	find -name "#*#" -delete -o -name "*~" -delete
	rm $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
