##
## EPITECH PROJECT, 2022
## makefile
## File description:
## Make
##
SRC = 	main.hs \
		src/Ope.hs \
		src/OperationsSender.hs \
		src/Parsing.hs \
		src/Push_verif.hs


NAME = pushswap_checker

$(NAME):
	ghc -o $(NAME) $(SRC)

all:	$(NAME)

clean:
	rm -rf *~
	rm -rf *.hi
	rm -rf *.o
	rm -rf src/*.o
	rm -rf src/*.hi

fclean: clean
	rm -rf $(NAME)

re:	fclean all
