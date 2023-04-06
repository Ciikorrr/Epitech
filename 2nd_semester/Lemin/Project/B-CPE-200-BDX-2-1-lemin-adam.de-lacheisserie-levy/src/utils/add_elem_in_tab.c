/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <unistd.h>
#include "macros.h"
#include "protos.h"

char **fill_new_tab(char **old_tab, char **new_tab, char *name)
{
    int i = 0;
    if (old_tab == NULL || new_tab == NULL)
        return NULL;
    for (; old_tab[i] != NULL; i += 1) {
        new_tab[i] = my_strdup(old_tab[i]);
        if (new_tab[i] == NULL)
            return NULL;
    }
    new_tab[i + 1] = my_strdup(name);
    if (new_tab[i + 1] == NULL)
        return NULL;
    return new_tab;
}
