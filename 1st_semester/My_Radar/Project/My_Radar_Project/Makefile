##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SOURCE_DIR = src/

SRC	=	init_radar/init_struct.c\
		init_radar/get_info.c\
		init_radar/biggest_line.c\
		init_radar/info_tab.c\
		init_radar/fill_elem.c\
		my_radar/main.c\
		my_radar/window.c\
		my_radar/intersections.c\
		my_radar/plane.c\
		my_radar/tower.c\
		my_radar/free_all.c\
		error_handling/check_all_error.c\
		error_handling/check_char.c\
		../lib/my/my_str_to_word_array.c\
		../lib/my/my_alphanum.c\
		../lib/my/find_index.c\
		../lib/my/my_strlen_index.c\
		../lib/my/my_nbr_mot.c\
		../lib/my/my_getnbr.c\
		../lib/my/my_putstr.c\
		../lib/my/my_putchar.c\
		../lib/my/my_strlen.c\
		../lib/my/my_strncmp.c

OBJ	=	$(addprefix $(SOURCE_DIR), $(SRC:.c=.o))

NAME	=	my_radar

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
