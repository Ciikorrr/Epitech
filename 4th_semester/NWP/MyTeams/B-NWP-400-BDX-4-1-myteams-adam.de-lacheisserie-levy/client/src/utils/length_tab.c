/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** length_tab
*/

#include "../../include/macros.h"

int length_tab(char **tab)
{
    int i = 0;

    if (!tab)
        return -1;
    for (; tab[i]; i++);
    return i;
}
