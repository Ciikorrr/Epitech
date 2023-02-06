/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-BSQ-marius.marolleau
** File description:
** my_bsq
*/
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include "struct_bsq.h"
#include "protos.h"
#include "macros.h"
#include <stdlib.h>

void compare(struct arg_bsq *square, int x, int y, int height)
{
    if (square->square_size - 1 > square->size) {
        square->size = square->square_size - 1;
        square->row = x;
        square->col = y;
    }
}

void check_square(struct arg_bsq *square, char **map, int x, int y)
{
    square->result = is_square_of_size(map, x, y, square->square_size);
    while (square->result == 0) {
        square->square_size += 1;
        square->result = is_square_of_size(map, x, y, square->square_size);
    }
}

char **display_square(struct arg_bsq *square, char **map)
{
    for (int x = square->row; map[x] != NULL
    && x < square->size + square->row; x += 1) {
        for (int y = square->col; map[x][y] != '\0'
        && y < square->size + square->col; y += 1) {
            map[x][y] = 'x';
        }
    }
    return map;
}

char **extension_bsq(int width, int height, char **map, struct arg_bsq square)
{
    for (int x = 1; x < height; x += 1) {
        for (int y = 0; y < width; y += 1) {
            check_square(&square, map, x, y);
            compare(&square, x, y, height);
        }
    }
    display_square(&square, map);
}

char **my_bsq(char **map)
{
    int height = 0;
    int width = 0;
    struct arg_bsq square = {0,1,0,0,0};
    width = nb_char(map[1], 0);
    height = lenght_map(map, height);
    int verif = my_getnbr(map[0]);
    if (verif != height) {
        exit(ERROR_EPITECH);
    }
    if (height == 1) {
        map = single_line(map);
    } else {
        extension_bsq(width, height, map, square);
    }
    return map;
}
