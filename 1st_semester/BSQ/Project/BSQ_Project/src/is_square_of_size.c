/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-bsbsq-marius.marolleau
** File description:
** is_square_of_size
*/
#include <unistd.h>
#include <stdio.h>
#include "macros.h"

int comparaison(char **map, int *x, int *y, int *count)
{
    if (!(map[*x][*y] == '.')) {
        return 1;
    }
    *count += 1;
    return SUCCESS_EPITECH;
}

int is_square_of_size(char **map, int row, int col, int square_size)
{
    int stop = 0;
    int count = 0;
    for (int x = row; map[x] != NULL &&
    x < square_size + row && !stop; x += 1) {
        for (int y = col; map[x][y] != '\0' &&
        y < square_size + col && !stop; y += 1) {
            stop = comparaison(map, &x, &y, &count);
        }
    }
    if (stop == 1)
        return -1;
    if (count < (square_size * square_size)) {
        return -1;
    }
    return SUCCESS_EPITECH;
}
