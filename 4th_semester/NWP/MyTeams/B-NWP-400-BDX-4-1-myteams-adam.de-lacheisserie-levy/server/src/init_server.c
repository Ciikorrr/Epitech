/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** init_server
*/

#include "../../include/server.h"
#include "../../include/macros.h"

void set_struct(my_teams_t *my_teams, int port)
{
    my_teams->nb_clients_connected = 0;
    my_teams->nb_users = 0;
    my_teams->nb_team = 0;
    my_teams->users = malloc(sizeof(user_t) * DEFAULT_SIZE);
    my_teams->teams = malloc(sizeof(team_t) * DEFAULT_SIZE);
    my_teams->server.sockStruct.sin_family = AF_INET;
    my_teams->server.sockStruct.sin_port = htons(port);
    my_teams->server.sockStruct.sin_addr.s_addr = htonl(INADDR_ANY);
    my_teams->server.peer_addr_size = sizeof(struct sockaddr_in);
    my_teams->server.socket_fd = socket(AF_INET, SOCK_STREAM, 0);
}

int bind_listen(my_teams_t *teams)
{
    int listening = 0;
    int binding = 0;

    binding = bind(teams->server.socket_fd,
    (struct sockaddr *) &teams->server.sockStruct, sizeof(struct sockaddr_in));
    if (binding >= 0)
        printf("Binding successfully\n");
    else
        return ERROR;
    listening = listen(teams->server.socket_fd, 5);
    if (listening >= 0)
        printf("Listening...\n");
    else
        return ERROR;
    return SUCCESS;
}
