##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	project

LDFLAGS	=	-lmy

LDFLAGS	=	-L./lib/ -lmy

CPPFLAGS	= -I./include/

LIB = lib/libmy.a

all:	$(NAME)

$(NAME):	$(LIB) $(OBJ)
	gcc -o $(NAME) $(NAME) $(CPPFLAGS) $(LDFLAGS)
$(LIB):
	make -C lib/my

clean:
	find -name "#*#" -delete -o -name "*~" -delete
	rm $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
