/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** print_eggs
*/

#include "server.h"
#include "utils.h"

void print_egg(zappy_t *zappy, egg_t *egg)
{
    if (zappy->gui)
        dprintf(zappy->gui->client_socket, "enw %d %d %d %d\n", egg->id,
        egg->player_id, egg->pos.x, egg->pos.y);
}

void print_eggs(zappy_t *zappy)
{
    egg_t *tmp = NULL;

    for (int i = 0; i < zappy->nb_teams; i += 1) {
        tmp = zappy->teams[i].eggs;
        while (tmp) {
            print_egg(zappy, tmp);
            dprintf(zappy->gui->client_socket, "eht %d\n", tmp->id);
            tmp = tmp->next;
        }
    }
}
