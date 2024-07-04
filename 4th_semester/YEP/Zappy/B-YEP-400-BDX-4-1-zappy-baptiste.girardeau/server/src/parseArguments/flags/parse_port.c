/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** parse_port
*/

#include "server.h"
#include "utils.h"

static int bind_listen(server_t *server)
{
    int listening = 0;
    int binding = 0;

    binding = bind(server->socket_fd,
    (struct sockaddr *) &server->sockStruct, sizeof(struct sockaddr_in));
    if (binding < 0)
        return ERROR;
    listening = listen(server->socket_fd, 5);
    if (listening < 0)
        return ERROR;
    return 1;
}

int parse_port(int index, char **argv, zappy_t *zappy)
{
    int port = 0;

    if (!argv || !zappy || !argv[index] || !my_str_isnum(argv[index])) {
        printf("-p: Wrong port number.\n");
        return ERROR;
    }
    port = atoi(argv[index]);
    if (port <= 0) {
        printf("-p: Wrong port number.\n");
        return ERROR;
    }
    zappy->server.sockStruct.sin_family = AF_INET;
    zappy->server.sockStruct.sin_port = htons(atoi(argv[index]));
    zappy->server.sockStruct.sin_addr.s_addr = htonl(INADDR_ANY);
    zappy->server.socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    return bind_listen(&zappy->server);
}
