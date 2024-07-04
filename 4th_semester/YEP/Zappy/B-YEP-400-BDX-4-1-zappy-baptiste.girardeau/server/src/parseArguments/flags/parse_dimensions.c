/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** parse_dimensions
*/

#include "server.h"
#include "utils.h"

int parse_height(int index, char **argv, zappy_t *zappy)
{
    if (!argv || !zappy || !argv[index] || !my_str_isnum(argv[index])) {
        printf("-y: Bad height.\n");
        return ERROR;
    }
    zappy->gd.y = atoi(argv[index]);
    if (zappy->gd.y <= 0) {
        printf("-y: Bad height.\n");
        return ERROR;
    }
    return 1;
}

int parse_width(int index, char **argv, zappy_t *zappy)
{
    if (!argv || !zappy || !argv[index] || !my_str_isnum(argv[index])) {
        printf("-x: Bad width.\n");
        return ERROR;
    }
    zappy->gd.x = atoi(argv[index]);
    if (zappy->gd.x <= 0) {
        printf("-x: Bad width.\n");
        return ERROR;
    }
    return 1;
}
