/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** code_list
*/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../../libs/myteams/logging_client.h"
#include "../../include/macros.h"
#include "../../include/protos_clt.h"

int code_list_teams(char **cmd)
{
    for (int i = 1; cmd[i]; i += 3)
        client_print_teams(cmd[i], cmd[i + 1], cmd[i + 2]);
    return SUCCESS;
}

int code_list_channels(char **cmd)
{
    for (int i = 1; cmd[i]; i += 3)
        client_team_print_channels(cmd[i], cmd[i + 1], cmd[i + 2]);
    return SUCCESS;
}

int code_list_thread(char **cmd)
{
    for (int i = 1; cmd[i]; i += 5)
        client_channel_print_threads
        (cmd[i], cmd[i + 1],
        convert_str_to_time(cmd[i + 2]), cmd[i + 3], cmd[i + 4]);
    return SUCCESS;
}

int code_list_replies(char **cmd)
{
    for (int i = 1; cmd[i]; i += 4)
        client_thread_print_replies
        (cmd[i], cmd[i + 1], convert_str_to_time(cmd[i + 2]), cmd[i + 3]);
    return SUCCESS;
}
