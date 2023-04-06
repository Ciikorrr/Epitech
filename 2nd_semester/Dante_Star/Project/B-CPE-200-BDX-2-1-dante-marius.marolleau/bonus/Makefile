##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SOURCE_DIR = src/

UTILS_DIR = utils

SOLVER_DIR = solver

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

tests_run : unit_tests
			./unit_tests

.PHONY : all clean fclean re
