/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include "protos.h"

int my_isdigit2(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

int check_car(char const *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (my_isdigit2(str[i]) == 0) {
            return 1;
        }
    }
    return SUCCESS_EPITECH;
}

int check_char_plane(char **tab, int i, int res)
{
    if (tab[i][0] == 'A') {
        res += check_car(tab[i + 1]);
        res += check_car(tab[i + 2]);
        res += check_car(tab[i + 3]);
        res += check_car(tab[i + 4]);
        res += check_car(tab[i + 5]);
        res += check_car(tab[i + 6]);
        if (res != 0)
            return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}

int check_char_tower(char **tab, int i, int res)
{
    if (tab[i][0] == 'T') {
        res += check_car(tab[i + 1]);
        res += check_car(tab[i + 2]);
        res += check_car(tab[i + 3]);
        if (res != 0)
            return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}
