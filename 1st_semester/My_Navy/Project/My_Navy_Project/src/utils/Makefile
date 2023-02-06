##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SRC	=	bin_to_dec.c\
		bin_to_string.c\
		file_to_str.c\
		strcat_bis.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libutils.a

CFLAGS = -Wall -Wextra

CPPFLAGS = -I ./include

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp libutils.h ../../include/

clean:
	find -name "#*#" -delete -o -name "*~" -delete
	rm -rf *.log \
	rm *.gcno \
	rm *.gcda \
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
