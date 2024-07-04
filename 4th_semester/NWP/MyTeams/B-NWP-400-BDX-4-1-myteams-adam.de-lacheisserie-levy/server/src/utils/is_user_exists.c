/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** is_user_exists
*/

#include "../../../include/server.h"

bool is_user_exists(my_teams_t *teams, char *uuid)
{
    char tmpUuid[37];

    for (int i = 0; i < teams->nb_users; i += 1) {
        uuid_unparse(teams->users[i].uuid, tmpUuid);
        if (strcmp(uuid, tmpUuid) == 0)
            return true;
    }
    return false;
}
