##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

ERROR_HANDLING = error_handling/

SOURCE_DIR = src/

SRC	=	client.c\
		$(ERROR_HANDLING)check_args_clt.c\
		utils/free_tab.c\
		utils/my_word_array_separator.c\
		utils/my_word_array_separator_quote.c\
		utils/command_parser.c\
		utils/string_is_num.c\
		utils/length_tab.c\
		init_client.c\
		codes/codelogin.c\
		codes/codelogout.c\
		codes/code_create.c\
		codes/code_print_create.c\
		codes/code_send.c\
		codes/code_bad_args.c\
		codes/code_bad_user.c\
		codes/code_help.c\
		codes/code_user.c\
		codes/code_users.c\
		codes/code_messages.c\
		codes/code_infos.c\
		codes/code_list.c\
		codes/code_already_exists.c\
		codes/code_unknown_team.c\
		codes/code_unauthorized.c\
		codes/code_subscribe.c\
		codes/code_unsubscribe.c

OBJ	=	$(addprefix $(SOURCE_DIR), $(SRC:.c=.o))

NAME	=	myteams_cli

CPPFLAGS = -I ./include -L../libs/myteams -lmyteams

CFLAGS = -Wall -Wextra -luuid

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)
	cp $(NAME) ../

clean:
	find -name "#*#" -delete -o -name "*~" -delete
	find -name "vgcore.*" -delete
	rm -f $(OBJ)
	rm -f unit_tests*

fclean:	clean
	rm -f $(NAME)

debug: fclean
debug: CFLAGS  += -ggdb3
debug:	$(NAME)

re: fclean all

.PHONY: all clean fclean re
