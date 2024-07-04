/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** handle_cmd
*/

#include "commands.h"
#include "commands_gui.h"

void handle_command_gui(char **cmd, zappy_t *zappy)
{
    if (!cmd || !cmd[0] || !zappy)
        return;
    for (int i = 0; i < 9; i += 1)
        if (strcmp(cmd[0], CMD_GUI[i].flag) == 0)
            return CMD_GUI[i].func(zappy, cmd);
    dprintf(zappy->gui->client_socket, "suc\n");
}

void handle_command(char **cmd, zappy_t *zappy, client_t *client)
{
    if (!cmd || !cmd[0] || !zappy)
        return;
    for (int i = 0; i < 13; i += 1)
        if (strcmp(cmd[0], COMMANDS[i].flag) == 0)
            return COMMANDS[i].func(zappy, client, cmd);
    for (int n = 0; n < zappy->nb_teams; n += 1)
        if (strcmp(cmd[0], zappy->teams[n].name) == 0)
            return new_player(zappy, client, n);
    dprintf(client->client_socket, "ko\n");
}
