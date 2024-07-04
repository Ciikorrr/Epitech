/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** free_tab
*/

#include <stdlib.h>
#include <stdbool.h>

bool free_tab(char **tab)
{
    if (!tab)
        return false;
    for (int i = 0; tab[i]; i++) {
        free(tab[i]);
    }
    free(tab);
    return true;
}
