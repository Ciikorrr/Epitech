##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

all :
	make -C ./antman
	make -C ./giantman

clean :
		make clean -C ./antman
		make clean -C ./giantman

fclean : clean
	make fclean -C ./lib/my
	make fclean -C ./antman
	make fclean -C ./giantman

re : fclean all

.PHONY : all clean fclean re
