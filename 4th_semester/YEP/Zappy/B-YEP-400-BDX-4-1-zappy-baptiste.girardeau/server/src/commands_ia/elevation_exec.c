/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** elevation_exec
*/

#include "server.h"
#include "utils.h"

static void print_level_in_gui(zappy_t *zappy, client_t *client, vector_t pos)
{
    if (zappy->gui) {
        dprintf(zappy->gui->client_socket, "plv %d %d\n",
        client->player->id, client->player->inc_level);
        dprintf(zappy->gui->client_socket, "pie %d %d 1\n", pos.x, pos.y);
    }
}

void increment_level(zappy_t *zappy, client_t *client, vector_t pos)
{
    print_level_in_gui(zappy, client, pos);
    for (int i = 0; i < client->player->group_size; i += 1) {
        client->player->group_incantation[i]->player->inc_level += 1;
        client->player->is_incanting = false;
        dprintf(client->player->group_incantation[i]->client_socket,
        "Current level: %d\n",
        client->player->group_incantation[i]->player->inc_level);
        print_level_in_gui(zappy, client->player->group_incantation[i], pos);
    }
    free(client->player->group_incantation);
    client->player->group_incantation = NULL;
    client->player->group_size = 0;
}

void level_one_exec(zappy_t *zappy, client_t *client)
{
    vector_t pos = client->player->coords;

    if (zappy->map[pos.y][pos.x].ressources[LINEMATE] <= 0) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    client->player->inc_level += 1;
    zappy->map[pos.y][pos.x].ressources[LINEMATE] -= 1;
    dprintf(client->client_socket,
    "Current level: %d\n", client->player->inc_level);
    client->player->is_incanting = false;
    print_level_in_gui(zappy, client, pos);
}

void level_two_exec(zappy_t *zappy, client_t *client)
{
    vector_t pos = client->player->coords;

    if (zappy->map[pos.y][pos.x].ressources[LINEMATE] <= 0 ||
        zappy->map[pos.y][pos.x].ressources[DERAUMERE] <= 0 ||
        zappy->map[pos.y][pos.x].ressources[SIBUR] <= 0 ||
        number_of_users(2, &zappy->map[pos.y][pos.x]) < 2) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    client->player->inc_level += 1;
    zappy->map[pos.y][pos.x].ressources[LINEMATE] -= 1;
    zappy->quantity_ressources[LINEMATE] -= 1;
    zappy->map[pos.y][pos.x].ressources[DERAUMERE] -= 1;
    zappy->quantity_ressources[DERAUMERE] -= 1;
    zappy->map[pos.y][pos.x].ressources[SIBUR] -= 1;
    zappy->quantity_ressources[SIBUR] -= 1;
    dprintf(client->client_socket,
    "Current level: %d\n", client->player->inc_level);
    client->player->is_incanting = false;
    increment_level(zappy, client, pos);
}

void level_three_exec(zappy_t *zappy, client_t *client)
{
    vector_t pos = client->player->coords;

    if (zappy->map[pos.y][pos.x].ressources[LINEMATE] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[PHIRAS] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[SIBUR] <= 0 ||
        number_of_users(3, &zappy->map[pos.y][pos.x]) < 2) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    client->player->inc_level += 1;
    zappy->map[pos.y][pos.x].ressources[LINEMATE] -= 2;
    zappy->quantity_ressources[LINEMATE] -= 2;
    zappy->map[pos.y][pos.x].ressources[PHIRAS] -= 2;
    zappy->quantity_ressources[PHIRAS] -= 2;
    zappy->map[pos.y][pos.x].ressources[SIBUR] -= 1;
    zappy->quantity_ressources[SIBUR] -= 1;
    dprintf(client->client_socket,
    "Current level: %d\n", client->player->inc_level);
    client->player->is_incanting = false;
    increment_level(zappy, client, pos);
}
