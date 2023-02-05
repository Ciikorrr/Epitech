##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SOURCE_DIR = src/

SRC	=	kill_it.c

OBJ	=	$(addprefix $(SOURCE_DIR), $(SRC:.c=.o))

NAME	=	kill_it

CPPFLAGS = -I ./include

LDFLAGS = -L lib/my/-lmy -lcsfml-graphics -lcsfml-system -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)
$(LIB):
	make -C lib/my
clean:
	find -name "#*#" -delete -o -name "*~" -delete
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	make fclean -C lib/my

re: fclean all

.PHONY: all clean fclean re
