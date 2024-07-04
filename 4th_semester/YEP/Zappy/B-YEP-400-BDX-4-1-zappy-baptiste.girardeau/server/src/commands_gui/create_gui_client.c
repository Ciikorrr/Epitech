/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** create_gui_client
*/

#include "server.h"
#include "utils.h"

static void print_players(zappy_t *z)
{
    for (int i = 0; i < z->server.nb_clients; i += 1) {
        if (!z->clients[i].player)
            continue;
        dprintf(z->gui->client_socket, "pnw %d %d %d %d %d %s\n",
        z->clients[i].player->id, z->clients[i].player->coords.x,
        z->clients[i].player->coords.y,
        z->clients[i].player->orientation, z->clients[i].player->inc_level,
        z->clients[i].player->team->name);
        dprintf(z->gui->client_socket, "pin %d %d %d %d %d %d %d %d %d %d\n",
        z->clients[i].player->id, z->clients[i].player->coords.x,
        z->clients[i].player->coords.y,
        z->clients[i].player->inventory[0], z->clients[i].player->inventory[1],
        z->clients[i].player->inventory[2],
        z->clients[i].player->inventory[3],
        z->clients[i].player->inventory[4],
        z->clients[i].player->inventory[5],
        z->clients[i].player->inventory[6]);
        dprintf(z->gui->client_socket, "plv %d %d\n",
        z->clients[i].player->id, z->clients[i].player->inc_level);
    }
}

void create_gui_client(zappy_t *zappy, client_t *client, char **cmd)
{
    (void)cmd;
    zappy->gui = malloc(sizeof(client_t));
    if (!zappy->gui)
        return;
    zappy->gui->client_socket = client->client_socket;
    client->client_socket = -1;
    dprintf(zappy->gui->client_socket, "msz %d %d\n", zappy->gd.x,
    zappy->gd.y);
    dprintf(zappy->gui->client_socket, "sgt %d\n", zappy->freq);
    content_tiles(zappy, NULL);
    print_teams(zappy, NULL);
    print_players(zappy);
    print_eggs(zappy);
}
