/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-theophile.combes
** File description:
** flag_x
*/

#include <stdarg.h>
#include "../my.h"

int flag_x(va_list list, int count, attributes_t flag_att)
{
    int precision = flag_att.precision;
    my_putnbr_base(va_arg(list, int), "0123456789abcdef", &count, precision);
    return count;
}
