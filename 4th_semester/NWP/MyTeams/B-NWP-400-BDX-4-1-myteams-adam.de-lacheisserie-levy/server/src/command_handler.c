/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** command_handler
*/

#include "../../include/server.h"
#include "../include/commandlist.h"
#include "protos_srv.h"
#include "../../include/macros.h"

static void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i += 1) {
        free(tab[i]);
    }
    free(tab);
}

int command_handler(my_teams_t *teams, char **cmd, client_t *client)
{
    if (!teams || !cmd || !cmd[0])
        return ERROR;
    for (size_t i = 0; i < 14; i += 1)
        if (strcmp(cmd[0], FLAGS[i].flag) == 0)
            return FLAGS[i].func(teams, cmd, client);
    dprintf(client->client_socket, "Invalid Command\n");
    free_tab(cmd);
    return SUCCESS;
}
