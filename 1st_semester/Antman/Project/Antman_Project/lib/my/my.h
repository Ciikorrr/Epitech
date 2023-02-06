/*
** EPITECH PROJECT, 2022
** myh
** File description:
** ouais
*/


#ifndef MY_H_
    #define MY_H_
        #include <stdarg.h>
        #include "struct_att.h"

void my_putchar(char c);
int my_numberlen(int nb);
int positiveexp(double n, int count);
int negativeexp(double n, int count);
char *my_putstring_base(int nb, char const *base);
int my_putstr(char *str);
int my_compute_square_root(int nb);
int my_compute_power_rec(int nb, int p);
char *my_evil_str(char *str);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_print_digits(void);
char my_print_revalpha(void);
int my_put_nbr(int nb);
int my_putnbr_base(int nb, char const *base, int *c, int precision);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *array, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_stupcase(char *str);
void my_swap(int *a, int *b);
char **my_str_to_word_array(char const *str);
int my_show_word_array(char * const *tab);
char *my_strdup(char const *str);
int my_put_unsignednbr(unsigned int nb);
int my_strcmp(char const *s1, char const *s2);
int flag_b(va_list list, int count, attributes_t);
int flag_a(va_list list, int count, attributes_t);
int flag_aa(va_list list, int count, attributes_t);
int flag_bigl(va_list list, int count, attributes_t);
int flag_c(va_list list, int count, attributes_t);
int flag_e(va_list list, int count, attributes_t);
int flag_ee(va_list list, int count, attributes_t);
int flag_f(va_list list, int count, attributes_t);
int flag_ff(va_list list, int count, attributes_t);
int flag_g(va_list list, int count, attributes_t);
int flag_gg(va_list list, int count, attributes_t);
int flag_h(va_list list, int count, attributes_t);
int flag_hh(va_list list, int count, attributes_t);
int flag_id(va_list list, int count, attributes_t);
int flag_j(va_list list, int count, attributes_t);
int flag_l(va_list list, int count, attributes_t);
int flag_ll(va_list list, int count, attributes_t);
int flag_m(va_list list, int count, attributes_t);
int flag_n(va_list list, int count, attributes_t);
int flag_o(va_list list, int count, attributes_t);
int flag_p(va_list list, int count, attributes_t);
int flag_per(va_list list, int count, attributes_t);
int flag_q(va_list list, int count, attributes_t);
int flag_s(va_list list, int count, attributes_t);
int flag_t(va_list list, int count, attributes_t);
int flag_u(va_list list, int count, attributes_t);
int flag_x(va_list list, int count, attributes_t);
int flag_xx(va_list list, int count, attributes_t);
int flag_z(va_list list, int count, attributes_t);
int flag_zz(va_list list, int count, attributes_t);
int my_printf(char const *format, ...);
int find_n(char *str, char occurence);
char **my_split(char *str, char separator);
int is_valid_file(char *filepath);
int my_special_getnbr(char *str, int *index);
char *file_to_buffer(char *filepath, int fd);
char *get_script(char *filepath);
int check_args(int argc, char **argv);
int is_num(char c);
int count_number(char *str);
char *my_itoa(int number);

#endif // MY_H_
