##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SOURCE_DIR = src/

BULIT_IN = builtin_functions

WORD_ARRAY = word_array

CD = options_cd

ERROR = error_handling

FEATURES = features

LIB_STR = lib_str

LIB_LIST = lib_list

LIB_TAB = lib_tab

SETENV = setenv_functions

REDIRECT = redirections

UTILS = utils

EXECUTION_DIR = execution

SRC	=	main.c\
		mysh.c\
		get_input.c\
		parser.c\
\
		$(FEATURES)/$(REDIRECT)/redirect.c\
		$(FEATURES)/$(REDIRECT)/function_redirect.c\
		$(FEATURES)/$(REDIRECT)/get_fd_input.c\
		$(FEATURES)/$(REDIRECT)/remake_all_tab.c\
		$(FEATURES)/$(REDIRECT)/double_redirection_left.c\
\
		$(ERROR)/check_error_cd.c\
		$(ERROR)/check_error_setenv.c\
		$(ERROR)/check_error_command.c\
\
		$(EXECUTION_DIR)/exec_command.c\
		$(EXECUTION_DIR)/exec_binary.c\
		$(EXECUTION_DIR)/search_path.c\
		$(EXECUTION_DIR)/absolut_path.c\
		$(EXECUTION_DIR)/functions_in_fork.c\
\
		$(UTILS)/$(WORD_ARRAY)/my_strlen_index.c\
		$(UTILS)/$(WORD_ARRAY)/my_alphanum.c\
		$(UTILS)/$(WORD_ARRAY)/my_nbr_mot.c\
		$(UTILS)/$(WORD_ARRAY)/find_index.c\
		$(UTILS)/$(WORD_ARRAY)/my_str_to_word_array.c\
		$(UTILS)/$(WORD_ARRAY)/my_word_array_separator.c\
		$(UTILS)/$(WORD_ARRAY)/strlen_index_separator.c\
		$(UTILS)/$(WORD_ARRAY)/find_index_separator.c\
		$(UTILS)/$(WORD_ARRAY)/loop_separator.c\
		$(UTILS)/$(WORD_ARRAY)/nbr_word_separator.c\
\
		$(UTILS)/$(LIB_TAB)/free_tab.c\
		$(UTILS)/$(LIB_TAB)/remake_tab.c\
		$(UTILS)/$(LIB_TAB)/printf_tab.c\
		$(UTILS)/$(LIB_TAB)/list_to_tab.c\
		$(UTILS)/$(LIB_TAB)/length_tab.c\
\
		$(UTILS)/$(LIB_STR)/strcat_dup.c\
		$(UTILS)/$(LIB_STR)/my_strlen.c\
		$(UTILS)/$(LIB_STR)/my_strcmp.c\
		$(UTILS)/$(LIB_STR)/my_putchar.c\
		$(UTILS)/$(LIB_STR)/my_putstr.c\
		$(UTILS)/$(LIB_STR)/my_putstr_choose.c\
		$(UTILS)/$(LIB_STR)/my_put_nbr.c\
		$(UTILS)/$(LIB_STR)/my_strncmp.c\
		$(UTILS)/$(LIB_STR)/my_strdup.c\
		$(UTILS)/$(LIB_STR)/my_strcpy.c\
		$(UTILS)/$(LIB_STR)/my_str_isalpha.c\
\
		$(UTILS)/$(LIB_LIST)/tab_to_list.c\
		$(UTILS)/$(LIB_LIST)/list.c\
		$(UTILS)/$(LIB_LIST)/free_list.c\
\
		$(FEATURES)/$(BULIT_IN)/exec_builtins.c\
		$(FEATURES)/$(BULIT_IN)/env.c\
		$(FEATURES)/$(BULIT_IN)/setenv.c\
		$(FEATURES)/$(BULIT_IN)/unsetenv.c\
		$(FEATURES)/$(BULIT_IN)/exit.c\
		$(FEATURES)/$(BULIT_IN)/cd.c\
\
		$(FEATURES)/$(BULIT_IN)/$(CD)/functions_cd.c\
		$(FEATURES)/$(BULIT_IN)/$(CD)/cd_moins.c\
		$(FEATURES)/$(BULIT_IN)/$(CD)/simple_cd.c\
		$(FEATURES)/$(BULIT_IN)/$(CD)/cd_path.c\
		$(FEATURES)/$(BULIT_IN)/$(CD)/utils_for_cd.c\
		$(FEATURES)/$(BULIT_IN)/$(CD)/cd_basic.c\
		$(FEATURES)/$(BULIT_IN)/$(SETENV)/env_exist.c\
		$(FEATURES)/$(BULIT_IN)/$(SETENV)/get_index_env.c

TO_TEST = 	$(SOURCE_DIR)$(UTILS)/$(LIB_STR)/my_strlen.c\
			$(SOURCE_DIR)$(UTILS)/$(LIB_STR)/my_strncmp.c\
			$(SOURCE_DIR)$(UTILS)/$(LIB_STR)/my_strdup.c\
			$(SOURCE_DIR)$(UTILS)/$(LIB_TAB)/length_tab.c\
			$(SOURCE_DIR)$(UTILS)/$(LIB_STR)/my_str_isalpha.c\
			$(SOURCE_DIR)$(UTILS)/$(LIB_STR)/my_strcmp.c\
			$(SOURCE_DIR)$(UTILS)/$(LIB_STR)/my_putchar.c\
			$(SOURCE_DIR)$(UTILS)/$(LIB_STR)/my_putstr.c\
			$(SOURCE_DIR)$(UTILS)/$(LIB_STR)/my_put_nbr.c\
			$(SOURCE_DIR)$(UTILS)/$(WORD_ARRAY)/my_strlen_index.c\
			$(SOURCE_DIR)$(UTILS)/$(WORD_ARRAY)/my_alphanum.c\
			$(SOURCE_DIR)$(UTILS)/$(WORD_ARRAY)/my_nbr_mot.c\
			$(SOURCE_DIR)$(UTILS)/$(WORD_ARRAY)/nbr_word_separator.c\
			$(SOURCE_DIR)$(UTILS)/$(WORD_ARRAY)/loop_separator.c\
			$(SOURCE_DIR)$(UTILS)/$(LIB_STR)/strcat_dup.c\
			$(SOURCE_DIR)$(UTILS)/$(WORD_ARRAY)/find_index_separator.c\
			$(SOURCE_DIR)$(UTILS)/$(WORD_ARRAY)/my_word_array_separator.c\
			$(SOURCE_DIR)$(UTILS)/$(WORD_ARRAY)/strlen_index_separator.c\

OBJ	=	$(addprefix $(SOURCE_DIR), $(SRC:.c=.o))

NAME	=	mysh

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
		gcc tests/test.c \
		$(TO_TEST)\
		-lcriterion --coverage -o unit_tests -I ./include

tests_run: unit_tests
			./unit_tests

.PHONY: all clean fclean re
