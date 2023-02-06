##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SOURCE_DIR = src/

SRC	=	main.c  						\
		antman.c 						\
		check_extension.c 				\
		compress.c 						\
		file_to_str.c 					\
		image/compress_image.c 			\
		site/compress_html.c 			\
		texte/create_huffman.c 			\
		texte/binary_heap_methods.c 	\
		texte/binary_heap_methods2.c 	\
		texte/determine_frequency.c 	\
		texte/show_linked_list.c 		\
		texte/get_number_bits.c 		\
		texte/encode_text.c 			\
		texte/write_bytes.c

OBJ	=	$(addprefix $(SOURCE_DIR), $(SRC:.c=.o))

NAME	=	antman

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
