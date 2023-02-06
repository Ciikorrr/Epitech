##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## ouais
##

FUNCTION_NUM = function_num

FUNCTION_STR = function_str

SOURCE_DIR = src

SRC	=	$(SOURCE_DIR)/$(FUNCTION_NUM)/my_compute_square_root.c	\
		$(SOURCE_DIR)/$(FUNCTION_NUM)/my_putstring_base.c			\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_evil_str.c	\
		$(SOURCE_DIR)/$(FUNCTION_NUM)/my_find_prime_sup.c	\
		$(SOURCE_DIR)/$(FUNCTION_NUM)/my_getnbr.c	\
		$(SOURCE_DIR)/$(FUNCTION_NUM)/my_isneg.c 	\
		$(SOURCE_DIR)/$(FUNCTION_NUM)/my_is_prime.c	\
		$(SOURCE_DIR)/my_print_alpha.c	\
		$(SOURCE_DIR)/$(FUNCTION_NUM)/my_print_digits.c	\
		$(SOURCE_DIR)/my_print_revalpha.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_putchar.c	\
		$(SOURCE_DIR)/$(FUNCTION_NUM)/my_put_nbr.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_putstr.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_revstr.c	\
		$(SOURCE_DIR)/my_showmem.c	\
		$(SOURCE_DIR)/my_showstr.c	\
		$(SOURCE_DIR)/$(FUNCTION_NUM)/my_sort_int_array.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_strcapitalize.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_strcat.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_strcmp.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_strcpy.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_str_isalpha.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_str_islower.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_str_isnum.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_str_isprintable.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_str_isupper.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_strlen.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_strlowcase.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_strncmp.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_strncpy.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_strstr.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_strupcase.c	\
		$(SOURCE_DIR)/my_swap.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_strdup.c	\
		$(SOURCE_DIR)/$(FUNCTION_STR)/my_str_to_word_array.c	\
		$(SOURCE_DIR)/my_show_word_array.c 	\
		$(SOURCE_DIR)/$(FUNCTION_NUM)/my_putnbr_base.c 		\
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
		flags/flag_b.c 		\
		$(SOURCE_DIR)/$(FUNCTION_NUM)/my_put_unsignednbr.c 	\
		$(SOURCE_DIR)/my_printf.c 			\
		$(SOURCE_DIR)/$(FUNCTION_NUM)/exposant.c 				\
		$(SOURCE_DIR)/$(FUNCTION_NUM)/exposantmaj.c 			\
		$(SOURCE_DIR)/$(FUNCTION_NUM)/my_compute_power_rec.c	\
		$(SOURCE_DIR)/$(FUNCTION_NUM)/my_numberlen.c 			\
		$(SOURCE_DIR)/$(FUNCTION_NUM)/my_put_float_nbr.c 	 	\
		$(SOURCE_DIR)/is_valid_file.c 		\
		$(SOURCE_DIR)/find_number_occurences.c 	\
		$(SOURCE_DIR)/my_split.c 					\
		$(SOURCE_DIR)/$(FUNCTION_NUM)/my_special_getnbr.c 		\
		$(SOURCE_DIR)/get_script.c 				\
		$(SOURCE_DIR)/file_to_buffer.c 			\
		$(SOURCE_DIR)/error_handling.c 			\
		$(SOURCE_DIR)/$(FUNCTION_NUM)/is_num.c 					\
		$(SOURCE_DIR)/count_number.c 				\
		$(SOURCE_DIR)/my_slice.c

OBJ =	$(SRC:.c=.o)

NAME =	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		mkdir -p ../../include
		cp $(NAME) ../
		cp include/my.h ../../include/

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f ../$(NAME)
		rm -f $(NAME)

re:		fclean all
