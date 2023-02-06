/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-theophile.combes
** File description:
** flag_u
*/

#include <stdarg.h>
#include "../my.h"

int flag_u(va_list list, int count, attributes_t flag_att)
{
    unsigned int result = va_arg(list, int);
    count = my_put_unsignednbr(result);
    return count;
}
