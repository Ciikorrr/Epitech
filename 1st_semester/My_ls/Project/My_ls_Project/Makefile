##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SRC	=	my_ls.c \
		no_argument.c\
		lib/my/my_putchar.c \
		lib/my/my_putstr.c \
		my_strcmp.c \
		flag_a.c \
		flags_function.c \
		flag_d.c \
		flag_l.c \
		my_strcat.c \
		my_strdup.c \
		my_strlen.c \
		info_l.c \
		error_handling.c \
		flag_r.c \
		flag_t.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

CPPFLAGS = -I ./include

LDFLAGS = -L my_printf/ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C my_printf/
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

$(LIB):
	# make -C my_printf/
	# make -C lib/my

clean:
	find -name "#*#" -delete -o -name "*~" -delete
	rm $(OBJ)
	make -C my_printf/ clean

fclean:	clean
	rm -f $(NAME)
	make -C my_printf/ fclean


re: fclean all

.PHONY: all clean fclean re
