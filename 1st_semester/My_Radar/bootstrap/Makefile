##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SOURCE_DIR = src/

SRC	=	main.c\
		circle.c\
		init_struct.c\
		window.c\

OBJ	=	$(addprefix $(SOURCE_DIR), $(SRC:.c=.o))

NAME	=	my_radar

CPPFLAGS = -I ./include -g

LDFLAGS = -L lib/my/ -lmy -L lib/my_printf/ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my_printf/
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) -lcsfml-graphics -lcsfml-system -lcsfml-window

$(LIB):
	make -C lib/my_printf/
	make -C lib/my

clean:
	find -name "#*#" -delete -o -name "*~" -delete
	rm -f $(OBJ)
	make -C lib/my_printf/ clean

fclean:	clean
	rm -f $(NAME)
	make fclean -C lib/my
	make fclean -C lib/my_printf/


re: fclean all

.PHONY: all clean fclean re
