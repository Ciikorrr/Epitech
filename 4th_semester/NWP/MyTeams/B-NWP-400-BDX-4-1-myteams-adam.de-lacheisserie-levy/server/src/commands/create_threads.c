/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** create_thread
*/
#include "../../../include/server.h"
#include "../../../include/macros.h"
#include "../../include/protos_srv.h"
#include <stdio.h>

int find_idx_thread(my_teams_t *teams, int idx_tc, int idx_chl, uuid_t to_find)
{
    for (int i = 0; i < 1024; i++) {
        if (uuid_compare(teams->teams[idx_tc].channels[idx_chl]
        .threads[i].uuid, to_find) == 0)
            return i;
    }
    return -1;
}

int add_to_my_teams_thread(my_teams_t *teams, char **cmd, uuid_t uuid, int *id)
{
    thread_t *thread = &teams->teams[id[0]].channels[id[1]].
    threads[teams->teams[id[0]].channels[id[1]].nb_threads];

    thread->title = strdup(cmd[1]);
    thread->content = strdup(cmd[2]);
    thread->date = time(NULL);
    thread->comments = malloc(sizeof(comment_t) * DEFAULT_SIZE);
    teams->teams[id[0]].channels[id[1]].nb_threads += 1;
    uuid_copy(thread->uuid, uuid);
    return SUCCESS;
}

int fill_new_thread
(my_teams_t *teams, thread_t *thd, char **cmd, client_t *clt)
{
    int tabidx[2];
    int idx_tc = clt->user->tm_ctxt;

    tabidx[0] = find_idx_tms(teams, clt->user->teams[idx_tc].uuid);
    tabidx[1] = find_idx_channel
    (teams, tabidx[0], clt->user->teams[idx_tc].
    channels[clt->user->chl_ctxt].uuid);
    thd->title = strdup(cmd[1]);
    thd->content = strdup(cmd[2]);
    thd->date = time(NULL);
    thd->nb_comment = 0;
    thd->comments = malloc(sizeof(comment_t) * DEFAULT_SIZE);
    uuid_generate(thd->uuid);
    return add_to_my_teams_thread(teams, cmd, thd->uuid, tabidx);
}

static
void all_users(my_teams_t *teams, uuid_t t_uuid, client_t *clt, thread_t *thd)
{
    char thd_uuid[37];
    char user_uuids[37];
    int idx_t = 0;

    uuid_unparse(clt->user->uuid, user_uuids);
    uuid_unparse(thd->uuid, thd_uuid);
    idx_t = find_idx_tms(teams, t_uuid);
    for (int i = 0; i < teams->nb_users; i++) {
        if (!teams->users[i].teams[idx_t].is_subscribe)
            continue;
        for (int z = 0; z < teams->users[i].nb_sockets; z += 1)
            dprintf(teams->users[i].client_socket[z],
            "180 \"%s\" \"%s\" \"%s\" \"%s\" \"%s\"\n",
            thd_uuid, user_uuids, ctime(&thd->date), thd->title, thd->content);
    }
}

static
void send_notif(thread_t *thd, client_t *clt, channel_t *ch, my_teams_t *teams)
{
    char thd_uuid[37];
    char user_uuids[37];
    char chl_uuid[37];

    uuid_unparse(thd->uuid, thd_uuid);
    uuid_unparse(clt->user->uuid, user_uuids);
    uuid_unparse(ch->uuid, chl_uuid);
    dprintf(clt->client_socket,
    "185 \"%s\" \"%s\" \"%s\" \"%s\" \"%s\"\n",
    thd_uuid, user_uuids, ctime(&thd->date), thd->title, thd->content);
    all_users(teams, clt->user->teams[clt->user->tm_ctxt].uuid, clt, thd);
    server_event_thread_created
    (chl_uuid, thd_uuid, user_uuids, thd->title, thd->content);
}

static int check_before(char **cmd, client_t *clt, int idx_chl, int idx_tc)
{
    if (idx_chl == -1 || idx_tc == -1)
        return ERROR;
    if (!cmd[1] || !cmd[2]) {
        dprintf(clt->client_socket, "300\n");
        return ERROR;
    }
    if (!clt->user) {
        dprintf(clt->client_socket, "500\n");
        return ERROR;
    }
    return SUCCESS;
}

int create_thread(my_teams_t *teams, char **cmd, client_t *client)
{
    int tabidx[2];
    int idx_tc = client->user->tm_ctxt;
    int idx_chl = client->user->chl_ctxt;
    int idx_thd = 0;
    thread_t *thread = NULL;

    if (check_before(cmd, client, idx_chl, idx_tc) == ERROR)
        return SUCCESS;
    idx_thd = client->user->teams[idx_tc].channels[idx_chl].nb_threads;
    thread = &client->user->teams[idx_tc].channels[idx_chl].threads[idx_thd];
    tabidx[0] = find_idx_tms(teams, client->user->teams[idx_tc].uuid);
    tabidx[1] = find_idx_channel(teams, tabidx[0], client->user->teams[idx_tc].
    channels[client->user->chl_ctxt].uuid);
    if (fill_new_thread(teams, thread, cmd, client) == ERROR)
        return ERROR;
    send_notif(thread, client, &client->user->teams
    [idx_tc].channels[idx_chl], teams);
    client->user->teams[idx_tc].channels[idx_chl].nb_threads += 1;
    return SUCCESS;
}
