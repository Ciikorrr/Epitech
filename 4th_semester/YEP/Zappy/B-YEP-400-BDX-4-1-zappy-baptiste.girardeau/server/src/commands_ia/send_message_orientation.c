/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** send_message_orientation
*/

#include "server.h"
#include "utils.h"

static void next_message_north
(vector_t max, char *msg, client_t *cli, vector_t pos)
{
    if (convert(cli->player->coords.x + 1, max.x) == pos.x &&
    convert(cli->player->coords.y + 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 6, %s\n", msg);
    if (convert(cli->player->coords.x + 1, max.x) == pos.x &&
    cli->player->coords.y == pos.y)
        dprintf(cli->client_socket, "message 7, %s\n", msg);
    if (convert(cli->player->coords.x + 1, max.x) == pos.x &&
    convert(cli->player->coords.y - 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 8, %s\n", msg);
}

void send_message_north(zappy_t *zappy, char *msg, client_t *cli, vector_t pos)
{
    vector_t max = zappy->gd;

    if (cli->player->coords.x == pos.x &&
    convert(cli->player->coords.y - 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 1, %s\n", msg);
    if (convert(cli->player->coords.x - 1, max.x) == pos.x &&
    convert(cli->player->coords.y - 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 2, %s\n", msg);
    if (convert(cli->player->coords.x - 1, max.x) == pos.x &&
    cli->player->coords.y == pos.y)
        dprintf(cli->client_socket, "message 3, %s\n", msg);
    if (convert(cli->player->coords.x - 1, max.x) == pos.x &&
    convert(cli->player->coords.y + 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 4, %s\n", msg);
    if (cli->player->coords.x == pos.x &&
    convert(cli->player->coords.y + 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 5, %s\n", msg);
    next_message_north(max, msg, cli, pos);
}

static void next_message_south
(vector_t max, char *msg, client_t *cli, vector_t pos)
{
    if (convert(cli->player->coords.x + 1, max.x) == pos.x &&
    convert(cli->player->coords.y + 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 2, %s\n", msg);
    if (convert(cli->player->coords.x + 1, max.x) == pos.x &&
    cli->player->coords.y == pos.y)
        dprintf(cli->client_socket, "message 3, %s\n", msg);
    if (convert(cli->player->coords.x + 1, max.x) == pos.x &&
    convert(cli->player->coords.y - 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 4, %s\n", msg);
}

void send_message_south(zappy_t *zappy, char *msg, client_t *cli, vector_t pos)
{
    vector_t max = zappy->gd;

    if (cli->player->coords.x == pos.x &&
    convert(cli->player->coords.y - 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 5, %s\n", msg);
    if (convert(cli->player->coords.x - 1, max.x) == pos.x &&
    convert(cli->player->coords.y - 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 6, %s\n", msg);
    if (convert(cli->player->coords.x - 1, max.x) == pos.x &&
    cli->player->coords.y == pos.y)
        dprintf(cli->client_socket, "message 7, %s\n", msg);
    if (convert(cli->player->coords.x - 1, max.x) == pos.x &&
    convert(cli->player->coords.y + 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 8, %s\n", msg);
    if (cli->player->coords.x == pos.x &&
    convert(cli->player->coords.y + 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 1, %s\n", msg);
    next_message_south(max, msg, cli, pos);
}

static void next_message_east
(vector_t max, char *msg, client_t *cli, vector_t pos)
{
    if (convert(cli->player->coords.x + 1, max.x) == pos.x &&
    convert(cli->player->coords.y + 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 8, %s\n", msg);
    if (convert(cli->player->coords.x + 1, max.x) == pos.x &&
    cli->player->coords.y == pos.y)
        dprintf(cli->client_socket, "message 1, %s\n", msg);
    if (convert(cli->player->coords.x + 1, max.x) == pos.x &&
    convert(cli->player->coords.y - 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 2, %s\n", msg);
}

void send_message_east(zappy_t *zappy, char *msg, client_t *cli, vector_t pos)
{
    vector_t max = zappy->gd;

    if (cli->player->coords.x == pos.x &&
    convert(cli->player->coords.y - 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 3, %s\n", msg);
    if (convert(cli->player->coords.x - 1, max.x) == pos.x &&
    convert(cli->player->coords.y - 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 4, %s\n", msg);
    if (convert(cli->player->coords.x - 1, max.x) == pos.x &&
    cli->player->coords.y == pos.y)
        dprintf(cli->client_socket, "message 5, %s\n", msg);
    if (convert(cli->player->coords.x - 1, max.x) == pos.x &&
    convert(cli->player->coords.y + 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 6, %s\n", msg);
    if (cli->player->coords.x == pos.x &&
    convert(cli->player->coords.y + 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 7, %s\n", msg);
    next_message_east(max, msg, cli, pos);
}

static void next_message_west
(vector_t max, char *msg, client_t *cli, vector_t pos)
{
    if (convert(cli->player->coords.x + 1, max.x) == pos.x &&
    convert(cli->player->coords.y + 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 4, %s\n", msg);
    if (convert(cli->player->coords.x + 1, max.x) == pos.x &&
    cli->player->coords.y == pos.y)
        dprintf(cli->client_socket, "message 5, %s\n", msg);
    if (convert(cli->player->coords.x + 1, max.x) == pos.x &&
    convert(cli->player->coords.y - 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 6, %s\n", msg);
}

void send_message_west(zappy_t *zappy, char *msg, client_t *cli, vector_t pos)
{
    vector_t max = zappy->gd;

    if (cli->player->coords.x == pos.x &&
    convert(cli->player->coords.y - 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 7, %s\n", msg);
    if (convert(cli->player->coords.x - 1, max.x) == pos.x &&
    convert(cli->player->coords.y - 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 8, %s\n", msg);
    if (convert(cli->player->coords.x - 1, max.x) == pos.x &&
    cli->player->coords.y == pos.y)
        dprintf(cli->client_socket, "message 1, %s\n", msg);
    if (convert(cli->player->coords.x - 1, max.x) == pos.x &&
    convert(cli->player->coords.y + 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 2, %s\n", msg);
    if (cli->player->coords.x == pos.x &&
    convert(cli->player->coords.y + 1, max.y) == pos.y)
        dprintf(cli->client_socket, "message 3, %s\n", msg);
    next_message_west(max, msg, cli, pos);
}
