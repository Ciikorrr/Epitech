##
## EPITECH PROJECT, 2024
## B-OOP-400-BDX-4-1-tekspice-marius.marolleau
## File description:
## Makefile
##

SRC	=			src/parsing/File.cpp	\
				src/parsing/Parser.cpp	\
				src/parsing/ParseCmd.cpp	\
				src/hubFunctionsManager.cpp	\
				src/loopToCircuit.cpp	\
				src/LoopFunction.cpp	\
				src/factory/Factory.cpp	\
				src/Circuit/Circuit.cpp	\
				src/components/chipsets/Component4071.cpp	\
				src/components/chipsets/Component4081.cpp	\
				src/components/chipsets/Component4030.cpp	\
				src/components/chipsets/Component4011.cpp	\
				src/components/chipsets/Component4001.cpp	\
				src/components/chipsets/Component4069.cpp	\
				src/components/AComponent.cpp	\
				src/components/gates/AndComponent.cpp	\
				src/components/inputs/ClockComponent.cpp	\
				src/components/inputs/FalseComponent.cpp	\
				src/components/inputs/InputComponent.cpp	\
				src/components/gates/NotComponent.cpp	\
				src/components/gates/OrComponent.cpp	\
				src/components/output/OutputComponent.cpp	\
				src/components/inputs/TrueComponent.cpp	\
				src/components/gates/XorComponent.cpp	\

SRC_MAIN	=	src/main.cpp


CPPFLAGS	=	-I./src/

CXX	=	g++

CXXFLAGS	=	 -W -Wall -Wextra -Werror -std=c++20

OBJ	=	$(addprefix $(SOURCE_DIR), $(SRC:.cpp=.o)) $(SRC_MAIN:.cpp=.o)

NAME	=	nanotekspice

NAME_TESTS	=	unit_tests

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) $(CFLAGS)


debug: fclean
debug: CFLAGS += -ggdb3
debug: $(NAME)

clean:
	find . -name "*.o" -delete
	find . -name "*~" -delete
	find . -name '#'*'#' -delete
	find . -name "*.gc*" -delete
	find . -name "vgcore.*" -delete

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests*

re: fclean all

.PHONY: all clean fclean re debug