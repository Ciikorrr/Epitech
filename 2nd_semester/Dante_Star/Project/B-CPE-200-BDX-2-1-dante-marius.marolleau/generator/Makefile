##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SOURCE_DIR = src/

SRC	=	main.c  					\
		class_methods.c				\
		maze_methods.c				\
		prims_algorithm.c			\
		neighbours.c				\
		check_even.c

OBJ	=	$(addprefix $(SOURCE_DIR), $(SRC:.c=.o))

NAME	=	generator

CPPFLAGS = -I ./include

CFLAGS = -Wall -Wextra -O3

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
