/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** elevation_exec_two
*/

#include "server.h"
#include "utils.h"

static void decrement_ressources_four(vector_t pos, zappy_t *zappy)
{
    zappy->map[pos.y][pos.x].ressources[LINEMATE] -= 1;
    zappy->quantity_ressources[LINEMATE] -= 1;
    zappy->map[pos.y][pos.x].ressources[DERAUMERE] -= 1;
    zappy->quantity_ressources[DERAUMERE] -= 1;
    zappy->map[pos.y][pos.x].ressources[PHIRAS] -= 1;
    zappy->quantity_ressources[PHIRAS] -= 1;
    zappy->map[pos.y][pos.x].ressources[SIBUR] -= 2;
    zappy->quantity_ressources[SIBUR] -= 2;
}

void level_four_exec(zappy_t *zappy, client_t *client)
{
    vector_t pos = client->player->coords;

    if (zappy->map[pos.y][pos.x].ressources[LINEMATE] <= 0 ||
        zappy->map[pos.y][pos.x].ressources[DERAUMERE] <= 0 ||
        zappy->map[pos.y][pos.x].ressources[SIBUR] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[PHIRAS] <= 0 ||
        number_of_users(4, &zappy->map[pos.y][pos.x]) < 4) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    client->player->inc_level += 1;
    decrement_ressources_four(pos, zappy);
    dprintf(client->client_socket,
    "Current level: %d\n", client->player->inc_level);
    client->player->is_incanting = false;
    increment_level(zappy, client, pos);
}

static void decrement_ressources_five(vector_t pos, zappy_t *zappy)
{
    zappy->map[pos.y][pos.x].ressources[LINEMATE] -= 1;
    zappy->quantity_ressources[LINEMATE] -= 1;
    zappy->map[pos.y][pos.x].ressources[DERAUMERE] -= 2;
    zappy->quantity_ressources[DERAUMERE] -= 2;
    zappy->map[pos.y][pos.x].ressources[MENDIANE] -= 3;
    zappy->quantity_ressources[MENDIANE] -= 3;
    zappy->map[pos.y][pos.x].ressources[SIBUR] -= 1;
    zappy->quantity_ressources[SIBUR] -= 1;
}

void level_five_exec(zappy_t *zappy, client_t *client)
{
    vector_t pos = client->player->coords;

    if (zappy->map[pos.y][pos.x].ressources[LINEMATE] <= 0 ||
        zappy->map[pos.y][pos.x].ressources[DERAUMERE] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[SIBUR] <= 0 ||
        zappy->map[pos.y][pos.x].ressources[MENDIANE] <= 2 ||
        number_of_users(5, &zappy->map[pos.y][pos.x]) < 4) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    client->player->inc_level += 1;
    decrement_ressources_five(pos, zappy);
    dprintf(client->client_socket,
    "Current level: %d\n", client->player->inc_level);
    client->player->is_incanting = false;
    increment_level(zappy, client, pos);
}

static void decrement_ressources_six(vector_t pos, zappy_t *zappy)
{
    zappy->map[pos.y][pos.x].ressources[LINEMATE] -= 1;
    zappy->quantity_ressources[LINEMATE] -= 1;
    zappy->map[pos.y][pos.x].ressources[DERAUMERE] -= 2;
    zappy->quantity_ressources[DERAUMERE] -= 2;
    zappy->map[pos.y][pos.x].ressources[PHIRAS] -= 1;
    zappy->quantity_ressources[PHIRAS] -= 1;
    zappy->map[pos.y][pos.x].ressources[SIBUR] -= 3;
    zappy->quantity_ressources[SIBUR] -= 3;
}

void level_six_exec(zappy_t *zappy, client_t *client)
{
    vector_t pos = client->player->coords;

    if (zappy->map[pos.y][pos.x].ressources[LINEMATE] <= 0 ||
        zappy->map[pos.y][pos.x].ressources[DERAUMERE] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[SIBUR] <= 2 ||
        zappy->map[pos.y][pos.x].ressources[PHIRAS] <= 0 ||
        number_of_users(6, &zappy->map[pos.y][pos.x]) < 6) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    client->player->inc_level += 1;
    decrement_ressources_six(pos, zappy);
    dprintf(client->client_socket,
    "Current level: %d\n", client->player->inc_level);
    client->player->is_incanting = false;
    increment_level(zappy, client, pos);
}

static void decrement_ressources_seven(vector_t pos, zappy_t *zappy)
{
    zappy->map[pos.y][pos.x].ressources[LINEMATE] -= 2;
    zappy->quantity_ressources[LINEMATE] -= 2;
    zappy->map[pos.y][pos.x].ressources[DERAUMERE] -= 2;
    zappy->quantity_ressources[DERAUMERE] -= 2;
    zappy->map[pos.y][pos.x].ressources[PHIRAS] -= 2;
    zappy->quantity_ressources[PHIRAS] -= 2;
    zappy->map[pos.y][pos.x].ressources[SIBUR] -= 2;
    zappy->quantity_ressources[SIBUR] -= 2;
    zappy->map[pos.y][pos.x].ressources[MENDIANE] -= 2;
    zappy->quantity_ressources[MENDIANE] -= 2;
    zappy->map[pos.y][pos.x].ressources[THYSTAME] -= 1;
    zappy->quantity_ressources[THYSTAME] -= 1;
}

void level_seven_exec(zappy_t *zappy, client_t *client)
{
    vector_t pos = client->player->coords;

    if (zappy->map[pos.y][pos.x].ressources[LINEMATE] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[DERAUMERE] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[SIBUR] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[MENDIANE] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[PHIRAS] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[THYSTAME] <= 0 ||
        number_of_users(6, &zappy->map[pos.y][pos.x]) < 7) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    client->player->inc_level += 1;
    decrement_ressources_seven(pos, zappy);
    dprintf(client->client_socket,
    "Current level: %d\n", client->player->inc_level);
    client->player->is_incanting = false;
    increment_level(zappy, client, pos);
}
