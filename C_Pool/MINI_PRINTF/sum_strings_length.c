/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** sum_strings_length
*/

#include <stdarg.h>
#include <stdio.h>

int my_strlen(const char *str);

int sum_strings_length(int n, ...)
{
    int sum = 0;
    int count = 0;
    va_list list;
    va_start(list, n);
    for (int i = 0; i < n; i += 1) {
        sum = sum + my_strlen(va_arg(list, char const *));
        count += 1;
    }
    va_end(list);
    return (sum);
}
