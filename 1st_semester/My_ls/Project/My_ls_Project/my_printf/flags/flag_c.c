/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-theophile.combes
** File description:
** flag_c
*/
#include <stdarg.h>
#include "../my.h"

int flag_c(va_list list, int count, attributes_t)
{
    my_putchar(va_arg(list, int));
    count += 1;
    return count;
}
