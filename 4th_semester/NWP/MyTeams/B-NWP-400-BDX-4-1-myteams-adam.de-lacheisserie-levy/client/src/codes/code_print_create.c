/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** code_create
*/

#include <dlfcn.h>
#include <time.h>
#include <stdio.h>
#include "../../../libs/myteams/logging_client.h"
#include "../../../include/macros.h"
#include "../../include/protos_clt.h"

int code_print_create_team(char **cmd)
{
    client_print_team_created(cmd[1], cmd[2], cmd[3]);
    return 0;
}

int code_print_create_channel(char **cmd)
{
    client_print_channel_created(cmd[1], cmd[2], cmd[3]);
    return 0;
}

int code_print_create_thread(char **cmd)
{
    client_print_thread_created(cmd[1], cmd[2],
    convert_str_to_time(cmd[3]), cmd[4], cmd[5]);
    return 0;
}

int code_print_create_comment(char **cmd)
{
    client_print_reply_created(cmd[1], cmd[2],
    convert_str_to_time(cmd[3]), cmd[4]);
    return 0;
}
