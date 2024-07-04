##
## EPITECH PROJECT, 2022
## makefile
## File description:
## Make
##

BINARY_PATH 	:=	$(shell stack path --local-install-root)
NAME 			= 	wolfram

all:
	stack build
	cp $(BINARY_PATH)/bin/wolfram-exe ./$(NAME)

clean:
	stack clean

fclean: clean
	rm -f $(NAME)
	rm -rf .stack-work

re: fclean all

.PHONY: all clean fclean re
