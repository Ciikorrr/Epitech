/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** teams
*/

#include "server.h"

void print_teams(zappy_t *zappy, char **cmd)
{
    if (!zappy->gui)
        return;
    (void)cmd;
    for (int i = 0; i < zappy->nb_teams; i += 1)
        dprintf(zappy->gui->client_socket, "tna %s\n", zappy->teams[i].name);
}
