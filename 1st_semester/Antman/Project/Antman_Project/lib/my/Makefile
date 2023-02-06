##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## ouais
##

SRC	=	my_compute_square_root.c	\
		my_putstring_base.c			\
		my_evil_str.c				\
		my_find_prime_sup.c			\
		my_getnbr.c					\
		my_isneg.c 					\
		my_is_prime.c				\
		my_print_alpha.c			\
		my_print_digits.c			\
		my_print_revalpha.c			\
		my_putchar.c				\
		my_put_nbr.c				\
		my_putstr.c					\
		my_revstr.c					\
		my_showmem.c				\
		my_showstr.c				\
		my_sort_int_array.c			\
		my_strcapitalize.c			\
		my_strcat.c					\
		my_strcmp.c					\
		my_strcpy.c					\
		my_str_isalpha.c			\
		my_str_islower.c			\
		my_str_isnum.c				\
		my_str_isprintable.c		\
		my_str_isupper.c			\
		my_strlen.c					\
		my_strlowcase.c				\
		my_strncmp.c				\
		my_strncpy.c				\
		my_strstr.c					\
		my_strupcase.c				\
		my_swap.c					\
		my_strdup.c					\
		my_str_to_word_array.c		\
		my_show_word_array.c 		\
		my_putnbr_base.c 			\
		flags/flag_a.c 				\
		flags/flag_aa.c 			\
		flags/flag_bigl.c 			\
		flags/flag_c.c 				\
		flags/flag_e.c 				\
		flags/flag_ee.c 			\
		flags/flag_f.c 				\
		flags/flag_ff.c 			\
		flags/flag_g.c 				\
		flags/flag_gg.c 			\
		flags/flag_hh.c 			\
		flags/flag_id.c 			\
		flags/flag_j.c 				\
		flags/flag_l.c 				\
		flags/flag_ll.c 			\
		flags/flag_m.c 				\
		flags/flag_n.c 				\
		flags/flag_o.c 				\
		flags/flag_p.c 				\
		flags/flag_per.c 			\
		flags/flag_q.c 				\
		flags/flag_s.c 				\
		flags/flag_t.c 				\
		flags/flag_u.c 				\
		flags/flag_x.c 				\
		flags/flag_xx.c 			\
		flags/flag_z.c 				\
		flags/flag_zz.c 			\
		flags/flag_f.c 				\
		flags/flag_ff.c				\
		flags/flag_b.c 				\
		my_put_unsignednbr.c 		\
		my_printf.c 				\
		exposant.c 					\
		exposantmaj.c 				\
		my_compute_power_rec.c		\
		my_numberlen.c 				\
		my_put_float_nbr.c 	 		\
		is_valid_file.c 			\
		find_number_occurences.c 	\
		my_split.c 					\
		my_special_getnbr.c 		\
		get_script.c 				\
		file_to_buffer.c 			\
		error_handling.c 			\
		is_num.c 					\
		count_number.c 				\
		my_slice.c					\
		my_slice_bis.c 				\
		my_itoa.c

OBJ =	$(SRC:.c=.o)

NAME =	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		mkdir -p ../../include
		cp $(NAME) ../
		cp my.h ../../include/

clean:
		rm -f $(OBJ)
		make -C tests clean

fclean: clean
		rm -f $(NAME)
		rm -f ../$(NAME)
		make -C tests fclean

re:		fclean all

tests_run:
		make -C tests

.PHONY: all clean fclean re tests_run
