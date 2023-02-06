/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** ouais
*/

#include <stdio.h>

int my_special_getnbr(char const *str, int *index)
{
    int res = 0;
    int s = 1;
    for (int i = *index; str[i] != '\0'; i = i + 1) {
        if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
            s = -1;
        if (str[i] >= '0' && str[i] <= '9')
            res = (res * 10 + (str[i] - '0'));
        if ((str[i] >= '0' && str[i] <= '9') &&
                (str[i + 1] < '0') || (str[i + 1] > '9')) {
            *index = i + 1;
            return (res * s);
        }
    }
    return (res * s);
}
