/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-theophile.combes
** File description:
** flag_p
*/

#include <stdarg.h>
#include "../my.h"

int flag_p(va_list list, int count, attributes_t flag_att)
{
    int precision = flag_att.precision;
    count = 2;
    my_putstr("0x");
    unsigned long int result = va_arg(list, void*);
    count += my_putnbr_base(result, "0123456789ABCDEF", &count, precision);
    return count;
}
