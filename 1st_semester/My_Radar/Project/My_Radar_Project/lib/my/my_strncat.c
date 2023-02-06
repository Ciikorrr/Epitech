/*
** EPITECH PROJECT, 2022
** my_programm
** File description:
** programm
*/

#include <stddef.h>

char *my_strncat(char *dest,char const *src, int nb)
{
    int i = 0;
    while (dest[i] != '\0') {
        i += 1;
    }
    int a = 0;
    while (src[a] != '\0') {
        a += 1;
    }
    for (int e = 0; e < a && e < nb; e += 1) {
        dest[i + e] = src[e];
    }
    dest[i + a + 1] = '\0';
    return dest;
}
