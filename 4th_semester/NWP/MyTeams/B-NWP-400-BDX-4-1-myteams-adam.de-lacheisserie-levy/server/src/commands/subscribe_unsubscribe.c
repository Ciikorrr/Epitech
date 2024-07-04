/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** subscribe_unsubscribe
*/
#include "../../../include/server.h"
#include "../../../include/macros.h"
#include "../../include/protos_srv.h"
#include <stdio.h>
#include <string.h>

static int add_team(my_teams_t *teams, client_t *clt, int idx_t)
{
    team_t *new_team = &clt->user->teams[clt->user->nb_team];

    new_team->channels = teams->teams[idx_t].channels;
    new_team->is_subscribe = true;
    new_team->name = strdup(teams->teams[idx_t].name);
    new_team->nb_channels = teams->teams[idx_t].nb_channels;
    new_team->team_description = strdup(teams->teams[idx_t].team_description);
    clt->user->nb_team += 1;
    uuid_copy(new_team->uuid, teams->teams[idx_t].uuid);
    return SUCCESS;
}

static void send_notif(char *team_uuid, char *user_uuid, int socket)
{
    dprintf(socket, "200 \"%s\" \"%s\"\n", user_uuid, team_uuid);
}

static int subscribe_user(my_teams_t *teams, char **cmd, client_t *clt)
{
    uuid_t to_find;
    char tmpUuid[37];
    int idx_t = 0;

    uuid_parse(cmd[1], to_find);
    idx_t = find_idx_tms(teams, to_find);
    uuid_unparse(clt->user->uuid, teams->tmpUuid);
    if (idx_t == -1)
        return SUCCESS;
    for (int i = 0; i < clt->user->nb_team; i++) {
        uuid_unparse(clt->user->teams[i].uuid, tmpUuid);
        if (strcmp(cmd[1], tmpUuid) == 0) {
            clt->user->teams[i].is_subscribe = true;
            send_notif(cmd[1], teams->tmpUuid, clt->client_socket);
            return server_event_user_subscribed(cmd[1], teams->tmpUuid);
        }
    }
    server_event_user_subscribed(cmd[1], teams->tmpUuid);
    send_notif(cmd[1], teams->tmpUuid, clt->client_socket);
    return add_team(teams, clt, idx_t);
}

int subscribe(my_teams_t *teams, char **cmd, client_t *clt)
{
    if (!clt->user) {
        dprintf(clt->client_socket, "500\n");
        return SUCCESS;
    }
    if (!cmd[1]) {
        dprintf(clt->client_socket, "300\n");
        return SUCCESS;
    }
    return subscribe_user(teams, cmd, clt);
}

static void send_notif_unsubscribe
(char *team_uuid, char *user_uuid, int socket)
{
    dprintf(socket, "205 \"%s\" \"%s\"\n", user_uuid, team_uuid);
}

int unsubscribe_user(my_teams_t *teams, char **cmd, client_t *clt)
{
    char tmpUuid[37];
    char user_uuid[37];

    (void)teams;
    for (int i = 0; i < clt->user->nb_team; i++) {
        uuid_unparse(clt->user->teams[i].uuid, tmpUuid);
        if (strcmp(cmd[1], tmpUuid) == 0)
            clt->user->teams[i].is_subscribe = false;
    }
    uuid_unparse(clt->user->uuid, user_uuid);
    server_event_user_unsubscribed(cmd[1], user_uuid);
    send_notif_unsubscribe(cmd[1], user_uuid, clt->client_socket);
    return SUCCESS;
}

int unsubscribe(my_teams_t *teams, char **cmd, client_t *clt)
{
    if (!clt->user) {
        dprintf(clt->client_socket, "500\n");
        return SUCCESS;
    }
    if (!cmd[1]) {
        dprintf(clt->client_socket, "300\n");
        return SUCCESS;
    }
    return unsubscribe_user(teams, cmd, clt);
}
