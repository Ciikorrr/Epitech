/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** get_list
*/

#include "../../../include/server.h"
#include "../../include/macros.h"
#include "protos_srv.h"

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

static int list_teams(my_teams_t *team, client_t *client)
{
    char *line = "";

    for (int i = 0; i < team->nb_team; i += 1) {
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

static int list_channels(my_teams_t *team, client_t *client)
{
    char *line = "";
    int team_ind = client->user->tm_ctxt;

    for (int i = 0; i < team->teams[team_ind].nb_channels; i += 1) {
        uuid_unparse(client->user->teams[team_ind].channels[i].uuid,
        team->tmpUuid);
        line = my_strcat_dup(line, " ",
        my_strcat_dup("\"", team->tmpUuid,
        my_strcat_dup("\"", " ",
        my_strcat_dup("\"",
        client->user->teams[team_ind].channels[i].name,
        my_strcat_dup("\"", " ",
        my_strcat_dup("\"",
        client->user->teams[team_ind].channels[i]
        .channel_description, "\""))))));
    }
    dprintf(client->client_socket, "610 %s\n", line);
    if (strlen(line) != 0)
        free(line);
    return SUCCESS;
}

static char *fill_thread_line(my_teams_t *team, channel_t *channel, int i)
{
    char *line = "";

    line = my_strcat_dup(line, " ",
    my_strcat_dup("\"", team->tmpUuid, my_strcat_dup("\"", " ",
    my_strcat_dup("\"", team->tmpUuid,
    my_strcat_dup("\"", " ",
    my_strcat_dup("\"", ctime(&channel->threads[i].date),
    my_strcat_dup("\"", " ",
    my_strcat_dup("\"", channel->threads[i].title,
    my_strcat_dup("\"", " ",
    my_strcat_dup("\"", channel->threads[i].content, "\""))))))))));
    return line;
}

static int list_threads(my_teams_t *team, client_t *client)
{
    char *line = "";
    int team_ind = client->user->tm_ctxt;
    int chan_ind = client->user->chl_ctxt;
    int nb_thread = team->teams[team_ind].channels[chan_ind].nb_threads;
    channel_t channel = team->teams[team_ind].channels[chan_ind];

    for (int i = 0; i < nb_thread; i += 1) {
        uuid_unparse(channel.threads[i].uuid,
        team->tmpUuid);
        line = fill_thread_line(team, &channel, i);
    }
    dprintf(client->client_socket, "620 %s\n", line);
    if (strlen(line) != 0)
        free(line);
    return SUCCESS;
}

static char *fill_line(my_teams_t *team, int nb_comments, thread_t *thread)
{
    char *line = "";
    char tmp[37];

    for (int i = 0; i < nb_comments; i += 1) {
        uuid_unparse(thread->uuid, team->tmpUuid);
        uuid_unparse(thread->comments[i].sender_uuid, tmp);
        line = my_strcat_dup(line, " ",
        my_strcat_dup("\"", team->tmpUuid,
        my_strcat_dup("\"", " ",
        my_strcat_dup("\"", tmp,
        my_strcat_dup("\"", " ",
        my_strcat_dup("\"", ctime(&thread->comments[i].timestamp),
        my_strcat_dup("\"", " ",
        my_strcat_dup("\"", thread->comments[i].content, "\""))))))));
    }
    return line;
}

static int list_replies(my_teams_t *team, client_t *client)
{
    char *line = NULL;
    int team_ind = client->user->tm_ctxt;
    int chan_ind = client->user->chl_ctxt;
    int thread_ind = client->user->thd_ctxt;
    int nb_comments = team->teams[team_ind].
    channels[chan_ind].threads[thread_ind].nb_comment;
    thread_t thread = team->teams[team_ind].
    channels[chan_ind].threads[thread_ind];

    line = fill_line(team, nb_comments, &thread);
    dprintf(client->client_socket, "630 %s\n", line);
    if (strlen(line) != 0)
        free(line);
    return SUCCESS;
}

int get_list(my_teams_t *team, char **cmd, client_t *client)
{
    if (check_before(client, cmd) == ERROR)
        return SUCCESS;
    if (client->user->context == UNDEFINED)
        return list_teams(team, client);
    if (client->user->context == TEAM)
        return list_channels(team, client);
    if (client->user->context == CHANNEL)
        return list_threads(team, client);
    if (client->user->context == THREAD)
        return list_replies(team, client);
    return SUCCESS;
}
