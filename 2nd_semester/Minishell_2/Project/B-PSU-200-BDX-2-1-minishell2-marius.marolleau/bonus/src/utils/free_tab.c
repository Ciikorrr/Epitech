/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdlib.h>
#include <unistd.h>

int free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i += 1) {
        free(tab[i]);
    }
    free(tab);
    return 0;
}
