/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** client
*/

#include "protos_clt.h"
#include "../../include/macros.h"

int main(int argc, char **argv)
{
    if (check_args_clt(argc, argv) == ERROR)
        return ERROR;
    return create_client(atoi(argv[2]), argv[1]);
}
