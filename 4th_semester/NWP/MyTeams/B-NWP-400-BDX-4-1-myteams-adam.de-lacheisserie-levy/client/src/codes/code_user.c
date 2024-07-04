/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** code100
*/

#include <dlfcn.h>
#include <stdlib.h>
#include "../../../libs/myteams/logging_client.h"
#include "../../../include/macros.h"

int code_user(char **cmd)
{
    client_print_user(cmd[1], cmd[2], atoi(cmd[3]));
    return SUCCESS;
}
