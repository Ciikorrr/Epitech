/*
** EPITECH PROJECT, 2023
** my_navy.c
** File description:
** ouais
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "protos_struct.h"
#include "protos_game.h"
#include "protos.h"
#include "macros_error.h"
#include "protos_map.h"

int game_loop_two(navy_t *navy)
{
    while (navy->win == -1) {
        my_printf("my positions:\n");
        show_map(navy->map);
        my_printf("\nenemy's positions:\n");
        show_map(navy->enemy_map);
        my_printf("\nwaiting for enemy's attack...\n");
        navy = decode_signal(navy);
        navy = check_lose(navy);
        if (navy == NULL)
            return ERROR_EPITECH;
        navy = launch_attack(navy);
        my_printf("\n");
        navy = check_win(navy);
    }
    return end_game(navy);
}

int game_loop_one(navy_t *navy)
{
    while (navy->win == -1) {
        my_printf("my positions:\n");
        show_map(navy->map);
        my_printf("\nenemy's positions:\n");
        show_map(navy->enemy_map);
        navy = launch_attack(navy);
        navy = check_win(navy);
        my_printf("\nwaiting for enemy's attack...\n");
        if (navy == NULL)
            return ERROR_EPITECH;
        navy = decode_signal(navy);
        my_printf("\n");
        navy = check_lose(navy);
    }
    return end_game(navy);
}

int player_two(navy_t *navy, char **argv)
{
    navy->enemy_map = create_empty_map();
    navy->map = create_empty_map();
    if (navy->enemy_map == NULL || navy->map == NULL)
        return ERROR_EPITECH;
    navy->map = create_map(navy->map, argv[2]);
    if (navy->map == NULL)
        return ERROR_EPITECH;
    connect_player_two(argv[1]);
    return game_loop_two(navy);
}

int player_one(navy_t *navy, char **argv)
{
    navy->enemy_map = create_empty_map();
    navy->map = create_empty_map();
    if (navy->enemy_map == NULL || navy->map == NULL)
        return ERROR_EPITECH;
    navy->map = create_map(navy->map, argv[1]);
    if (navy->map == NULL)
        return ERROR_EPITECH;
    connect_player_one();
    return game_loop_one(navy);
}

int launch_game_loop(int argc, char **argv)
{
    navy_t *navy = malloc(sizeof(navy_t));
    if (navy == NULL)
        return ERROR_EPITECH;
    navy->win = -1;
    if (argc == 2 && my_strcmp("-h", argv[1]) == 0)
        display_desc();
    if (do_error_handling(argc, argv) == ERROR_EPITECH)
        return ERROR_EPITECH;
    if (argc == 3) {
        return player_two(navy, argv);
    }
    if (argc == 2) {
        return player_one(navy, argv);
    }
    return SUCCESS_EPITECH;
}
