##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

ERROR_HANDLING = error_handling/

SOURCE_DIR = src/

SRC	=	server.c\
		$(ERROR_HANDLING)check_args_srv.c\
		utils/free_tab.c\
		utils/my_word_array_separator.c\
		utils/command_parser.c\
		utils/string_is_num.c\
		utils/my_strcat_dup.c\
		utils/find_index_chat.c\
		utils/is_user_exists.c\
		init_server.c\
		client_handler.c\
		command_handler.c\
		commands/login_client.c\
		commands/create.c\
		commands/create_teams.c\
		commands/create_channels.c\
		commands/create_threads.c\
		commands/create_comments.c\
		commands/subscribe_unsubscribe.c\
		commands/logout_client.c\
		commands/get_users.c\
		commands/get_user.c\
		commands/get_infos.c\
		commands/get_list.c\
		commands/get_help.c\
		commands/get_messages.c\
		commands/list_subscribed.c\
		commands/use_context.c\
		commands/send.c

TO_TEST =

OBJ	=	$(addprefix $(SOURCE_DIR), $(SRC:.c=.o))

NAME	=	myteams_server

CPPFLAGS = -I ./include -lmyteams -L../libs/myteams

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


unit_tests: fclean $(NAME)
		@gcc $(TO_TEST)\
		-lcriterion --coverage -o unit_tests -I ./include

tests_run: unit_tests
			./unit_tests

.PHONY: all clean fclean re
