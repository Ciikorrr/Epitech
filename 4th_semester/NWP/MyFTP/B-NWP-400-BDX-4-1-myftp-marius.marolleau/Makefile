##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

ERROR_HANDLING = error_handling/

UTILS = utils/

FUNC_CMD = func_command/

SOURCE_DIR = src/

SRC	=	main.c\
		init_struct.c\
		myftp_func.c\
		new_client.c\
		free_all.c\
		select_client.c\
		my_word_array_separator.c\
		$(ERROR_HANDLING)check_args.c\
		$(UTILS)string_is_num.c\
		$(UTILS)get_path.c\
		$(UTILS)free_tab.c\
		$(UTILS)strcat_dup.c\
		$(UTILS)my_strcmp.c\
		$(FUNC_CMD)func_user.c\
		$(FUNC_CMD)func_pass.c\
		$(FUNC_CMD)func_cdup.c\
		$(FUNC_CMD)func_cwd.c\
		$(FUNC_CMD)func_dele.c\
		$(FUNC_CMD)func_help.c\
		$(FUNC_CMD)func_list.c\
		$(FUNC_CMD)func_noop.c\
		$(FUNC_CMD)func_pasv.c\
		$(FUNC_CMD)func_port.c\
		$(FUNC_CMD)func_pwd.c\
		$(FUNC_CMD)func_quit.c\
		$(FUNC_CMD)func_retr.c\
		$(FUNC_CMD)func_syst.c\
		$(FUNC_CMD)func_stor.c

TO_TEST =	$(SOURCE_DIR)$(ERROR_HANDLING)check_args.c \
			$(SOURCE_DIR)$(UTILS)string_is_num.c \
			$(SOURCE_DIR)$(UTILS)strcat_dup.c \
			$(SOURCE_DIR)$(UTILS)my_strcmp.c \
			tests/test_my_strcat_dup.c \
			tests/test_strcmp.c

OBJ	=	$(addprefix $(SOURCE_DIR), $(SRC:.c=.o))

NAME	=	myftp

CPPFLAGS = -I ./include

CFLAGS = -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

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
