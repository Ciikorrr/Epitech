/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** ouais
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int len = my_strlen(src);
    dest = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i += 1)
        dest[i] = src[i];
    dest[len] = '\0';
    return dest;
}
