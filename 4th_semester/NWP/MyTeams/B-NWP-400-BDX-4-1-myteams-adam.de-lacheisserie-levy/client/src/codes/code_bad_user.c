/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** code_bad_user
*/
#include <dlfcn.h>
#include "../../../libs/myteams/logging_client.h"
#include "../../../include/macros.h"

int code_bad_user(char **cmd)
{
    client_error_unknown_user(cmd[1]);
    return SUCCESS;
}
