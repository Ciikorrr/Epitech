##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SOURCE_DIR = src/

SRC	=	bootstrap.c \
		my_strlen.c

OBJ	=	$(addprefix $(SOURCE_DIR), $(SRC:.c=.o))

NAME	=	my_popup

CPPFLAGS = -I ./include

#LDFLAGS = -L my_printf/ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) -lncurses

$(LIB):

clean:
	find -name "#*#" -delete -o -name "*~" -delete
	rm $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
