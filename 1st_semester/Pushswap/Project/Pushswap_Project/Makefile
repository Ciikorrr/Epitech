##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SOURCE_DIR = src/

SRC	=	main.c\
		functions_list/free_list.c\
		functions_list/list.c\
		functions_list/utils_list.c\
		../lib/my/my_getnbr.c\
		operations/operations.c \
		operations/operations_2.c \
		operations/operations_3.c\
		error_handling/check_error.c \
		functions_list/functions_divers.c\
		functions_list/function_lists.c

OBJ	=	$(addprefix $(SOURCE_DIR), $(SRC:.c=.o))

NAME	=	push_swap

CPPFLAGS = -I ./include -g

CFLAGS = -W

LDFLAGS = -L lib/my/ -lmy -L lib/my_printf/ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my_printf/
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

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

debug: CFLAGS += -ggdb3
debug: $(NAME)

re: fclean all

.PHONY: all clean fclean re
