/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-adam.de-lacheisserie-levy
** File description:
** my_str_isnum
*/

#include <stdbool.h>

bool my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return false;
        i += 1;
    }
    return true;
}
