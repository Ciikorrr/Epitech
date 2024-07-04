/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** look
*/

#include "server.h"
#include "utils.h"

int convert(int x, int max)
{
    if (x >= 0 && x < max)
        return x;
    if (x < 0)
        return convert(max + x, max);
    if (x >= max)
        return convert(x - max, max);
}

static void read_ressources
(int nb_ressources, Ressources_t ressource, char *buf, size_t size)
{
    for (int i = 0; i < nb_ressources; i += 1)
        snprintf(buf + strlen(buf),
        size - strlen(buf) + 1, " %s", ressources[ressource]);
}

static void read_tile(tile_t tile, client_t *client, char *buf, size_t size)
{
    int size_max = tile.nbplayers;

    if (strlen(buf) == 7)
        size_max -= 1;
    for (int i = 0; i < size_max; i += 1)
        snprintf(buf + strlen(buf), size - strlen(buf), " player");
    for (int e = 0; e < tile.nb_eggs; e += 1)
        snprintf(buf + strlen(buf), size - strlen(buf), " egg");
    for (int z = 0; z < NB_RESSOURCES; z += 1) {
        if (tile.ressources[z] > 0)
            read_ressources(tile.ressources[z], z, buf, size);
    }
}

static void look_north(zappy_t *zappy, client_t *client, char *buf, size_t s)
{
    int count = 3;
    vector_t pos = {convert(client->player->coords.x - 1,
    zappy->gd.x),
    convert(client->player->coords.y - 1, zappy->gd.y)};

    for (int i = 0; i < client->player->inc_level; i += 1) {
        for (int z = 0; z < count; z += 1) {
            read_tile(zappy->map[pos.y]
            [convert(pos.x + z, zappy->gd.x)], client, buf, s);
            snprintf(buf + strlen(buf), s - strlen(buf), ",");
        }
        pos.x = convert(pos.x - 1, zappy->gd.x);
        pos.y = convert(pos.y - 1, zappy->gd.y);
        count += 2;
    }
}

static void look_east(zappy_t *zappy, client_t *client, char *buf, size_t s)
{
    int count = 3;
    vector_t pos = {convert(client->player->coords.x + 1,
    zappy->gd.x),
    convert(client->player->coords.y - 1, zappy->gd.y)};

    for (int i = 0; i < client->player->inc_level; i += 1) {
        for (int z = 0; z < count; z += 1) {
            read_tile(zappy->map[convert(pos.y + z, zappy->gd.y)]
            [pos.x], client, buf, s);
            snprintf(buf + strlen(buf), s - strlen(buf), ",");
        }
        pos.x = convert(pos.x + 1, zappy->gd.x);
        pos.y = convert(pos.y - 1, zappy->gd.y);
        count += 2;
    }
}

static void look_south(zappy_t *zappy, client_t *client, char *buf, size_t s)
{
    int count = 3;
    vector_t pos = {convert(client->player->coords.x + 1,
    zappy->gd.x),
    convert(client->player->coords.y + 1, zappy->gd.y)};

    for (int i = 0; i < client->player->inc_level; i += 1) {
        for (int z = 0; z < count; z += 1) {
            read_tile(zappy->map[pos.y]
            [convert(pos.x - z, zappy->gd.x)], client, buf, s);
            snprintf(buf + strlen(buf), s - strlen(buf), ",");
        }
        pos.x = convert(pos.x + 1, zappy->gd.x);
        pos.y = convert(pos.y + 1, zappy->gd.y);
        count += 2;
    }
}

static void look_west(zappy_t *zappy, client_t *client, char *buf, size_t s)
{
    int count = 3;
    vector_t pos = {convert(client->player->coords.x - 1,
    zappy->gd.x),
    convert(client->player->coords.y + 1, zappy->gd.y)};

    for (int i = 0; i < client->player->inc_level; i += 1) {
        for (int z = 0; z < count; z += 1) {
            read_tile(zappy->map[convert(pos.y - z, zappy->gd.y)]
            [pos.x], client, buf, s);
            snprintf(buf + strlen(buf), s - strlen(buf), ",");
        }
        pos.x = convert(pos.x - 1, zappy->gd.x);
        pos.y = convert(pos.y + 1, zappy->gd.y);
        count += 2;
    }
}

void look_function_exec(zappy_t *zappy, client_t *client)
{
    char buf[512];

    snprintf(buf, sizeof(buf), "[player");
    read_tile(zappy->map[client->player->coords.y][client->player->coords.x],
    client, buf, sizeof(buf));
    snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), ",");
    if (client->player->orientation == NORTH)
        look_north(zappy, client, buf, sizeof(buf));
    if (client->player->orientation == EAST)
        look_east(zappy, client, buf, sizeof(buf));
    if (client->player->orientation == SOUTH)
        look_south(zappy, client, buf, sizeof(buf));
    if (client->player->orientation == WEST)
        look_west(zappy, client, buf, sizeof(buf));
    snprintf(buf + strlen(buf) - 1, sizeof(buf) - strlen(buf) - 1, "]");
    dprintf(client->client_socket, "%s\n", buf);
}

void look_function(zappy_t *zappy, client_t *client, char **cmd)
{
    time_t duration = time(NULL) + (7 / zappy->freq);

    if (!client->player) {
        dprintf(client->client_socket, "You're not a player.\n");
        return;
    }
    push_back_task(client, duration, 0, &look_function_exec);
}
