/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdio.h>
#include <stdlib.h>
#include "macros_error.h"
#include "protos_struct.h"
#include "protos_map.h"

char **create_empty_map(void)
{
    char **tab = malloc(sizeof(char *) * 9);
    if (tab == NULL)
        return NULL;
    tab[8] = NULL;
    for (int i = 0; i < 8; i += 1) {
        tab[i] = malloc(sizeof(char) * 9);
        if (tab[i] == NULL)
            return NULL;
        tab[8] = '\0';
    }
    for (int i = 0; tab[i] != NULL; i += 1) {
        for (int j = 0; j < 8; j += 1) {
            tab[i][j] = '.';
        }
    }
    return tab;
}

char **loop(char **tab, int *size, char *line)
{
    if (*size <= 4) {
        if (error_script(line, *size) == ERROR_EPITECH)
            return NULL;
        *size += 1;
    } else {
        return NULL;
    }
    tab = add_boat_on_map(line, tab);
    if (tab == NULL)
        return NULL;
    return tab;
}

char **create_map(char **tab, char const *filepath)
{
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    int size = 1;

    stream = fopen(filepath, "r");
    if (stream == NULL) {
        return NULL;
    }
    while ((nread = getline(&line, &len, stream)) != -1) {
        tab = loop(tab, &size, line);
        if (tab == NULL)
            return NULL;
    }
    free(line);
    fclose(stream);
    return tab;
}
