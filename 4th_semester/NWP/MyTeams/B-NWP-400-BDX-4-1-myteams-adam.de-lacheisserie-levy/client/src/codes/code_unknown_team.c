/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** code_unknown_team
*/

#include <dlfcn.h>
#include "../../../libs/myteams/logging_client.h"
#include "../../include/macros.h"

int code_unknown_team(char **cmd)
{
    if (!cmd[1])
        return ERROR;
    client_error_unknown_team(cmd[1]);
    return SUCCESS;
}

int code_unknown_channel(char **cmd)
{
    if (!cmd[1])
        return ERROR;
    client_error_unknown_channel(cmd[1]);
    return SUCCESS;
}

int code_unknown_thread(char **cmd)
{
    if (!cmd[1])
        return ERROR;
    client_error_unknown_thread(cmd[1]);
    return SUCCESS;
}
