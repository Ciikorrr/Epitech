/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** get_users
*/

#include "../../../include/server.h"
#include "protos_srv.h"
#include "../../include/macros.h"

char *int_to_string(int num)
{
    int num_digits = snprintf(NULL, 0, "%d", num);
    char *str = malloc(sizeof(char) * (num_digits + 1));

    if (str == NULL)
        return NULL;
    if (num > 0)
        num = 1;
    snprintf(str, num_digits + 1, "%d", num);
    return str;
}

void draw_users(my_teams_t *team, client_t *client)
{
    char *to_concat = "";
    char tmpUuid[37];

    for (int i = 0; i < team->nb_users; i += 1) {
        uuid_unparse(team->users[i].uuid, tmpUuid);
        to_concat = my_strcat_dup(to_concat, " ", my_strcat_dup("\"", tmpUuid,
        my_strcat_dup("\"", " ",
        my_strcat_dup("\"", team->users[i].user_name,
        my_strcat_dup("\"", " ",
        my_strcat_dup("\"",
        int_to_string(team->users[i].is_logged), "\""))))));
    }
    dprintf(client->client_socket, "110 %s\n", to_concat);
    free(to_concat);
}

int get_users(my_teams_t *team, char **cmd, client_t *client)
{
    if (cmd[1]) {
        dprintf(client->client_socket, "300\n");
        return SUCCESS;
    }
    if (!client->user) {
        dprintf(client->client_socket, "500\n");
        return SUCCESS;
    }
    draw_users(team, client);
    return SUCCESS;
}
