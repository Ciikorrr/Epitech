/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** get number
*/

#include <unistd.h>
#include <stdio.h>

int control(char *str)
{
    int i = 0;
    int nb = 0;
    while (str[i] != '\0') {
        if (str[i] == '-' ) {
            nb += 1;
        }
        i += 1;
    }
    if (nb % 2 != 0) {
        nb = nb * -1;
        return -1;
    }
    return 1;
}

int my_isdigit(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

int my_getnbr(char const *str)
{
    int res = 0;
    int isneg = control(str);
    int i = 0;
    if (str == NULL)
        return NULL;
    while (str[i] != '\0') {
        if (my_isdigit(str[i]) == 1 && my_isdigit(str[i + 1]) == 1) {
            res += (str[i] - 48);
            res = res * 10;
            }
        if (my_isdigit(str[i]) == 1 && my_isdigit(str[i + 1]) == 0) {
            res += (str[i] - 48);
            break;
        }
        i += 1;
    }
    res = res * isneg;
    if (res <= -214483647 || res >= 21448364)
        return 0;
    return res;
}
