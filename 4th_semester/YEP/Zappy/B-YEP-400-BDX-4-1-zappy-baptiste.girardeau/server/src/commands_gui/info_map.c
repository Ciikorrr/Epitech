/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** info_map
*/

#include "server.h"
#include "utils.h"

void map_size(zappy_t *zappy, char **cmd)
{
    (void)cmd;
    dprintf(zappy->gui->client_socket, "msz %d %d\n",
    zappy->gd.x, zappy->gd.y);
}

void content_tile(zappy_t *zappy, char **cmd)
{
    vector_t pos;
    tile_t tile;

    if (!cmd || !cmd[1] || !cmd[2])
        return;
    pos.x = atoi(cmd[1]);
    pos.y = atoi(cmd[2]);
    tile = zappy->map[pos.y][pos.x];
    dprintf(zappy->gui->client_socket, "bct %d %d %d %d %d %d %d %d %d\n",
    pos.x, pos.y, tile.ressources[FOOD], tile.ressources[LINEMATE],
    tile.ressources[DERAUMERE], tile.ressources[SIBUR],
    tile.ressources[MENDIANE], tile.ressources[PHIRAS],
    tile.ressources[THYSTAME]);
}

static void print_content_tiles(zappy_t *zappy, vector_t pos)
{
    tile_t tile;

    tile = zappy->map[pos.y][pos.x];
    dprintf(zappy->gui->client_socket, "bct %d %d %d %d %d %d %d %d %d\n",
    pos.x, pos.y, tile.ressources[FOOD], tile.ressources[LINEMATE],
    tile.ressources[DERAUMERE], tile.ressources[SIBUR],
    tile.ressources[MENDIANE], tile.ressources[PHIRAS],
    tile.ressources[THYSTAME]);
}

void content_tiles(zappy_t *zappy, char **cmd)
{
    vector_t pos = {0, 0};

    if (!zappy->gui)
        return;
    (void)cmd;
    for (int y = 0; y < zappy->gd.y; y += 1) {
        pos.y = y;
        for (int x = 0; x < zappy->gd.x; x += 1) {
            pos.x = x;
            print_content_tiles(zappy, pos);
        }
    }
}

void freq_time(zappy_t *zappy, char **cmd)
{
    (void)cmd;
    dprintf(zappy->gui->client_socket, "sgt %d\n", zappy->freq);
}

void set_freq_time(zappy_t *zappy, char **cmd)
{
    if (!cmd[1] || !my_str_isnum(cmd[1]))
        return;
    zappy->freq = atoi(cmd[1]);
    dprintf(zappy->gui->client_socket, "sst %d\n", zappy->freq);
}
