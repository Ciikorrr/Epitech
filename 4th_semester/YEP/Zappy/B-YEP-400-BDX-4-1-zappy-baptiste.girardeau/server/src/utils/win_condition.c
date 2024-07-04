/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** win_condition
*/

#include "server.h"

bool is_winning(zappy_t *zappy)
{
    int win = 0;

    for (int i = 0; i < zappy->server.nb_clients; i += 1) {
        if (!zappy->clients[i].player)
            continue;
        if (zappy->clients[i].player->inc_level == 8)
            win += 1;
    }
    if (win >= 6)
        return true;
    return false;
}
