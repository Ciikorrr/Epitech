##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## ouais
##

SRC	=	my_putchar.c 		\
		my_putstr.c 		\
		my_put_nbr.c 		\
		my_putnbr_base.c 	\
		my_printf.c			\
		my_put_float_nbr.c	\
		my_numberlen.c 		\
		my_strlen.c 		\
		my_revstr.c 		\
		exposant.c 			\
		exposantmaj.c 		\
		my_compute_power_rec.c 	\
		my_put_unsignednbr.c 	\
		flags/flag_a.c 		\
		flags/flag_aa.c 	\
		flags/flag_bigl.c 	\
		flags/flag_c.c 		\
		flags/flag_e.c 		\
		flags/flag_ee.c 	\
		flags/flag_f.c 		\
		flags/flag_ff.c 	\
		flags/flag_g.c 		\
		flags/flag_gg.c 	\
		flags/flag_hh.c 	\
		flags/flag_id.c 	\
		flags/flag_j.c 		\
		flags/flag_l.c 		\
		flags/flag_ll.c 	\
		flags/flag_m.c 		\
		flags/flag_n.c 		\
		flags/flag_o.c 		\
		flags/flag_p.c 		\
		flags/flag_per.c 	\
		flags/flag_q.c 		\
		flags/flag_s.c 		\
		flags/flag_t.c 		\
		flags/flag_u.c 		\
		flags/flag_x.c 		\
		flags/flag_xx.c 	\
		flags/flag_z.c 		\
		flags/flag_zz.c 	\
		flags/flag_f.c 		\
		flags/flag_ff.c		\
		flags/flag_b.c

CPPFLAGS = -I .

OBJ =	$(SRC:.c=.o)

NAME =	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
