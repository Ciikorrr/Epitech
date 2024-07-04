/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** take_object
*/

#include "server.h"
#include "utils.h"

static void manage_changes(zappy_t *z, vector_t pos, client_t *client)
{
    z->map[pos.y][pos.x].ressources[client->player->res_t_g] -= 1;
    z->quantity_ressources[client->player->res_t_g] -= 1;
    client->player->inventory[client->player->res_t_g] += 1;
}

void take_object_exec(zappy_t *z, client_t *client)
{
    vector_t pos = {client->player->coords.x, client->player->coords.y};

    if (z->map[pos.y][pos.x].ressources[client->player->res_t_g] <= 0) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    manage_changes(z, pos, client);
    if (z->gui) {
        dprintf(z->gui->client_socket, "pgt %d %d\n", client->player->id,
        client->player->res_t_g);
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

void take_object(zappy_t *zappy, client_t *client, char **cmd)
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
            push_back_task(client, duration, i, &take_object_exec);
            return;
        }
    dprintf(client->client_socket, "ko\n");
}
