/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** player_dead
*/

#include "server.h"
#include "utils.h"

void player_death(zappy_t *zappy, client_t *client)
{
    if (zappy->gui)
        dprintf(zappy->gui->client_socket, "pdi %d\n", client->player->id);
    dprintf(client->client_socket, "dead\n");
    pop_player(zappy, client);
    client->player->team->free_slot += 1;
    free(client->player);
    client->player = NULL;
}

void decrement_food(zappy_t *zappy)
{
    for (int i = 0; i < zappy->server.nb_clients; i += 1) {
        if (!zappy->clients[i].player)
            continue;
        if (zappy->clients[i].player->inventory[FOOD] == 0)
            player_death(zappy, &zappy->clients[i]);
        else
            zappy->clients[i].player->inventory[FOOD] -= 1;
    }
}
