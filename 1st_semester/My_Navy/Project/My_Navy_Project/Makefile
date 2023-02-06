##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## project makefile
##

SOURCE_DIR = src

LIB_DIR = ../lib/my/src

FUNCTION_NUM = function_num

FUNCTION_STR = function_str

SRC =	$(SOURCE_DIR)/error_handling/check_errors.c\
		$(SOURCE_DIR)/error_handling/display.c

SRC_MAIN = $(SOURCE_DIR)/main.c

OBJ	=	$(SRC:.c=.o) $(SRC_MAIN:.c=.o)

NAME	=	navy

CFLAGS = -Wall -Wextra

CPPFLAGS = -I ./include

LDFLAGS  = -L ./src/game_navy/ -lnavy -L ./src/create_map/ -lmap -L\
./src/signal/ -lsignal -L ./src/utils/ -lutils -L./lib/ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	make -C src/signal
	make -C src/utils
	make -C src/game_navy
	make -C src/create_map
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS)

clean:
	find -name "#*#" -delete -o -name "*~" -delete
	rm -rf *.log \
	rm *.gcno \
	rm *.gcda \
	rm -f $(OBJ)

fclean:	clean
	make fclean -C lib/my
	make fclean -C $(SOURCE_DIR)/signal
	make fclean -C $(SOURCE_DIR)/game_navy
	make fclean -C $(SOURCE_DIR)/create_map
	make fclean -C $(SOURCE_DIR)/utils
	rm -f unit_tests
	rm -f $(NAME)

re: fclean all

unit_tests: fclean $(NAME)
		gcc tests/*.c \
		src/error_handling/check_errors.c\
		src/create_map/check_caracters.c\
		src/create_map/check_position.c\
		src/create_map/check_script.c\
		src/utils/file_to_str.c\
		src/utils/bin_to_dec.c \
		lib/my/src/function_str/my_strlen.c\
		lib/my/src/function_num/my_compute_power_rec.c\
		$(CPPFLAGS) $(CFLAGS) \
		-L ./include/\
		-lcriterion --coverage -o unit_tests -I ./include

tests_run: unit_tests
			./unit_tests

.PHONY: all clean fclean re
