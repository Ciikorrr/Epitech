/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** code_unsuscribe
*/
#include "../../../libs/myteams/logging_client.h"
#include "../../../include/macros.h"

int code_unsubscribe(char **cmd)
{
    if (!cmd[1] || !cmd[2])
        return ERROR;
    client_print_unsubscribed(cmd[1], cmd[2]);
    return SUCCESS;
}
