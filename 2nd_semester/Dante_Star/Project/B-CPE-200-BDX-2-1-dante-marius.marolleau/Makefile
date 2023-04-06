##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SOURCE_DIR = src/

UTILS_DIR = utils

SOLVER_DIR = solver

TO_TEST = 	$(SOLVER_DIR)/$(SOURCE_DIR)/$(UTILS_DIR)/my_strlen.c		\
			$(SOLVER_DIR)/$(SOURCE_DIR)/$(UTILS_DIR)/my_putchar.c		\
			$(SOLVER_DIR)/$(SOURCE_DIR)/$(UTILS_DIR)/my_putstr.c		\
			$(SOLVER_DIR)/$(SOURCE_DIR)/$(UTILS_DIR)/file_to_str.c		\
			$(SOLVER_DIR)/$(SOURCE_DIR)/$(UTILS_DIR)/biggest_line.c		\
			$(SOLVER_DIR)/$(SOURCE_DIR)/$(UTILS_DIR)/info_tab.c			\
			$(SOLVER_DIR)/$(SOURCE_DIR)/$(UTILS_DIR)/my_strdup.c		\
			$(SOLVER_DIR)/$(SOURCE_DIR)/fill_tab.c						\
			$(SOLVER_DIR)/$(SOURCE_DIR)/init_struct.c					\
			$(SOLVER_DIR)/$(SOURCE_DIR)/map.c							\
			$(SOLVER_DIR)/$(SOURCE_DIR)/go_back.c						\
			$(SOLVER_DIR)/$(SOURCE_DIR)/error_handling.c				\
			$(SOLVER_DIR)/$(SOURCE_DIR)/$(UTILS_DIR)/print_tab.c		\
			$(SOLVER_DIR)/$(SOURCE_DIR)/do_solver.c						\
			$(SOLVER_DIR)/$(SOURCE_DIR)/free_tab.c						\
			$(SOLVER_DIR)/$(SOURCE_DIR)/movement.c						\

all :
	make -C ./solver
	make -C ./generator

clean :
		make clean -C ./solver
		make clean -C ./generator

fclean : clean
	make fclean -C ./solver
	make fclean -C ./generator
	find -name "vgcore.*" -delete
	rm -f *.log
	rm -rf unit_tests*

debug: make -C debug solver/

re : fclean all

unit_tests : fclean
		gcc tests/tests_my_strlen.c\
			tests/tests_length_map.c\
			tests/tests_do_width.c\
			tests/tests_get_line.c\
			tests/tests_get_nb_line.c\
			tests/tests_file_to_tab.c\
			tests/test_my_putchar.c\
			tests/tests_my_putstr.c\
			tests/tests_my_strdup.c\
			tests/tests_do_solver.c\
			tests/tests_map.c\
			tests/tests_error_handling.c\
			tests/tests_print_tab.c\
		$(TO_TEST)\
		-lcriterion --coverage -o ./unit_tests -I $(SOLVER_DIR)/include/.

tests_run : unit_tests
			./unit_tests

.PHONY : all clean fclean re
