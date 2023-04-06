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

SETENV = setenv_functions

UTILS = utils

SRC	=	main.c\
		mysh.c\
		get_input.c\
		get_error.c\
		exec_command.c\
		search_path.c\
		absolut_path.c\
		$(UTILS)/free_tab.c\
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
		$(UTILS)/strcat_dup.c\
		$(UTILS)/my_strlen.c\
		$(UTILS)/my_strcmp.c\
		$(UTILS)/my_putchar.c\
		$(UTILS)/my_putstr.c\
		$(UTILS)/my_putstr_choose.c\
		$(UTILS)/my_put_nbr.c\
		$(UTILS)/my_strncmp.c\
		$(UTILS)/my_strdup.c\
		$(UTILS)/my_strcpy.c\
		$(UTILS)/list.c\
		$(UTILS)/free_list.c\
		$(UTILS)/list_to_tab.c\
		$(UTILS)/tab_to_list.c\
		$(UTILS)/length_tab.c\
		$(UTILS)/my_str_isalpha.c\
		$(BULIT_IN)/env.c\
		$(BULIT_IN)/setenv.c\
		$(BULIT_IN)/unsetenv.c\
		$(BULIT_IN)/exit.c\
		$(BULIT_IN)/cd.c\
		$(BULIT_IN)/$(CD)/functions_cd.c\
		$(BULIT_IN)/$(CD)/check_error_cd.c\
		$(BULIT_IN)/$(CD)/cd_moins.c\
		$(BULIT_IN)/$(CD)/simple_cd.c\
		$(BULIT_IN)/$(CD)/cd_path.c\
		$(BULIT_IN)/$(CD)/utils_for_cd.c\
		$(BULIT_IN)/$(CD)/cd_basic.c\
		$(BULIT_IN)/$(SETENV)/function_setenv.c\
		$(BULIT_IN)/$(SETENV)/env_exist.c\
		$(BULIT_IN)/$(SETENV)/get_index_env.c

TO_TEST = 	$(SOURCE_DIR)$(UTILS)/my_strlen.c\
			$(SOURCE_DIR)$(UTILS)/my_strncmp.c\
			$(SOURCE_DIR)$(UTILS)/my_strdup.c\
			$(SOURCE_DIR)$(UTILS)/length_tab.c\
			$(SOURCE_DIR)$(UTILS)/my_str_isalpha.c\
			$(SOURCE_DIR)$(UTILS)/my_strcmp.c\
			$(SOURCE_DIR)$(UTILS)/my_putchar.c\
			$(SOURCE_DIR)$(UTILS)/my_putstr.c\
			$(SOURCE_DIR)$(UTILS)/my_put_nbr.c\
			$(SOURCE_DIR)$(UTILS)/$(WORD_ARRAY)/my_strlen_index.c\
			$(SOURCE_DIR)$(UTILS)/$(WORD_ARRAY)/my_alphanum.c\
			$(SOURCE_DIR)$(UTILS)/$(WORD_ARRAY)/my_nbr_mot.c\
			$(SOURCE_DIR)$(UTILS)/$(WORD_ARRAY)/nbr_word_separator.c\
			$(SOURCE_DIR)$(UTILS)/$(WORD_ARRAY)/loop_separator.c\
			$(SOURCE_DIR)$(UTILS)/strcat_dup.c\
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
