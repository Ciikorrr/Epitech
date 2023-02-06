/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include "macros_error.h"
#include "protos_struct.h"
#include "protos_map.h"
#include "protos.h"

int end_game(navy_t *navy)
{
    my_printf("my positions:\n");
    show_map(navy->map);
    my_printf("\nenemy's positions:\n\n");
    show_map(navy->enemy_map);
    if (navy->win == 0) {
        my_printf("\nEnemy won\n\n");
        return LOSE;
    } else {
        my_printf("\nI won\n\n");
    }
    return SUCCESS_EPITECH;
}
