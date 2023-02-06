##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SRC	=	end_game.c\
		launch_game.c\
		verif_end_game.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libnavy.a

CFLAGS = -Wall -Wextra

CPPFLAGS = -I ../../include

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp libnavy.h ../../include/
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
