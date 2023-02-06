/*
** EPITECH PROJECT, 2022
** myh
** File description:
** ouais
*/

#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_

    #include "struct_att.h"

void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_putnbr_base(int nb, char const *base, int *c, int precision);
int my_printf(char const *format, ...);
int my_strlen(char const *str);
int my_numberlen(int nb);
char *my_revstr(char *str);
int my_compute_power_rec(int nb, int p);
int my_put_unsignednbr(unsigned int nb);
int my_strcmp(char const *s1, char const *s2);
int flag_b(va_list list, int count, attributes_t);
int flag_a(va_list list, int count, attributes_t);
int flag_aa(va_list list, int count, attributes_t);
int flag_bigl(va_list list, int count, attributes_t);
int flag_c(va_list list, int count, attributes_t);
int flag_e(va_list list, int count, attributes_t);
int flag_ee(va_list list, int count, attributes_t);
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

#endif // MY_H_
