/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** free_tab
*/
#include <stdlib.h>

void free_tab(char **tab)
{
    if (!tab)
        return;
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
    return;
}
