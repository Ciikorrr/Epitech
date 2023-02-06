/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-theophile.combes
** File description:
** flag_ee
*/

#include <stdarg.h>
#include "../my.h"
int negativeexpm(double n);
int positiveexpm(double n);


int flag_ee(va_list list, int count, attributes_t)
{
    double i = va_arg(list, double);
    if (i > 1) {
        positiveexpm(i);
    }
    if (i < 1 && i > 0) {
        negativeexpm(i);
    }
    if (i == 0) {
        my_put_nbr(0);
    }
    return count;
}
