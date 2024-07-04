/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** code_users
*/
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../../libs/myteams/logging_client.h"
#include "../../include/macros.h"

int code_users(char **cmd)
{
    for (int i = 1; cmd[i]; i += 3)
        client_print_users(cmd[i], cmd[i + 1], atoi(cmd[i + 2]));
    return SUCCESS;
}
