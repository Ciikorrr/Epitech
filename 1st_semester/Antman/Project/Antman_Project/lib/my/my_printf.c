/*
** EPITECH PROJECT, 2022
** parsing test
** File description:
** ouais
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct_flag.h"
#include "struct_att.h"
#include "my.h"

int my_strlen(char const *str);

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int is_flag(char format)
{
    for (int i = 0; i < TAB_SIZE; i = i + 1) {
        if (format == tab_flag[i].flag)
            return (i);
    }
    return (-1);
}

int find_precision(char const *format, int i)
{
    int res = 0;
    for (int index = i; is_num(format[index]) == 1; index += 1) {
        res = ((res * 10) + (format[index] - '0'));
    }
    return res;
}

int find_arg(char const *format, int i, int *precision, int *flag)
{
    while (i < my_strlen(format)) {
        if (format[i] == '.') {
            i = i + 1;
            *precision = find_precision(format, i);
        }
        if (is_flag(format[i]) != -1) {
            *flag = is_flag(format[i]);
            return (i);
        }
        i += 1;
    }
    return (i);
}

int my_printf(char const *format, ...)
{
    attributes_t *flag_att = malloc(sizeof(attributes_t));
    int flag = 0, count = 0, precision = -1;
    va_list list;
    va_start(list, format);
    for (int i = 0; i < my_strlen(format); i = i + 1) {
        if (format[i] == '%') {
            i = find_arg(format, (i + 1), &precision, &flag);
            flag_att->precision = precision;
            count = tab_flag[flag].function(list, count, *flag_att);
            continue;
        }
        if (format[i] != '\0') {
            my_putchar(format[i]);
            count += 1;
        }
    }
    va_end(list);
    return (count);
}
