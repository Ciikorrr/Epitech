/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** get_user
*/

#include "../../../include/server.h"
#include "../../include/macros.h"

int display_info_user(user_t *requester, user_t *requested)
{
    char tmpUuid[37];

    uuid_unparse(requested->uuid, tmpUuid);
    dprintf(requester->client_socket[0],
    "100 \"%s\" \"%s\" \"%d\"\n", tmpUuid,
    requested->user_name, requested->is_logged);
    return SUCCESS;
}

int get_user(my_teams_t *team, char **cmd, client_t *client)
{
    char tmpUuid[37];

    if (!cmd[1]) {
        dprintf(client->client_socket, "300\n");
        return ERROR;
    }
    if (!client->user) {
        dprintf(client->client_socket, "500\n");
        return SUCCESS;
    }
    for (int i = 0; i < team->nb_users; i++) {
        if (!team->users[i].user_name)
            continue;
        uuid_unparse(team->users[i].uuid, tmpUuid);
        if (strcmp(tmpUuid, cmd[1]) == 0)
            return display_info_user(client->user, &team->users[i]);
    }
    dprintf(client->client_socket, "400 \"%s\"\n", cmd[1]);
    return SUCCESS;
}
