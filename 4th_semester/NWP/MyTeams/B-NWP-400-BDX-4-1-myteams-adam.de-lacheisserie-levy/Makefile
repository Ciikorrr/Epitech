##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

TO_TEST = 	server/src/error_handling/check_args_srv.c\
			server/src/utils/string_is_num.c\
			server/src/utils/my_strcat_dup.c\
			server/src/utils/free_tab.c\
			tests/test_parser.c\
			server/src/utils/command_parser.c

all:
	make -C server/
	make -C client/

clean:
	make clean -C server/
	make clean -C client/
	rm -rf myteams_server
	rm -rf myteams_cli
	rm -rf *gcno
	rm -rf *gcda
	rm -rf unit_tests

fclean:	clean
	make fclean -C server/
	make fclean -C client/

debug:
	make debug -C server/
	make debug -C client/

re: fclean all

unit_tests: fclean $(NAME)
		@gcc $(TO_TEST) \
		-lcriterion --coverage -o unit_tests -I ./include

tests_run: unit_tests
			./unit_tests

.PHONY: all clean fclean re
