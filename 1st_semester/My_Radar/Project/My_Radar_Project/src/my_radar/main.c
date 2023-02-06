/*
** EPITECH PROJECT, 2022
** Start_projet
** File description:
** main
*/
#include <time.h>
#include "protos.h"


int main(int argc, char **argv, const char *const *env)
{
    srand(time(NULL));
    if (description(argc, argv) == SUCCESS_EPITECH)
        return SUCCESS_EPITECH;
    if (check_arg(argc, argv, env) == ERROR_EPITECH)
        return ERROR_EPITECH;
    game_t *game = malloc(sizeof(game_t));
    if (game == NULL)
        return ERROR_EPITECH;
    if (check_script(argv) == ERROR_EPITECH)
        return ERROR_EPITECH;
    game = init_game(game);
    if (game == NULL)
        return ERROR_EPITECH;
    if (check_assets(game) == ERROR_EPITECH)
        return ERROR_EPITECH;
    game = get_info(argc, argv, game);
    if (start_radar(game) == SUCCESS_EPITECH)
        return SUCCESS_EPITECH;
    return ERROR_EPITECH;
}
