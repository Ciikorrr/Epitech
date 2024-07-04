/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** get_help
*/
#include "../../../include/server.h"
#include "../../include/macros.h"

int get_help(my_teams_t *teams, char **cmd, client_t *client)
{
    (void)teams;
    if (cmd[1])
        dprintf(client->client_socket, "300\n");
    else
        dprintf(client->client_socket, "10\n");
    return SUCCESS;
}
