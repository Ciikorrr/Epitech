/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** player_infos
*/

#include "server.h"
#include "utils.h"

void player_position(zappy_t *zappy, char **cmd)
{
    int id = 0;

    if (!cmd || !cmd[1])
        return;
    id = get_user_id(cmd[1]);
    for (int i = 0; i < zappy->server.nb_clients; i += 1) {
        if (!zappy->clients[i].player)
            continue;
        if (zappy->clients[i].player->id == id) {
            dprintf(zappy->gui->client_socket, "ppo %d %d %d %d\n",
            id, zappy->clients[i].player->coords.x,
            zappy->clients[i].player->coords.y,
            zappy->clients[i].player->orientation);
            break;
        }
    }
}

void player_level(zappy_t *zappy, char **cmd)
{
    int id = 0;

    if (!cmd || !cmd[1])
        return;
    id = get_user_id(cmd[1]);
    for (int i = 0; i < zappy->server.nb_clients; i += 1) {
        if (!zappy->clients[i].player)
            continue;
        if (zappy->clients[i].player->id == id) {
            dprintf(zappy->gui->client_socket, "plv %d %d\n",
            id, zappy->clients[i].player->inc_level);
            break;
        }
    }
}

static void print_player_inventory(zappy_t *zappy, int index, int id)
{
    dprintf(zappy->gui->client_socket, "pin %d %d %d %d %d %d %d %d %d %d\n",
    id, zappy->clients[index].player->coords.x,
    zappy->clients[index].player->coords.y,
    zappy->clients[index].player->inventory[0],
    zappy->clients[index].player->inventory[1],
    zappy->clients[index].player->inventory[2],
    zappy->clients[index].player->inventory[3],
    zappy->clients[index].player->inventory[4],
    zappy->clients[index].player->inventory[5],
    zappy->clients[index].player->inventory[6]);
}

void player_inventory(zappy_t *zappy, char **cmd)
{
    int id = 0;

    if (!cmd || !cmd[1])
        return;
    id = get_user_id(cmd[1]);
    for (int i = 0; i < zappy->server.nb_clients; i += 1) {
        if (!zappy->clients[i].player)
            continue;
        if (zappy->clients[i].player->id == id) {
            print_player_inventory(zappy, i, id);
            break;
        }
    }
}
