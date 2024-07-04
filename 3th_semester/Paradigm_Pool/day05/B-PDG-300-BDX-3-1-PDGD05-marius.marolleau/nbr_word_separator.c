/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include "string.h"

int nbr_word_separator(char *str, char *separator)
{
    int nb = 0;
    int i = 0;

    while (loop_separator(str[i], separator) == 0) {
        i += 1;
    }
    for (; str[i] != '\0' && str[i] != '\n'; i += 1) {
        if ((loop_separator(str[i], separator) == 1 &&
        loop_separator(str[i + 1], separator) == 0) ||
        (loop_separator(str[i], separator) == 1 && str[i + 1] == '\0')) {
            nb += 1;
        }
    }
    return nb;
}
