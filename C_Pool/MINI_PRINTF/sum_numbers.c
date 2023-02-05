/*
** EPITECH PROJECT, 2022
** sum_numbers
** File description:
** sum_numbers
*/

#include <stdarg.h>
#include <stdio.h>

int sum_numbers(int n, ...)
{
    int sum = 0;
    int count = 0;
    va_list list;
    va_start(list, n);
    for (int i = 0; i < n; i += 1) {
        sum = sum + va_arg(list, int);
        count += 1;
    }
    va_end(list);
    return (sum);

}
