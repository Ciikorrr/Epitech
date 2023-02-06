/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-theophile.combes
** File description:
** flag_id
*/

#include <stdarg.h>
#include "../my.h"

int flag_id(va_list list, int count, attributes_t)
{
    count += my_put_nbr(va_arg(list, int));
    return count;
}
