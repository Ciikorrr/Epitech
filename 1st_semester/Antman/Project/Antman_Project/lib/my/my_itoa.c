/*
** EPITECH PROJECT, 2022
** itoa
** File description:
** ouais
*/

#include <stdlib.h>
#include <stdio.h>

int my_numberlen(int nb);
char *my_revstr(char *str);

char *my_itoa(int nb)
{
    char *au_cas_ou = "0";
    if (nb == 0)
        return au_cas_ou;
    char *str = malloc(sizeof(char) * (my_numberlen(nb) + 1));
    str[my_numberlen(nb)] = '\0';
    int i = 0;
    while (nb) {
        str[i++] = (nb % 10) + 48;
        nb = nb / 10;
    }
    my_revstr(str);
    return str;
}
