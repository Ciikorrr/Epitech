/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** create_team
*/
#include "../../../include/server.h"
#include "../../../include/macros.h"
#include "../../include/protos_srv.h"
#include <stdio.h>

int create(my_teams_t *teams, char **cmd, client_t *client)
{
    if (!client->user) {
        dprintf(client->client_socket, "500\n");
        return SUCCESS;
    }
    if (client->user->context == UNDEFINED)
        return create_team(teams, cmd, client);
    if (client->user->context == TEAM)
        return create_channel(teams, cmd, client);
    if (client->user->context == CHANNEL)
        return create_thread(teams, cmd, client);
    return create_comment(teams, cmd, client);
}
