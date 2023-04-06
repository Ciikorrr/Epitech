/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

char **remake_tab(char **tab, char *c)
{
    int len = length_tab(tab);
    char **new_tab = NULL;
    int i = 0;
    int index_tab = 0;
    new_tab = malloc(sizeof(char *) * (len + 1));
    while (tab[i] != NULL) {
        if (my_strncmp(c, tab[i], 1) == 0) {
            i += 2;
        } else {
            new_tab[index_tab] = my_strdup(tab[i]);
            i += 1;
            index_tab += 1;
        }
    }
    new_tab[index_tab] = NULL;
    return new_tab;
}
