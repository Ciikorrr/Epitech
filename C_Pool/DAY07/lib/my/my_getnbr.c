/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** get number
*/

#include <unistd.h>
#include <stdio.h>

void my_putchar(char c);

int control(int i, char const *str, int is_neg)
{
    if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9')) {
        is_neg = -1;
    }
    return is_neg;
}

int add(int i, char const *str)
{
    if (str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')) {
        i += 1;
    }
    return i;
}

int my_getnbr(char const *str)
{
    int res = 0;
    int is_neg = 1;
    int i = 0;
    while (str[i] != '\0') {
        is_neg = control(i, str, is_neg);
        if (str[i] >= '0' && str[i] <= '9') {
            res = res * 10;
            res += (str[i] - 48);
        }
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+') {
            return res * is_neg;
        }
        i = add(i, str);
    }
    return res * is_neg;
}
