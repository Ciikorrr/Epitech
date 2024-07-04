/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** create_comments
*/
#include "../../../include/server.h"
#include "../../../include/macros.h"
#include "../../include/protos_srv.h"
#include <stdio.h>

int add_to_teams_comment(my_teams_t *teams, char **cmd, int *id, uuid_t uuidu)
{
    comment_t *comment = &teams->teams[id[0]].channels[id[1]].threads[id[2]].
    comments[teams->teams[id[0]].channels[id[1]].threads[id[2]].nb_comment];

    comment->content = strdup(cmd[1]);
    uuid_copy(comment->sender_uuid, uuidu);
    comment->timestamp = time(NULL);
    comment->users = NULL;
    teams->teams[id[0]].channels[id[1]].threads[id[2]].nb_comment++;
    return SUCCESS;
}

int find_var(client_t *client, int *ctxidx)
{
    ctxidx[0] = client->user->tm_ctxt;
    ctxidx[1] = client->user->chl_ctxt;
    ctxidx[2] = client->user->thd_ctxt;
    if (ctxidx[0] == -1 || ctxidx[1] == -1 || ctxidx[2] == -1)
        return ERROR;
    return SUCCESS;
}

int fill_new_comment
(my_teams_t *teams, comment_t *cmt, char **cmd, client_t *clt)
{
    int tabidx[3];
    int ctxidx[3];

    find_var(clt, ctxidx);
    tabidx[0] = find_idx_tms(teams, clt->user->teams[ctxidx[0]].uuid);
    tabidx[1] = find_idx_channel(teams, tabidx[0],
    clt->user->teams[ctxidx[0]].channels[ctxidx[1]].uuid);
    tabidx[2] = find_idx_thread
    (teams, tabidx[0], tabidx[1], clt->user->teams[ctxidx[0]].
    channels[ctxidx[1]].threads[ctxidx[2]].uuid);
    cmt->content = strdup(cmd[1]);
    uuid_copy(cmt->sender_uuid, clt->user->uuid);
    cmt->timestamp = time(NULL);
    cmt->users = NULL;
    return add_to_teams_comment(teams, cmd, tabidx, clt->user->uuid);
}

static
void all_users(my_teams_t *teams, comment_t *cmt, client_t *clt, int *ctxidx)
{
    char t_uuid[37];
    char u_uuid[37];
    char thd_uuid[37];
    int idx_t = 0;

    uuid_unparse(clt->user->uuid, u_uuid);
    uuid_unparse(clt->user->teams[ctxidx[0]].uuid, t_uuid);
    uuid_unparse(clt->user->teams[ctxidx[0]].
    channels[ctxidx[1]].threads[ctxidx[2]].uuid, thd_uuid);
    for (int i = 0; i < teams->nb_users; i++) {
        idx_t = find_idx_tms(teams, clt->user->teams[ctxidx[0]].uuid);
        if (!teams->users[i].teams[idx_t].is_subscribe)
            continue;
        for (int z = 0; z < teams->users[i].nb_sockets; z += 1) {
            dprintf(teams->users[i].client_socket[z],
            "190 \"%s\" \"%s\" \"%s\" \"%s\"\n",
            t_uuid, thd_uuid, u_uuid, cmt->content);
        }
    }
}

static
void send_notif(my_teams_t *teams, comment_t *cmt, client_t *clt, int *ctxidx)
{
    char user_uuids[37];
    char thd_uuids[37];

    uuid_unparse(clt->user->teams[ctxidx[0]].channels[ctxidx[1]].
    threads[ctxidx[2]].uuid, thd_uuids);
    uuid_unparse(clt->user->uuid, user_uuids);
    dprintf(clt->client_socket, "195 \"%s\" \"%s\" \"%s\" \"%s\"\n",
    thd_uuids, user_uuids, ctime(&cmt->timestamp), cmt->content);
    all_users(teams, cmt, clt, ctxidx);
    server_event_reply_created(thd_uuids, user_uuids, cmt->content);
}

static int check_before(char **cmd, client_t *clt)
{
    if (!cmd[1]) {
        dprintf(clt->client_socket, "300\n");
        return ERROR;
    }
    if (!clt->user) {
        dprintf(clt->client_socket, "500\n");
        return ERROR;
    }
    return SUCCESS;
}

int create_comment(my_teams_t *teams, char **cmd, client_t *client)
{
    int ctxidx[3];
    int idx_cmt = 0;
    comment_t *comment = NULL;

    if (find_var(client, ctxidx) == ERROR)
        return ERROR;
    idx_cmt = client->user->teams[ctxidx[0]].
    channels[ctxidx[1]].threads[ctxidx[2]].nb_comment;
    comment = &client->user->teams[ctxidx[0]].channels[ctxidx[1]].
    threads[ctxidx[2]].comments[idx_cmt];
    if (check_before(cmd, client) == ERROR)
        return SUCCESS;
    if (fill_new_comment(teams, comment, cmd, client) == ERROR)
        return ERROR;
    send_notif(teams, comment, client, ctxidx);
    client->user->teams[ctxidx[0]].
    channels[ctxidx[1]].threads[ctxidx[2]].nb_comment += 1;
    return SUCCESS;
}
