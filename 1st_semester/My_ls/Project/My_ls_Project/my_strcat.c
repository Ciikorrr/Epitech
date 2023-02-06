/*
** EPITECH PROJECT, 2022
** my_programm
** File description:
** programm
*/

#include <stddef.h>
#include <stdlib.h>

int len(char const *l)
{
    int i = 0;
    while (l[i] != '\0') {
        i += 1;
    }
    return i;
}

char *my_strcat(char *dest, char const *src)
{
    int t1 = len(dest);
    int t2 = len(src);
    int e = 0;
    char *new_str = malloc(sizeof(char) * t1 + t2 + 1);
    for (int i = 0; i <= t1; i += 1) {
        new_str[i] = dest[i];
        e = i;
    }
    for (int j = 0; j <= t2; j += 1) {
        new_str[e] = src[j];
        e += 1;
    }
    new_str[e] = '\0';
    return new_str;
}
