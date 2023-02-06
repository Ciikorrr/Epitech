##
## EPITECH PROJECT, 2022
## B-CPE-110-BDX-1-1-pushswap-marius.marolleau
## File description:
## Makefile
##

SOURCE_MY = my/

SRC =	$(addprefix $(SOURCE_MY), my_putchar.c)\
		$(addprefix $(SOURCE_MY), my_putstr.c)\
		$(addprefix $(SOURCE_MY), my_put_nbr.c)\
		$(addprefix $(SOURCE_MY), my_putnbr_base.c)\
		$(addprefix $(SOURCE_MY), my_put_float_nbr.c)\
		$(addprefix $(SOURCE_MY), my_numberlen.c)\
		$(addprefix $(SOURCE_MY), my_strlen.c)\
		$(addprefix $(SOURCE_MY), my_revstr.c)\
		$(addprefix $(SOURCE_MY), my_put_unsignednbr.c)\
		$(addprefix $(SOURCE_MY), my_compute_power_rec.c)\
		my_printf.c\
		exposant.c\
		exposantmaj.c\
		flags/flag_a.c\
		flags/flag_aa.c\
		flags/flag_c.c\
		flags/flag_e.c\
		flags/flag_ee.c\
		flags/flag_g.c\
		flags/flag_gg.c\
		flags/flag_hh.c\
		flags/flag_id.c\
		flags/flag_j.c\
		flags/flag_l.c\
		flags/flag_ll.c\
		flags/flag_m.c\
		flags/flag_n.c\
		flags/flag_o.c\
		flags/flag_p.c\
		flags/flag_per.c\
		flags/flag_q.c\
		flags/flag_s.c\
		flags/flag_t.c\
		flags/flag_u.c\
		flags/flag_x.c\
		flags/flag_xx.c\
		flags/flag_z.c\
		flags/flag_zz.c\
		flags/flag_b.c

CPPFLAGS = -I include/

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f *.gc*
		rm -f unit_tests

re: fclean all

unit_tests: fclean $(OBJ)
		gcc  test/test.c flags/*.c \
		$(SRC) \
		-lcriterion --coverage -o unit_tests \

tests_run: unit_tests
		./unit_tests
