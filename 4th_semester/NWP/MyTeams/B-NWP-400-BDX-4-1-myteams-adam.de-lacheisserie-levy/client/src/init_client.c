/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** init_client
*/

#include "../../include/client.h"
#include "code_list.h"
#include "protos_clt.h"
#include "../../include/macros.h"

static int code_handler(char **cmd_line)
{
    if (!cmd_line || !cmd_line[0])
        return ERROR;
    for (size_t i = 0; i < 32; i += 1)
        if (strcmp(cmd_line[0], CODE[i].flag) == 0)
            return CODE[i].func(cmd_line);
    return SUCCESS;
}

static void get_input(client_t *client, bool *loop)
{
    fd_set rfds;
    struct timeval tv;
    size_t size;
    char *line = NULL;

    tv.tv_sec = 0;
    tv.tv_usec = 1000;
    FD_ZERO(&rfds);
    FD_SET(STDIN_FILENO, &rfds);
    if (select(STDIN_FILENO + 1, &rfds, NULL, NULL, &tv) > 0) {
        if (getline(&line, &size, stdin) == EOF)
            *loop = false;
        dprintf(client->client_socket, line);
    }
}

static void verif_read(client_t *client)
{
    fd_set rfds;
    struct timeval tv;
    size_t size;
    char **cmd_line;
    char line[BUFSIZ];

    tv.tv_sec = 0;
    tv.tv_usec = 1000;
    FD_ZERO(&rfds);
    FD_SET(client->client_socket, &rfds);
    if (select(client->client_socket + 1, &rfds, NULL, NULL, &tv) > 0) {
        size = read(client->client_socket, line, BUFSIZ);
        line[size] = '\0';
        cmd_line = command_parser(line, " \n");
        code_handler(cmd_line);
    }
}

static int loop_client(client_t *client)
{
    bool loop = true;

    while (loop) {
        get_input(client, &loop);
        verif_read(client);
    }
    return SUCCESS;
}

int create_client(int port, char *address)
{
    client_t client = {0};

    client.client_socket = socket(AF_INET, SOCK_STREAM, 0);
    client.client_struct.sin_family = AF_INET;
    client.client_struct.sin_port = htons(port);
    client.client_struct.sin_addr.s_addr = inet_addr(address);
    if (connect(client.client_socket, (const struct sockaddr *)
    &client.client_struct, sizeof(client.client_struct)) == -1)
        return ERROR;
    return loop_client(&client);
}
