/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** use_context
*/

#include "../../../include/server.h"
#include "../../include/macros.h"

static int check_before(client_t *client)
{
    if (!client->user) {
        dprintf(client->client_socket, "500\n");
        return ERROR;
    }
    return SUCCESS;
}

static int find_index_team(my_teams_t *team, char *uuid)
{
    for (int i = 0; i < team->nb_team; i += 1) {
        uuid_unparse(team->teams[i].uuid, team->tmpUuid);
        if (strcmp(team->tmpUuid, uuid) == 0)
            return i;
    }
    return -1;
}

static int find_index_channel(my_teams_t *team, char *uuid, client_t *client)
{
    int nb_channels = team->teams[client->user->tm_ctxt].nb_channels;

    for (int i = 0; i < nb_channels; i += 1) {
        uuid_unparse(team->teams[client->user->tm_ctxt]
        .channels[i].uuid, team->tmpUuid);
        if (strcmp(team->tmpUuid, uuid) == 0)
            return i;
    }
    return -1;
}

static int find_index_thread(my_teams_t *team, char *uuid, client_t *client)
{
    int nb_threads = team->teams[client->user->tm_ctxt].
    channels[client->user->chl_ctxt].nb_threads;

    for (int i = 0; i < nb_threads; i += 1) {
        uuid_unparse(team->teams[client->user->tm_ctxt]
        .channels[client->user->chl_ctxt]
        .threads[i].uuid, team->tmpUuid);
        if (strcmp(team->tmpUuid, uuid) == 0)
            return i;
    }
    return -1;
}

static int set_team_context(my_teams_t *team, char **cmd, client_t *client)
{
    int index_team = find_index_team(team, cmd[1]);

    if (index_team < 0) {
        dprintf(client->client_socket, "410 \"%s\"\n", cmd[1]);
        return ERROR;
    }
    client->user->tm_ctxt = index_team;
    if (!cmd[2]) {
        client->user->context = TEAM;
        dprintf(client->client_socket, "Context : TEAM\n");
        return ERROR;
    }
    return SUCCESS;
}

static int set_channel_context(my_teams_t *team, char **cmd, client_t *client)
{
    int index_channel = find_index_channel(team, cmd[2], client);

    if (index_channel < 0) {
        dprintf(client->client_socket, "420 \"%s\"\n", cmd[2]);
        return ERROR;
    }
    client->user->chl_ctxt = index_channel;
    if (!cmd[3]) {
        client->user->context = CHANNEL;
        dprintf(client->client_socket, "Context : CHANNEL\n");
        return ERROR;
    }
    return SUCCESS;
}

static int set_thread_context(my_teams_t *team, char **cmd, client_t *client)
{
    int index_thread = find_index_thread(team, cmd[3], client);

    if (index_thread < 0) {
        dprintf(client->client_socket, "430 \"%s\"\n", cmd[3]);
        return SUCCESS;
    }
    client->user->thd_ctxt = index_thread;
    client->user->context = THREAD;
    dprintf(client->client_socket, "Context : THREAD\n");
    return SUCCESS;
}

int use_context(my_teams_t *team, char **cmd, client_t *client)
{
    if (check_before(client) == ERROR)
        return SUCCESS;
    if (!cmd[1]) {
        client->user->context = UNDEFINED;
        return SUCCESS;
    }
    if (set_team_context(team, cmd, client) == ERROR)
        return SUCCESS;
    if (set_channel_context(team, cmd, client) == ERROR)
        return SUCCESS;
    return set_thread_context(team, cmd, client);
}
