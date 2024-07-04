/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** code_messages
*/

#include <dlfcn.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include "../../include/macros.h"
#include "../../../libs/myteams/logging_client.h"
#include "../../include/protos_clt.h"

int code_messages(char **cmd)
{
    for (int i = 1; cmd[i]; i += 3)
        client_private_message_print_messages
        (cmd[i], convert_str_to_time(cmd[i + 2]), cmd[i + 1]);
    return SUCCESS;
}
