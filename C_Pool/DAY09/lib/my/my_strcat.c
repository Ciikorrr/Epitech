/*
** EPITECH PROJECT, 2022
** my_programm
** File description:
** programm
*/

#include <stddef.h>

int len(char *l)
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
    for (int i = t1; i < t2 + t1; i += 1) {
        dest[i] = src[i - t1];
    }
    dest[t1 + t2 + 1] = '\0';
    return dest;
}
