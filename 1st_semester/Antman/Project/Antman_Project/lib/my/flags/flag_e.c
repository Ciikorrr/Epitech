/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-theophile.combes
** File description:
** flag_e
*/

#include <stdarg.h>
#include "../my.h"

int flag_e(va_list list, int count, attributes_t flag_t)
{
    double i = va_arg(list, double);
    if (i > 1) {
        count += positiveexp(i, count);
    }
    if (i > 0 && i < 1) {
        count += negativeexp(i, count);
    }
    if (i == 0) {
        my_put_nbr(0);
        count += 1;
    }
    return count;
}
