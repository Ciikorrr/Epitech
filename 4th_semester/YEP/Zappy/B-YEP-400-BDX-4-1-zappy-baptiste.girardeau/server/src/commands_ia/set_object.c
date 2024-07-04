/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** set_object
*/

#include "server.h"
#include "utils.h"

static void manage_set
(zappy_t *z, client_t *client, vector_t pos, Ressources_t drop)
{
    client->player->inventory[drop] -= 1;
    z->map[pos.y][pos.x].ressources[drop] += 1;
    z->quantity_ressources[drop] += 1;
}

void set_object_exec(zappy_t *z, client_t *client)
{
    vector_t pos = {client->player->coords.x, client->player->coords.y};
    Ressources_t drop = client->player->res_t_g;

    if (client->player->inventory[drop] <= 0) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    manage_set(z, client, pos, drop);
    if (z->gui) {
        dprintf(z->gui->client_socket, "pdr %d %d\n", client->player->id,
        drop);
        dprintf(z->gui->client_socket, "pin %d %d %d %d %d %d %d %d %d %d\n",
        client->player->id, client->player->coords.x, client->player->coords.y,
        client->player->inventory[0], client->player->inventory[1],
        client->player->inventory[2], client->player->inventory[3],
        client->player->inventory[4], client->player->inventory[5],
        client->player->inventory[6]);
        content_tiles(z, NULL);
    }
    dprintf(client->client_socket, "ok\n");
}

void set_object(zappy_t *zappy, client_t *client, char **cmd)
{
    time_t duration = time(NULL) + (7 / zappy->freq);

    if (!cmd[1])
        return;
    if (!client->player) {
        dprintf(client->client_socket, "You're not a player.\n");
        return;
    }
    for (int i = 0; i < NB_RESSOURCES; i += 1)
        if (strcmp(cmd[1], ressources[i]) == 0) {
            push_back_task(client, duration, i, &set_object_exec);
            return;
        }
    dprintf(client->client_socket, "ko\n");
}
