/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** refill_map
*/

#include "server.h"
#include "utils.h"

static void fill_res(zappy_t *zappy, Ressources_t ressource)
{
    vector_t pos;

    for (int i = 0; i < zappy->max_ressources[ressource]; i += 1) {
        pos.x = random_number(0, zappy->gd.x - 1);
        pos.y = random_number(0, zappy->gd.y - 1);
        zappy->map[pos.y][pos.x].ressources[ressource] += 1;
    }
    zappy->quantity_ressources[ressource] = zappy->max_ressources[ressource];
}

void fill_ressources(zappy_t *zappy)
{
    fill_res(zappy, FOOD);
    fill_res(zappy, LINEMATE);
    fill_res(zappy, DERAUMERE);
    fill_res(zappy, SIBUR);
    fill_res(zappy, MENDIANE);
    fill_res(zappy, PHIRAS);
    fill_res(zappy, THYSTAME);
}
