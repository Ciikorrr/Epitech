/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** send
*/

#include "../../../include/server.h"
#include "../../include/macros.h"
#include "../../include/protos_srv.h"

int find_user_index(my_teams_t *teams, char *uuid)
{
    char tmpUuid[37];

    for (int i = 0; i < teams->nb_users; i += 1) {
        uuid_unparse(teams->users[i].uuid, tmpUuid);
        if (strcmp(uuid, tmpUuid) == 0)
            return i;
    }
    return -1;
}

static void update_receiver
(my_teams_t *teams, char *uuid_receiver, char *uuid_sender, char *msg)
{
    int index = find_user_index(teams, uuid_receiver);
    int chat_index = find_index_chat(teams, uuid_sender, index);
    int index_msg = teams->users[index].chats[chat_index].nb_msg;

    teams->users[index].chats[chat_index].mess[index_msg].timestamp =
    time(NULL);
    teams->users[index].
    chats[chat_index].mess[index_msg].msg = strdup(msg);
    teams->users[index].
    chats[chat_index].mess[index_msg].sender_uuid = strdup(uuid_sender);
    teams->users[index].chats[chat_index].nb_msg += 1;
}

static void create_receiver
(my_teams_t *teams, char *uuid, char *sender_uuid, char *msg)
{
    int index = find_user_index(teams, uuid);

    teams->users[index].chats[teams->users[index].nb_chats].nb_msg = 0;
    teams->users[index].chats[teams->users[index].nb_chats].mess =
    malloc(sizeof(messages_t) * DEFAULT_SIZE);
    teams->users[index].chats[teams->users[index].nb_chats].
    mess[0].timestamp = time(NULL);
    teams->users[index].
    chats[teams->users[index].nb_chats].user_id = strdup(sender_uuid);
    teams->users[index].
    chats[teams->users[index].nb_chats].mess[0].msg = strdup(msg);
    teams->users[index].chats[teams->users[index].nb_chats].
    mess[0].sender_uuid = strdup(sender_uuid);
    teams->users[index].chats[teams->users[index].nb_chats].nb_msg += 1;
    teams->users[index].nb_chats += 1;
    server_event_private_message_sended(teams->tmpUuid, uuid, msg);
}

static void setup_chat
(client_t *client, int index, int index_msg)
{
    client->user->chats[index].mess[index_msg].timestamp =
    time(NULL);
}

static int send_msg(my_teams_t *team, int index, char *msg, client_t *client)
{
    int index_m = client->user->chats[index].nb_msg;

    setup_chat(client, index, index_m);
    client->user->chats[index].mess[index_m].msg = strdup(msg);
    uuid_unparse(client->user->uuid, team->tmpUuid);
    client->user->chats[index].
    mess[index_m].sender_uuid = strdup(team->tmpUuid);
    client->user->chats[index].nb_msg += 1;
    update_receiver(team, client->user->chats[index].user_id,
    team->tmpUuid, msg);
    server_event_private_message_sended
    (team->tmpUuid, client->user->chats[index].user_id, msg);
    dprintf(team->users[find_user_index(team,
    client->user->chats[index].user_id)].client_socket[0],
    "800 \"%s\" \"%s\"\n", team->tmpUuid, msg);
    return SUCCESS;
}

static int create_msg
(my_teams_t *team, client_t *client, char *msg, char *uuid)
{
    client->user->chats[client->user->nb_chats].mess =
    malloc(sizeof(messages_t) * DEFAULT_SIZE);
    client->user->chats[client->user->nb_chats].nb_msg = 0;
    client->user->chats[client->user->nb_chats].
    mess[0].timestamp = time(NULL);
    client->user->
    chats[client->user->nb_chats].user_id = strdup(uuid);
    client->user->
    chats[client->user->nb_chats].mess[0].msg = strdup(msg);
    uuid_unparse(client->user->uuid, team->tmpUuid);
    client->user->chats[client->user->nb_chats].
    mess[0].sender_uuid = strdup(team->tmpUuid);
    client->user->chats[client->user->nb_chats].nb_msg += 1;
    client->user->nb_chats += 1;
    create_receiver(team, uuid, team->tmpUuid, msg);
    dprintf(team->users[find_user_index(team, uuid)].client_socket[0],
    "800 \"%s\" \"%s\"\n", team->tmpUuid, msg);
    return SUCCESS;
}

int send_to_user(my_teams_t *teams, char **cmd, client_t *client)
{
    if (!cmd || !cmd[1] || !cmd[2])
        return ERROR;
    if (!client->user) {
        dprintf(client->client_socket, "500\n");
        return SUCCESS;
    }
    if (!is_user_exists(teams, cmd[1])) {
        dprintf(client->client_socket, "400 %s\n", cmd[1]);
        return SUCCESS;
    }
    for (int i = 0; i < client->user->nb_chats; i += 1)
        if (strcmp(cmd[1], client->user->chats[i].user_id) == 0)
            return send_msg(teams, i, cmd[2], client);
    return create_msg(teams, client, cmd[2], cmd[1]);
}
