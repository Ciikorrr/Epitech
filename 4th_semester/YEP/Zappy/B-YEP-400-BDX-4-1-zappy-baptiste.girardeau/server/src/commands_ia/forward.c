/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** forward
*/

#include "server.h"
#include "utils.h"

static void move_north_exec(zappy_t *zappy, client_t *client)
{
    zappy->map
    [client->player->coords.y][client->player->coords.x].nbplayers --;
    pop_player(zappy, client);
    if (client->player->coords.y - 1 < 0)
        client->player->coords.y = zappy->gd.y - 1;
    else
        client->player->coords.y -= 1;
    push_back_player(zappy, client);
    zappy->map
    [client->player->coords.y][client->player->coords.x].nbplayers ++;
    dprintf(client->client_socket, "ok\n");
    if (zappy->gui)
        dprintf(zappy->gui->client_socket, "ppo %d %d %d %d\n",
        client->player->id, client->player->coords.x,
        client->player->coords.y, client->player->orientation);
}

static void move_north(zappy_t *zappy, client_t *client)
{
    time_t duration = time(NULL) + (7 / zappy->freq);

    push_back_task(client, duration, 0, &move_north_exec);
}

static void move_south_exec(zappy_t *zappy, client_t *client)
{
    zappy->map
    [client->player->coords.y][client->player->coords.x].nbplayers --;
    pop_player(zappy, client);
    if (client->player->coords.y + 1 >= zappy->gd.y)
        client->player->coords.y = 0;
    else
        client->player->coords.y += 1;
    push_back_player(zappy, client);
    zappy->map
    [client->player->coords.y][client->player->coords.x].nbplayers ++;
    dprintf(client->client_socket, "ok\n");
    if (zappy->gui)
        dprintf(zappy->gui->client_socket, "ppo %d %d %d %d\n",
        client->player->id, client->player->coords.x,
        client->player->coords.y, client->player->orientation);
}

static void move_south(zappy_t *zappy, client_t *client)
{
    time_t duration = time(NULL) + (7 / zappy->freq);

    push_back_task(client, duration, 0, &move_south_exec);
}

static void move_east_exec(zappy_t *zappy, client_t *client)
{
    zappy->map
    [client->player->coords.y][client->player->coords.x].nbplayers --;
    pop_player(zappy, client);
    if (client->player->coords.x + 1 >= zappy->gd.x)
        client->player->coords.x = 0;
    else
        client->player->coords.x += 1;
    push_back_player(zappy, client);
    zappy->map
    [client->player->coords.y][client->player->coords.x].nbplayers ++;
    dprintf(client->client_socket, "ok\n");
    if (zappy->gui)
        dprintf(zappy->gui->client_socket, "ppo %d %d %d %d\n",
        client->player->id, client->player->coords.x,
        client->player->coords.y, client->player->orientation);
}

static void move_east(zappy_t *zappy, client_t *client)
{
    time_t duration = time(NULL) + (7 / zappy->freq);

    push_back_task(client, duration, 0, &move_east_exec);
}

static void move_west_exec(zappy_t *zappy, client_t *client)
{
    zappy->map
    [client->player->coords.y][client->player->coords.x].nbplayers --;
    pop_player(zappy, client);
    if (client->player->coords.x - 1 < 0)
        client->player->coords.x = zappy->gd.x - 1;
    else
        client->player->coords.x -= 1;
    push_back_player(zappy, client);
    zappy->map
    [client->player->coords.y][client->player->coords.x].nbplayers ++;
    dprintf(client->client_socket, "ok\n");
    if (zappy->gui)
        dprintf(zappy->gui->client_socket, "ppo %d %d %d %d\n",
        client->player->id, client->player->coords.x,
        client->player->coords.y, client->player->orientation);
}

static void move_west(zappy_t *zappy, client_t *client)
{
    time_t duration = time(NULL) + (7 / zappy->freq);

    push_back_task(client, duration, 0, &move_west_exec);
}

void move_forward(zappy_t *zappy, client_t *client, char **cmd)
{
    (void)cmd;
    if (!client->player) {
        dprintf(client->client_socket, "You're not a player.\n");
        return;
    }
    switch (client->player->orientation) {
    case NORTH:
        move_north(zappy, client);
        break;
    case SOUTH:
        move_south(zappy, client);
        break;
    case WEST:
        move_west(zappy, client);
        break;
    default:
        move_east(zappy, client);
        break;
    }
}
