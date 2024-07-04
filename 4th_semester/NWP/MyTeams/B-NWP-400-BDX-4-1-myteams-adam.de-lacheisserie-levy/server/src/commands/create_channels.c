/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** create_channels
*/
#include "../../../include/server.h"
#include "../../../include/macros.h"
#include "../../include/protos_srv.h"
#include <stdio.h>

int find_idx_channel(my_teams_t *teams, int idx_tc, uuid_t to_find)
{
    for (int i = 0; i < 1024; i++) {
        if (uuid_compare(teams->teams[idx_tc].channels[i].uuid, to_find) == 0)
            return i;
    }
    return -1;
}

int add_to_my_teams_channel(my_teams_t *teams, char **cmd, uuid_t uuid, int it)
{
    teams->teams[it].channels
    [teams->teams[it].nb_channels].name = strdup(cmd[1]);
    teams->teams[it].channels
    [teams->teams[it].nb_channels].channel_description = strdup(cmd[2]);
    teams->teams[it].channels
    [teams->teams[it].nb_channels].threads =
    malloc(sizeof(thread_t) * DEFAULT_SIZE);
    if (!teams->teams[it].channels[teams->teams[it].nb_channels].threads)
        return ERROR;
    uuid_copy(teams->teams[it].channels
    [teams->teams[it].nb_channels].uuid, uuid);
    teams->teams[it].nb_channels += 1;
    return SUCCESS;
}

int fill_new_channel
(my_teams_t *teams, channel_t *chl, char **cmd, client_t *clt)
{
    int idx_t = clt->user->tm_ctxt;

    uuid_generate(chl->uuid);
    chl->name = strdup(cmd[1]);
    chl->channel_description = strdup(cmd[2]);
    chl->nb_threads = 0;
    chl->threads = malloc(sizeof(thread_t) * DEFAULT_SIZE);
    return add_to_my_teams_channel(teams, cmd, chl->uuid,
    find_idx_tms(teams, clt->user->teams[idx_t].uuid));
}

static void send_to_client
(my_teams_t *teams, int i, channel_t *chl, char *chl_uuid)
{
    for (int z = 0; z < teams->users[i].nb_sockets; z += 1) {
        dprintf(teams->users[i].client_socket[z],
        "170 \"%s\" \"%s\" \"%s\"\n",
        chl_uuid, chl->name, chl->channel_description);
    }
}

static
void all_users(my_teams_t *teams, uuid_t t_uuid, channel_t *chl)
{
    char chl_uuid[37];
    int idx_t = 0;

    uuid_unparse(chl->uuid, chl_uuid);
    idx_t = find_idx_tms(teams, t_uuid);
    for (int i = 0; i < teams->nb_users; i++) {
        if (teams->users[i].teams[idx_t].is_subscribe)
            send_to_client(teams, i, chl, chl_uuid);
    }
}

static void send_notif(my_teams_t *teams, client_t *clt, channel_t *chl)
{
    char chl_uuid[37];
    char team_uuid[37];

    uuid_unparse(chl->uuid, chl_uuid);
    dprintf(clt->client_socket, "175 \"%s\" \"%s\" \"%s\"\n",
    chl_uuid, chl->name, chl->channel_description);
    uuid_unparse(clt->user->teams[clt->user->tm_ctxt].uuid, team_uuid);
    all_users(teams, clt->user->teams[clt->user->tm_ctxt].uuid, chl);
    server_event_channel_created(team_uuid, chl_uuid, chl->name);
}

int create_channel(my_teams_t *teams, char **cmd, client_t *client)
{
    int idx_tc = client->user->tm_ctxt;
    int idx_chl = client->user->teams[idx_tc].nb_channels;
    channel_t *chl = NULL;

    if (!cmd[1] || !cmd[2]) {
        dprintf(client->client_socket, "300\n");
        return SUCCESS;
    }
    if (idx_chl == -1 || idx_tc == -1)
        return SUCCESS;
    chl = &client->user->teams[idx_tc].channels[idx_chl];
    if (fill_new_channel(teams, chl, cmd, client) == ERROR)
        return ERROR;
    send_notif(teams, client, chl);
    client->user->teams[idx_tc].nb_channels += 1;
    return SUCCESS;
}
