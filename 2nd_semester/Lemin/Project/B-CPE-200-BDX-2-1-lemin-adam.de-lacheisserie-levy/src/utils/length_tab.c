/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-lemin-adam.de-lacheisserie-levy
** File description:
** length_tab
*/

#include <unistd.h>

int length_tab(char **tab)
{
    int i = 0;
    for (; tab[i] != NULL; i += 1);
    return i;
}
