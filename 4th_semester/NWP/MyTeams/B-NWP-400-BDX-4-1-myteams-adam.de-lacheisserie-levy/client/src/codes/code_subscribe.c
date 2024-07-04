/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** code_subscribe
*/
#include "../../../libs/myteams/logging_client.h"
#include "../../../include/macros.h"

int code_subscribe(char **cmd)
{
    if (!cmd[1] || !cmd[2])
        return ERROR;
    client_print_subscribed(cmd[1], cmd[2]);
    return SUCCESS;
}
