/*
** EPITECH PROJECT, 2023
** C Pool
** File description:
** tab_length
*/
#include <stdio.h>

int length_tab(char **tab)
{
    int len = 0;

    for (int i = 0; tab[i] != NULL; i += 1) {
        len += 1;
    }
    return len;
}
