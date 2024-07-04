/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** logout_client
*/

#include "../../../include/server.h"
#include "../../include/macros.h"

int logout_client(my_teams_t *teams, char **cmd, client_t *client)
{
    char tmpUuid[37];

    (void)cmd;
    if (!client->user) {
        dprintf(client->client_socket,
        "500\n");
        return SUCCESS;
    }
    client->user->is_logged -= 1;
    uuid_unparse(client->user->uuid, tmpUuid);
    server_event_user_logged_out(tmpUuid);
    for (int i = 0; i < teams->nb_users; i += 1)
        for (int z = 0; z < teams->users[i].nb_sockets; z += 1)
            dprintf(teams->users[i].client_socket[z],
            "220 \"%s\" \"%s\"\n", tmpUuid, client->user->user_name);
    client->user = NULL;
    return SUCCESS;
}
