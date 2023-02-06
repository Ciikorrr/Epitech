/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-theophile.combes
** File description:
** flag_per
*/

#include <stdarg.h>
#include "../my.h"

int flag_per(va_list list, int count, attributes_t)
{
    my_putchar('%');
    count += 1;
    return count;
}
