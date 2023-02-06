/*
** EPITECH PROJECT, 2022
** test
** File description:
** ouais
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

char *my_putstring_base(int nb, char const *base)
{
    int temp = nb;
    int tmp = 0;
    int len = my_strlen(base);
    int bytes = 0;
    while (temp) {
        bytes += 1;
        temp = temp / len;
    }
    int i = bytes - 1;
    char *result = malloc(sizeof(char) * (bytes + 1));
    result[bytes] = '\0';
    while (nb) {
        tmp = nb % len;
        nb = nb / len;
        result[i--] = base[tmp];
    }
    return result;
}
