/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** connect_nbr
*/

#include "server.h"

void display_connect_nbr(zappy_t *zappy, client_t *client, char **cmd)
{
    (void)cmd;
    if (!client->player) {
        dprintf(client->client_socket, "You're not a player.\n");
        return;
    }
    dprintf(client->client_socket, "%d\n", client->player->team->free_slot);
}
