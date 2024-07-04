/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** create_teams
*/
#include "../../../include/server.h"
#include "../../../include/macros.h"
#include "../../include/protos_srv.h"
#include <stdio.h>

int find_idx_tms(my_teams_t *teams, uuid_t to_find)
{
    for (int i = 0; i < 128; i++) {
        if (uuid_compare(teams->teams[i].uuid, to_find) == 0) {
            return i;
        }
    }
    return -1;
}

int add_to_my_teams(my_teams_t *teams, char **cmd, uuid_t uuid_team)
{
    teams->teams[teams->nb_team].is_subscribe = true;
    teams->teams[teams->nb_team].name = strdup(cmd[1]);
    teams->teams[teams->nb_team].team_description = strdup(cmd[2]);
    teams->teams[teams->nb_team].channels =
    malloc(sizeof(channel_t) * DEFAULT_SIZE);
    if (!teams->teams[teams->nb_team].channels)
        return ERROR;
    uuid_copy(teams->teams[teams->nb_team].uuid, uuid_team);
    teams->nb_team += 1;
    return SUCCESS;
}

int fill_new_team(my_teams_t *teams, team_t *team, char **cmd)
{
    uuid_generate(team->uuid);
    team->is_subscribe = false;
    team->name = strdup(cmd[1]);
    team->team_description = strdup(cmd[2]);
    team->nb_channels = 0;
    team->channels = malloc(sizeof(channel_t) * DEFAULT_SIZE);
    if (!team->channels)
        return ERROR;
    if (add_to_my_teams(teams, cmd, team->uuid) == ERROR)
        return ERROR;
    return SUCCESS;
}

static
void send_notif(my_teams_t *teams, team_t *team, client_t *clt, uuid_t uuid)
{
    char team_uuid[37];
    char user_uuid[37];

    uuid_unparse(uuid, team_uuid);
    dprintf(clt->client_socket,
    "165 \"%s\" \"%s\" \"%s\"\n",
    team_uuid, team->name, team->team_description);
    for (int i = 0; i < 128; i++) {
        if (teams->users[i].is_logged <= 0)
            continue;
        for (int z = 0; z < teams->users[i].nb_sockets; z += 1)
            dprintf(teams->users[i].client_socket[z],
            "160 \"%s\" \"%s\" \"%s\"\n", team_uuid, team->name,
            team->team_description);
    }
    uuid_unparse(clt->user->uuid, user_uuid);
    server_event_team_created(team_uuid, team->name, user_uuid);
}

int create_team(my_teams_t *teams, char **cmd, client_t *client)
{
    team_t *team = &client->user->teams[client->user->nb_team];

    if (!cmd[1] || !cmd[2]) {
        dprintf(client->client_socket, "300\n");
        return SUCCESS;
    }
    if (!client->user) {
        dprintf(client->client_socket, "500\n");
        return SUCCESS;
    }
    if (fill_new_team(teams, team, cmd) == ERROR)
        return ERROR;
    send_notif(teams, team, client, team->uuid);
    client->user->nb_team += 1;
    return SUCCESS;
}
