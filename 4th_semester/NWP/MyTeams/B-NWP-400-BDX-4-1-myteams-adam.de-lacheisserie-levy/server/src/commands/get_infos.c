/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** get_infos
*/

#include "../../../include/server.h"
#include "../../include/macros.h"

static int check_before(client_t *client, char **cmd)
{
    if (cmd[1]) {
        dprintf(client->client_socket, "300\n");
        return ERROR;
    }
    if (!client->user) {
        dprintf(client->client_socket, "500\n");
        return ERROR;
    }
    return SUCCESS;
}

static int current_user_infos(my_teams_t *team, client_t *client)
{
    uuid_unparse(client->user->uuid, team->tmpUuid);
    dprintf(client->client_socket,
    "100 \"%s\" \"%s\" \"%d\"\n", team->tmpUuid,
    client->user->user_name, client->user->is_logged);
    return SUCCESS;
}

static int team_info(my_teams_t *team, client_t *client)
{
    uuid_unparse(client->user->teams[client->user->tm_ctxt].uuid,
    team->tmpUuid);
    dprintf(client->client_socket,
    "130 \"%s\" \"%s\" \"%s\"\n", team->tmpUuid,
    client->user->teams[client->user->tm_ctxt].name,
    client->user->teams[client->user->tm_ctxt].team_description);
    return SUCCESS;
}

static int channel_info(my_teams_t *team, client_t *client)
{
    uuid_unparse(client->user->teams[client->user->tm_ctxt].
    channels[client->user->chl_ctxt].uuid, team->tmpUuid);
    dprintf(client->client_socket,
    "140 \"%s\" \"%s\" \"%s\"\n", team->tmpUuid,
    client->user->teams[client->user->tm_ctxt].
    channels[client->user->chl_ctxt].name,
    client->user->teams[client->user->tm_ctxt].
    channels[client->user->chl_ctxt].channel_description);
    return SUCCESS;
}

static int thread_info(my_teams_t *team, client_t *client)
{
    uuid_unparse(client->user->teams[client->user->tm_ctxt].
    channels[client->user->chl_ctxt].
    threads[client->user->thd_ctxt].uuid, team->tmpUuid);
    dprintf(client->client_socket,
    "150 \"%s\" \"%s\" \"%s\" \"%s\" \"%s\"\n", team->tmpUuid,
    team->tmpUuid,
    ctime(&client->user->teams[client->user->tm_ctxt].
    channels[client->user->chl_ctxt].
    threads[client->user->thd_ctxt].date),
    client->user->teams[client->user->tm_ctxt].
    channels[client->user->chl_ctxt].
    threads[client->user->thd_ctxt].title,
    client->user->teams[client->user->tm_ctxt].
    channels[client->user->chl_ctxt].
    threads[client->user->thd_ctxt].content);
    return SUCCESS;
}

int get_infos(my_teams_t *team, char **cmd, client_t *client)
{
    if (check_before(client, cmd) == ERROR)
        return SUCCESS;
    if (client->user->context == UNDEFINED)
        return current_user_infos(team, client);
    if (client->user->context == TEAM)
        return team_info(team, client);
    if (client->user->context == CHANNEL)
        return channel_info(team, client);
    if (client->user->context == THREAD)
        return thread_info(team, client);
    return SUCCESS;
}
