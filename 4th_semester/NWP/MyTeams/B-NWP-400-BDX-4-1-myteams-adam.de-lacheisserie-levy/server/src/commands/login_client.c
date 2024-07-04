/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** login_client
*/

#include "../../../include/server.h"
#include "../../include/macros.h"

int check_before(client_t *client, char **cmd)
{
    if (!cmd[1]) {
        dprintf(client->client_socket, "300\n");
        return ERROR;
    }
    if (client->user) {
        dprintf(client->client_socket, "500\n");
        return ERROR;
    }
    return SUCCESS;
}

static bool user_exists(my_teams_t *teams, int index_cli, client_t *client)
{
    client->user = &teams->users[index_cli];
    client->user->is_logged += 1;
    client->user->client_socket[client->user->nb_sockets]
    = client->client_socket;
    client->index_socket = client->user->nb_sockets;
    client->user->nb_sockets += 1;
    uuid_unparse(client->user->uuid, teams->tmpUuid);
    server_event_user_logged_in(teams->tmpUuid);
    for (int i = 0; i < teams->nb_users; i += 1)
        for (int z = 0; z < teams->users[i].nb_sockets; z += 1)
            dprintf(teams->users[i].client_socket[z],
            "210 \"%s\" \"%s\"\n", teams->tmpUuid, client->user->user_name);
    return true;
}

static bool is_user_exists(my_teams_t *teams, char *name, client_t *client)
{
    for (int i = 0; i < teams->nb_users; i += 1)
        if (strcmp(name, teams->users[i].user_name) == 0)
            return user_exists(teams, i, client);
    return false;
}

static void set_up_user(my_teams_t *teams, char **cmd, client_t *client)
{
    teams->users[teams->nb_users].nb_chats = 0;
    teams->users[teams->nb_users].chats =
    malloc(sizeof(chat_t) * DEFAULT_SIZE);
    teams->users[teams->nb_users].teams =
    malloc(sizeof(team_t) * DEFAULT_SIZE);
    uuid_generate(teams->users[teams->nb_users].uuid);
    teams->users[teams->nb_users].user_name = strdup(cmd[1]);
    teams->users[teams->nb_users].is_logged = 1;
    teams->users[teams->nb_users].context = UNDEFINED;
    teams->users[teams->nb_users].nb_team = 0;
    teams->users[teams->nb_users].client_socket[0] = client->client_socket;
    teams->users[teams->nb_users].nb_sockets = 1;
    client->index_socket = 0;
    uuid_unparse(teams->users[teams->nb_users].uuid, teams->tmpUuid);
}

int login_client(my_teams_t *teams, char **cmd, client_t *client)
{
    if (check_before(client, cmd) == ERROR)
        return SUCCESS;
    if (is_user_exists(teams, cmd[1], client))
        return SUCCESS;
    set_up_user(teams, cmd, client);
    server_event_user_created
    (teams->tmpUuid, teams->users[teams->nb_users].user_name);
    server_event_user_logged_in(teams->tmpUuid);
    client->user = &teams->users[teams->nb_users];
    teams->nb_users += 1;
    for (int i = 0; i < teams->nb_users; i += 1)
        for (int z = 0; z < teams->users[i].nb_sockets; z += 1)
            dprintf(teams->users[i].client_socket[z],
            "210 \"%s\" \"%s\"\n", teams->tmpUuid, client->user->user_name);
    return SUCCESS;
}
