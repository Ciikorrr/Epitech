/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** ouais
*/

#include <stdio.h>
#include <string.h>

char *my_strncpy(char *dest, char const *src, size_t size)
{
    int i = 0;
    for (i = 0; i < size && src[i] != '\0'; i = i + 1)
        dest[i] = src[i];
    while (i < size) {
        dest[i] = '\0';
        i = i + 1;
    }
    return (dest);
}
