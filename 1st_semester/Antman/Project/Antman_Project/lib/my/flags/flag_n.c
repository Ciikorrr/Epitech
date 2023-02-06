/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-theophile.combes
** File description:
** flag_n
*/
#include <stdarg.h>
#include "../my.h"

int flag_n(va_list list, int count, attributes_t)
{
    *va_arg(list, int *) = count;
    count -= 1;
    return count;
}
