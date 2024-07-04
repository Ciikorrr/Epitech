/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** free_zappy
*/

#include "server.h"
#include "utils.h"

static void free_teams(zappy_t *zappy)
{
    for (int i = 0; i < zappy->nb_teams; i += 1)
        free(zappy->teams[i].name);
    free(zappy->teams);
}

static void free_players(zappy_t *zappy)
{
    for (int i = 0; i < zappy->server.nb_clients; i += 1)
        if (zappy->clients[i].player)
            free(zappy->clients[i].player);
}

char **free_tab(char **tab)
{
    if (!tab)
        return NULL;
    for (int i = 0; tab[i] != NULL; i += 1)
        free(tab[i]);
    free(tab);
    return NULL;
}

static void free_teams_eggs(zappy_t *zappy)
{
    for (int i = 0; i < zappy->nb_teams; i += 1) {
        free_eggs(&zappy->teams[i]);
    }
}

void free_zappy(zappy_t *zappy)
{
    close(zappy->server.socket_fd);
    free_map(zappy);
    free_teams_eggs(zappy);
    free_teams(zappy);
    free_players(zappy);
    if (zappy->gui)
        free(zappy->gui);
}
