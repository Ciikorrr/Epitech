/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** strdup
*/
#include <stdlib.h>

char my_putstr(char *str);


char *my_strdup(char *src)
{
    int i = 0;
    while (src[i] != '\0') {
        i += 1;
    }
    char *str;
    str = malloc(sizeof(char) * (i + 1));
    int e = 0;
    for (e = 0; e < i; e += 1) {
        str[e] = src[e];
    }
    str[i] = '\0';
    return str;
}
