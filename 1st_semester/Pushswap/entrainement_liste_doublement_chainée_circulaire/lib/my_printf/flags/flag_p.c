/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-theophile.combes
** File description:
** flag_p
*/

#include <stdarg.h>
#include "my.h"

int flag_p(va_list list, int count, attributes_t flag_att)
{
    int precision = flag_att.precision;
    count = 2;
    int *nbr = &list;
    my_putstr("0x");
    count += my_putnbr_base(nbr, "0123456789abcef", &count, precision);
    return count;
}
