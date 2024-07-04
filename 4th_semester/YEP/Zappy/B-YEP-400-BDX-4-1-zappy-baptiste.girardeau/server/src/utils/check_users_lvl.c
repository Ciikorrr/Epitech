/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** check_users_lvl
*/

#include "server.h"

int number_of_users(int level, tile_t *tile)
{
    int count = 0;
    player_list_t *tmp = tile->players;

    while (tmp) {
        if (tmp->client->player->inc_level == level)
            count += 1;
        tmp = tmp->next;
    }
    return count;
}
