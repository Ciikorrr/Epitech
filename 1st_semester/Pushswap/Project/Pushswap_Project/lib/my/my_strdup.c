/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** strdup
*/
#include <stdlib.h>

char my_putstr(char *str);

char my_putchar(char *str);

char *my_strdup(char const *src)
{
    int i = 0;
    while (src[i] != '\0') {
        i += 1;
    }
    char *str;
    str = malloc(sizeof(char) * i);
    int e = 0;
    for (e = 0; e < i; e += 1) {
        str[e] = src[e];
    }
    return str;
}
