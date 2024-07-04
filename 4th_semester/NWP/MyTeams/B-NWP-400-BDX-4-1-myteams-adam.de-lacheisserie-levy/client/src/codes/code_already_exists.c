/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** code_already_exists
*/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../../libs/myteams/logging_client.h"
#include "../../include/macros.h"

int code_already_exists(char **cmd)
{
    (void)cmd;
    client_error_already_exist();
    return SUCCESS;
}
