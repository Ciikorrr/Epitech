##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SRC	=	connect_players.c\
		decode_signal.c\
		get_signal.c\
		give_consequence.c\
		launch_attack.c\
		receive_signal.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libsignal.a

CFLAGS = -Wall -Wextra

CPPFLAGS = -I ../../include

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp libsignal.h ../../include/

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
