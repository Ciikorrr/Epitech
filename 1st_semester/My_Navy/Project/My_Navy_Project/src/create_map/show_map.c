/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include "macros_error.h"
#include "protos.h"
int show_map(char **map)
{
    int i = 1;
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int j = 0; map[j] != NULL; j += 1) {
        my_printf("%d|", i);
        for (int a = 0; a < 7; a += 1) {
            my_printf("%c ", map[j][a]);
        }
        i += 1;
        my_printf("%c\n", map[j][7]);
    }
    return SUCCESS_EPITECH;
}
