/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** get_messages
*/

#include "../../../include/server.h"
#include "../../include/macros.h"
#include "../../include/protos_srv.h"

static int send_messages(int chat, client_t *client)
{
    char *line = "";
    char *time = NULL;

    for (int i = 0; i < client->user->chats[chat].nb_msg; i += 1) {
        time = ctime(&client->user->chats[chat].mess[i].timestamp);
        line = my_strcat_dup(line, " ",
        my_strcat_dup("\"", client->user->chats[chat].
        mess[i].sender_uuid,
        my_strcat_dup("\"", " ",
        my_strcat_dup("\"", client->user->chats[chat].mess[i].msg,
        my_strcat_dup("\"", " ",
        my_strcat_dup("\"", time, "\""))))));
    }
    dprintf(client->client_socket, "120 %s\n", line);
    free(line);
    return SUCCESS;
}

int get_messages(my_teams_t *team, char **cmd, client_t *client)
{
    int chat_index = 0;

    if (!cmd[1]) {
        dprintf(client->client_socket, "300\n");
        return SUCCESS;
    }
    if (!client->user) {
        dprintf(client->client_socket, "500\n");
        return SUCCESS;
    }
    if (!is_user_exists(team, cmd[1])) {
        dprintf(client->client_socket, "400 %s\n", cmd[1]);
        return SUCCESS;
    }
    uuid_unparse(client->user->uuid, team->tmpUuid);
    chat_index =
    find_index_chat(team, cmd[1], find_user_index(team, team->tmpUuid));
    if (chat_index == -1)
        return SUCCESS;
    return send_messages(chat_index, client);
}
