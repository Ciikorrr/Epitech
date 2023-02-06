/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-theophile.combes
** File description:
** flag_b
*/

#include <stdarg.h>
#include "../my.h"
#include <stdint.h>
#include <stdlib.h>

int flag_b(va_list list, int count, attributes_t flag_att)
{
    int precision = flag_att.precision;
    count += my_putnbr_base(va_arg(list, int), "01", &count, precision);
    return count;
}
