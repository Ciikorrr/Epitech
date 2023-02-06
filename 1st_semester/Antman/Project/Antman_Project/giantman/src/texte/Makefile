##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##


SRC	=  	decompress_texte.c 				\
		show_linked_list.c 				\
		binary_heap_methods2.c 			\
		binary_heap_methods.c 			\
		create_huffman.c 				\
		parse_header.c

OBJ	=	$(SRC:.c=.o)

NAME	=	a.out

CPPFLAGS = -I ./../../include

CFLAGS = -Wall -Wextra

LDFLAGS  = -L./../../../lib/ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB) $(LDFLAGS)

$(LIB):
	make -C ../../../lib/my/

clean:
	find -name "#*#" -delete -o -name "*~" -delete
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
