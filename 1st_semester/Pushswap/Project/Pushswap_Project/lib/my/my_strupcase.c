/*
** EPITECH PROJECT, 2022
** my_strupcase.c
** File description:
** upper case
*/

#include <stdio.h>

char *my_strupcase(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
        i += 1;
    }
    return str;
}
