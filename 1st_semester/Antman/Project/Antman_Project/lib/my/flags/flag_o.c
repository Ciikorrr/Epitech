/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-theophile.combes
** File description:
** flag_o
*/

#include <stdarg.h>
#include "../my.h"

int flag_o(va_list list, int count, attributes_t flag_att)
{
    my_putnbr_base(va_arg(list, int), "01234567", &count, flag_att.precision);
    return count;
}
