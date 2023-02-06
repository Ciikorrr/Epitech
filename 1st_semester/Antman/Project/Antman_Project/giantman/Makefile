##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SOURCE_DIR = src/

SRC	=	main.c  						\
		decompress.c  					\
		file_to_str.c 					\
		giantman.c 						\
		image/decompress_image.c 		\
		site/decompress_html.c 			\
		texte/binary_heap_methods.c 	\
		texte/binary_heap_methods2.c 	\
		texte/create_huffman.c 			\
		texte/linked_list_methods.c 	\
		texte/parse_header.c 			\
		texte/decompress_texte.c 		\
		texte/show_linked_list.c 		\
		texte/encode_text.c

OBJ	=	$(addprefix $(SOURCE_DIR), $(SRC:.c=.o))

NAME	=	giantman

CPPFLAGS = -I ./include

CFLAGS = -Wall -Wextra

LDFLAGS  = -L./../lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ../lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
