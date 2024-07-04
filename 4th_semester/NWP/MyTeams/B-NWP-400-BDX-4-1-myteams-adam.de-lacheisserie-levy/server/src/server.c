/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** server
*/

#include "protos_srv.h"
#include "../../include/macros.h"

int main(int argc, char **argv)
{
    int port = 0;
    my_teams_t my_teams = {0};

    if (check_args_srv(argc, argv) == ERROR)
        return ERROR;
    port = atoi(argv[1]);
    set_struct(&my_teams, port);
    if (bind_listen(&my_teams) == ERROR)
        return ERROR;
    return client_handler(&my_teams);
}
