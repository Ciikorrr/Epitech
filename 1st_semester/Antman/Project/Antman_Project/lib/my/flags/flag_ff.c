/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-theophile.combes
** File description:
** flag_f
*/

#include <stdarg.h>
#include "../my.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static int get_precision_t(attributes_t flag_att)
{
    if (flag_att.precision == -1)
        return 6;
    return flag_att.precision;
}

int flag_ff(va_list list, int count, attributes_t flag_att)
{
    int i = 0, j = 0, precision = get_precision_t(flag_att);
    intmax_t x = va_arg(list, double) * (my_compute_power_rec(10, precision));
    if (x < 0)
        x = x * -1;
    char *str = malloc(sizeof(char) * (my_numberlen(x) + 1));
    str[my_numberlen(x)] = '\0';
    while (x) {
        str[i++] = (x % 10) + 48;
        x = x / 10;
    }
    my_revstr(str);
    while (j < (my_strlen(str) - (precision)))
        my_putchar(str[j++]);
    if (flag_att.precision != 0)
        my_putchar('.');
    while (j < my_strlen(str))
        my_putchar(str[j++]);
    count = my_strlen(str) + 1;
    free(str);
    return count;
}
