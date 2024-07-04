/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** refill_map
*/

#include "server.h"
#include "utils.h"

static void refill_res(zappy_t *zappy, Ressources_t ressource)
{
    vector_t pos;

    if (zappy->quantity_ressources[ressource] >=
    zappy->max_ressources[ressource])
        return;
    pos.x = random_number(0, zappy->gd.x - 1);
    pos.y = random_number(0, zappy->gd.y - 1);
    zappy->map[pos.y][pos.x].ressources[ressource] += 1;
    zappy->quantity_ressources[ressource] += 1;
}

void refill_ressources(zappy_t *zappy)
{
    refill_res(zappy, FOOD);
    refill_res(zappy, LINEMATE);
    refill_res(zappy, DERAUMERE);
    refill_res(zappy, SIBUR);
    refill_res(zappy, MENDIANE);
    refill_res(zappy, PHIRAS);
    refill_res(zappy, THYSTAME);
}
