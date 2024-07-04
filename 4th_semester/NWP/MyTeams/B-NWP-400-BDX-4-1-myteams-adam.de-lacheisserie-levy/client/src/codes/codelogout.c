/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** code220
*/

#include <dlfcn.h>
#include "../../../libs/myteams/logging_client.h"
#include "../../include/macros.h"

int code_logout(char **cmd)
{
    if (!cmd[1] || !cmd[2])
        return ERROR;
    client_event_logged_out(cmd[1], cmd[2]);
    return SUCCESS;
}
