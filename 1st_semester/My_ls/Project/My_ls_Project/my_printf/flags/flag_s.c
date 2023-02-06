/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-theophile.combes
** File description:
** flag_s
*/
#include <stdarg.h>
#include "../my.h"
#include <stdlib.h>

int flag_s(va_list list, int count, attributes_t flag_att)
{
    char *temp = va_arg(list, char*);
    if (temp == NULL)
        return 0;
    if (flag_att.precision != -1) {
        for (int i = 0; i < flag_att.precision; i += 1) {
            my_putchar(temp[i]);
            count += 1;
        }
        return count;
    }
    my_putstr(temp);
    count += my_strlen(temp);
    return count;
}
