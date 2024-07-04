/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** broadcast
*/

#include "server.h"
#include "utils.h"

static int dist_converted_x(zappy_t *zappy, client_t *client, int x)
{
    int player_dist = abs(x - client->player->coords.x);
    int converted_dist = 0;
    bool is_superior = x > client->player->coords.x;

    while (x != client->player->coords.x) {
        converted_dist += 1;
        if (is_superior)
            x += 1;
        else
            x -= 1;
        if (x < 0)
            x = zappy->gd.x - 1;
        if (x > zappy->gd.x - 1)
            x = 0;
    }
    if (converted_dist > player_dist)
        return player_dist;
    return converted_dist;
}

static int dist_converted_y(zappy_t *zappy, client_t *client, int y)
{
    int player_dist = abs(y - client->player->coords.y);
    int converted_dist = 0;
    bool is_superior = y > client->player->coords.y;

    while (y != client->player->coords.y) {
        converted_dist += 1;
        if (is_superior)
            y += 1;
        else
            y -= 1;
        if (y < 0)
            y = zappy->gd.y - 1;
        if (y > zappy->gd.y - 1)
            y = 0;
    }
    if (converted_dist > player_dist)
        return player_dist;
    return converted_dist;
}

static void get_min_tile
(vector_t values, vector_t *tmp_pos, vector_t *final_pos, vector_t pos_tile)
{
    if (values.x + values.y < tmp_pos->x + tmp_pos->y) {
        tmp_pos->x = values.x;
        tmp_pos->y = values.y;
        final_pos->x = pos_tile.x;
        final_pos->y = pos_tile.y;
    }
}

static bool is_in_the_same_tile(client_t *client, client_t *cli)
{
    if (client->player->coords.x == cli->player->coords.x &&
    client->player->coords.y == cli->player->coords.y) {
        dprintf(cli->client_socket,
        "message 0, %s\n", client->player->message);
        return true;
    }
    return false;
}

static void set_message_orientation
(zappy_t *zappy, client_t *cli, char *msg, vector_t pos)
{
    switch (cli->player->orientation) {
    case NORTH:
        send_message_north(zappy, msg, cli, pos);
        break;
    case EAST:
        send_message_east(zappy, msg, cli, pos);
        break;
    case WEST:
        send_message_west(zappy, msg, cli, pos);
        break;
    default:
        send_message_south(zappy, msg, cli, pos);
        break;
    }
}

static void send_msg_to_player
(zappy_t *zappy, client_t *client, client_t *cli, vector_t tmp_pos)
{
    vector_t values = {0, 0};
    vector_t final_pos = {0, 0};
    vector_t pos_tile =
    {convert(cli->player->coords.x - 1, zappy->gd.x),
    convert(cli->player->coords.y - 1, zappy->gd.y)};
    int tmp_x = pos_tile.x;

    if (is_in_the_same_tile(client, cli))
        return;
    for (int y = 0; y < 3; y += 1) {
        pos_tile.x = tmp_x;
        for (int x = 0; x < 3; x += 1) {
            values.x = dist_converted_x(zappy, client, pos_tile.x);
            values.y = dist_converted_y(zappy, client, pos_tile.y);
            get_min_tile(values, &tmp_pos, &final_pos, pos_tile);
            pos_tile.x = convert(pos_tile.x + 1, zappy->gd.x);
        }
        pos_tile.y = convert(pos_tile.y + 1, zappy->gd.y);
    }
    set_message_orientation(zappy, cli, client->player->message, final_pos);
}

static void broadcast_exec(zappy_t *zappy, client_t *client)
{
    vector_t tmp_pos = {100, 100};

    for (int i = 0; i < zappy->server.nb_clients; i += 1) {
        if (!zappy->clients[i].player ||
        zappy->clients[i].client_socket == client->client_socket)
            continue;
        send_msg_to_player(zappy, client, &zappy->clients[i], tmp_pos);
    }
    if (zappy->gui)
        dprintf(zappy->gui->client_socket, "pbc %d %s\n", client->player->id,
        client->player->message);
    free(client->player->message);
    client->player->message = NULL;
}

void broadcast_text(zappy_t *zappy, client_t *client, char **cmd)
{
    time_t duration = time(NULL) + (7 / zappy->freq);

    if (!cmd[1]) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    if (!client->player) {
        dprintf(client->client_socket, "You're not a player.\n");
        return;
    }
    client->player->message = strdup(cmd[1]);
    push_back_task(client, duration, 0, &broadcast_exec);
}
