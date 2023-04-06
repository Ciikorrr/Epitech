/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdio.h>
#include "macros_errors.h"

int print_tab(char **map)
{
    if (map == NULL)
        return ERROR_EPITECH;
    int i = 0;
    for (i = 0; map[i + 1] != NULL; i += 1) {
        if (printf("%s\n", map[i]) < 0)
            return ERROR_EPITECH;
    }
    if (printf("%s", map[i]) < 0)
        return ERROR_EPITECH;
    return 0;
}
