/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** code_infos
*/

#include "../../../libs/myteams/logging_client.h"
#include "../../include/macros.h"
#include "../../include/protos_clt.h"

int code_info_team(char **cmd)
{
    if (!cmd[1] || !cmd[2] || !cmd[3])
        return ERROR;
    client_print_team(cmd[1], cmd[2], cmd[3]);
    return SUCCESS;
}

int code_info_channel(char **cmd)
{
    if (!cmd[1] || !cmd[2] || !cmd[3])
        return ERROR;
    client_print_channel(cmd[1], cmd[2], cmd[3]);
    return SUCCESS;
}

int code_info_thread(char **cmd)
{
    if (!cmd[1] || !cmd[2] || !cmd[3] || !cmd[4] || !cmd[5])
        return ERROR;
    client_print_thread(cmd[1], cmd[2],
    convert_str_to_time(cmd[3]), cmd[4], cmd[5]);
    return SUCCESS;
}
