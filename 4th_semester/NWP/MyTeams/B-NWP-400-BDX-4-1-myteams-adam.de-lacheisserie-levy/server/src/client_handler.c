/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** client_handler
*/

#include "../../include/server.h"
#include "protos_srv.h"
#include "../../include/macros.h"

static void free_clients(my_teams_t *teams)
{
    free(teams->users);
}

static void set_client_struct
(my_teams_t *team, client_t *clients, int nb_clients)
{
    clients[nb_clients].client_socket = team->server.acceptation;
    clients[nb_clients].user = NULL;
}

static void add_client(my_teams_t *teams, client_t *clients, int *nb_clients)
{
    struct sockaddr_in client_struct;
    fd_set fd_read;
    fd_set fd_write;
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 1000;
    FD_ZERO(&fd_read);
    FD_ZERO(&fd_write);
    FD_SET(teams->server.socket_fd, &fd_read);
    FD_SET(teams->server.socket_fd, &fd_write);
    if (select(teams->server.socket_fd + 1,
    &fd_read, &fd_write, NULL, &tv) <= 0)
        return;
    teams->server.acceptation = accept(teams->server.socket_fd,
    (struct sockaddr *) &client_struct, &teams->server.peer_addr_size);
    set_client_struct(teams, clients, *nb_clients);
    *nb_clients += 1;
}

static void client_connexion
(my_teams_t *my_teams, client_t *clients, int nb_clients)
{
    fd_set fd_tab;
    struct timeval tv;
    size_t size;
    char line[BUFSIZ];
    char **cmd_line;

    tv.tv_sec = 0;
    tv.tv_usec = 1000;
    for (int i = 0; i < nb_clients; i += 1) {
        FD_ZERO(&fd_tab);
        FD_SET(clients[i].client_socket, &fd_tab);
        if (select(clients[i].client_socket + 1,
        &fd_tab, NULL, NULL, &tv) <= 0)
            continue;
        size = read(clients[i].client_socket, line, BUFSIZ);
        line[size] = '\0';
        cmd_line = command_parser(line, " \n");
        command_handler(my_teams, cmd_line, &clients[i]);
    }
}

int client_handler(my_teams_t *my_teams)
{
    client_t *clients = malloc(sizeof(client_t) * DEFAULT_SIZE);
    int nb_clients = 0;

    while (1) {
        add_client(my_teams, clients, &nb_clients);
        client_connexion(my_teams, clients, nb_clients);
    }
    free_clients(my_teams);
    return SUCCESS;
}
