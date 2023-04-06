/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include "utils.h"

void print_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i += 1) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}
