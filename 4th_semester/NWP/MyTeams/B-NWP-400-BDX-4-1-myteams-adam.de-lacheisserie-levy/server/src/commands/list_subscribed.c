/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** list_subscribed
*/

#include "../../../include/server.h"
#include "../../include/protos_srv.h"
#include "../../include/macros.h"

static int check_before(client_t *client)
{
    if (!client->user) {
        dprintf(client->client_socket, "500\n");
        return ERROR;
    }
    return SUCCESS;
}

static int find_index_team(user_t *user, char *uuid)
{
    char tmpUuid[37];

    for (int i = 0; i < user->nb_team; i += 1) {
        uuid_unparse(user->teams[i].uuid, tmpUuid);
        if (strcmp(tmpUuid, uuid) == 0)
            return i;
    }
    return -1;
}

int list_subscriptions(my_teams_t *team, client_t *client)
{
    char *line = "";

    for (int i = 0; i < client->user->nb_team; i += 1) {
        if (!client->user->teams[i].is_subscribe)
            continue;
        uuid_unparse(client->user->teams[i].uuid, team->tmpUuid);
        line = my_strcat_dup(line, " ",
        my_strcat_dup("\"", team->tmpUuid,
        my_strcat_dup("\"", " ",
        my_strcat_dup("\"", client->user->teams[i].name,
        my_strcat_dup("\"", " ",
        my_strcat_dup("\"",
        client->user->teams[i].team_description, "\""))))));
    }
    dprintf(client->client_socket, "600 %s\n", line);
    if (strlen(line) != 0)
        free(line);
    return SUCCESS;
}

int list_subscribed_team(my_teams_t *team, client_t *client, char *uuid)
{
    char *to_concat = "";
    char tmpUuid[37];
    int index_team = 0;

    for (int i = 0; i < team->nb_users; i += 1) {
        index_team = find_index_team(team->users, uuid);
        if (index_team < 0 || !team->users[i].teams[index_team].is_subscribe)
            continue;
        uuid_unparse(team->users[i].uuid, tmpUuid);
        to_concat = my_strcat_dup(to_concat, " ", my_strcat_dup("\"", tmpUuid,
        my_strcat_dup("\"", " ",
        my_strcat_dup("\"", team->users[i].user_name,
        my_strcat_dup("\"", " ",
        my_strcat_dup("\"",
        int_to_string(team->users[i].is_logged), "\""))))));
    }
    dprintf(client->client_socket, "110 %s\n", to_concat);
    if (strlen(to_concat) != 0)
        free(to_concat);
    return SUCCESS;
}

int list_subscribed(my_teams_t *team, char **cmd, client_t *client)
{
    if (check_before(client) == ERROR)
        return SUCCESS;
    if (cmd[1])
        return list_subscribed_team(team, client, cmd[1]);
    return list_subscriptions(team, client);
}
