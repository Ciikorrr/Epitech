##
## EPITECH PROJECT, 2022
## makefile
## File description:
## Make
##

NAME = mypandoc

all:
	stack build --fast
	cp $$(stack path --local-install-root)/bin/Pandoc-exe ./$(NAME)

clean:
	find . -name "*.o" -delete
	find . -name "*.hi" -delete

fclean: clean
	rm -rf $(NAME)

re:	fclean all
