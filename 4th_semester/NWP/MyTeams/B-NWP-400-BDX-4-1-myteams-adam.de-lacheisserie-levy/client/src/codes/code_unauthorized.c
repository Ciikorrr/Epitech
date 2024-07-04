/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** code_unauthorized
*/
#include <dlfcn.h>
#include "../../../libs/myteams/logging_client.h"
#include "../../include/macros.h"

int code_unauthorized(char **cmd)
{
    (void)cmd;
    client_error_unauthorized();
    return SUCCESS;
}
