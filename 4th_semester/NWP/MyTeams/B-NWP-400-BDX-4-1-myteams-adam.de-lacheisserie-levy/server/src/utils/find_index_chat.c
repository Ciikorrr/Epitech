/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** find_index_chat
*/

#include "../../../include/server.h"

int find_index_chat(my_teams_t *teams, char *uuid, int index)
{
    for (int i = 0; i < teams->users[index].nb_chats; i += 1) {
        if (strcmp(uuid, teams->users[index].chats[i].user_id) == 0)
            return i;
    }
    return -1;
}
