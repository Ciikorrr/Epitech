##
## EPITECH PROJECT, 2022
## zoijr
## File description:
## ouais
##

SRC		=	rush3.c display.c

OBJ		=	$(SRC:.c=.o)

NAME 	= 	rush3

LDFLAGS	=	-L lib/ -lmy

CFLAGS=	-I./include

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -g -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		make -C lib/my fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
