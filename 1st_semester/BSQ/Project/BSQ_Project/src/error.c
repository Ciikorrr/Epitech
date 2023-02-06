/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-BSQ-marius.marolleau
** File description:
** error
*/
#include "protos.h"
#include <stdlib.h>
#include "macros.h"
#include "struct_bsq.h"
#include <stdbool.h>

int my_isdigit_bis(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return SUCCESS_EPITECH;
}

void good_argv(char **argv)
{
    int nb = my_getnbr(argv[1]);
    int res = my_strlen(argv[2]);
    special_case(nb, argv[2]);
    if (res == 0) {
        exit(ERROR_EPITECH);
    }
    for (int i = 0; i < my_strlen(argv[1]); i += 1) {
        if (!(my_isdigit_bis(argv[1][i]))) {
            exit(ERROR_EPITECH);
        }
    }
    for (int i = 0; i < my_strlen(argv[2]); i += 1) {
        if (!(argv[2][i] == '.' || argv[2][i] == 'o')) {
            exit(ERROR_EPITECH);
        }
    }
}

char **my_bsq2(char **map)
{
    int height = 0;
    int width = 0;
    struct arg_bsq square = {0,1,0,0,0};
    width = nb_char(map[1], 0);
    height = lenght_map(map, height);
    if (height == 1) {
        map = single_line(map);
    } else {
        extension_bsq2(width, height, map, square);
    }
    return map;
}

char **extension_bsq2(int width, int height, char **map, struct arg_bsq square)
{
    for (int x = 0; x < height; x += 1) {
        for (int y = 0; y < width; y += 1) {
            check_square(&square, map, x, y);
            compare(&square, x, y, height);
        }
    }
    display_square(&square, map);
}

void special_case(int nb, char *argv)
{
    if (nb == 1 && (my_strcmp(argv, ".") == 0)) {
        my_putchar('x');
        exit(SUCCESS_EPITECH);
    }
    if (nb == 1 && (my_strcmp(argv, "o") == 0)) {
        my_putchar('o');
        exit(ERROR_EPITECH);
    }
    if (nb == 2 && (my_strcmp(argv, ".") == 0)) {
        my_putstr("xx\nxx");
        exit(SUCCESS_EPITECH);
    }
}
