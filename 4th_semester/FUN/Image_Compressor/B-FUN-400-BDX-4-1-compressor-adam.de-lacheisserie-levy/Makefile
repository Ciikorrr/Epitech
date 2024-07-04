##
## EPITECH PROJECT, 2022
## makefile
## File description:
## Make
##

NAME = imageCompressor

all:
	stack build --fast
	cp $$(stack path --local-install-root)/bin/Compressor-exe ./$(NAME)

clean:
	find . -name "*.o" -delete
	find . -name "*.hi" -delete

fclean: clean
	rm -rf $(NAME)

re:	fclean all
