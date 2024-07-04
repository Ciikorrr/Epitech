/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** turn_functions
*/

#include "server.h"
#include "utils.h"

void turn_left_exec(zappy_t *zappy, client_t *client)
{
    client->player->orientation -= 1;
    if (client->player->orientation < 1)
        client->player->orientation = WEST;
    dprintf(client->client_socket, "ok\n");
    if (zappy->gui)
        dprintf(zappy->gui->client_socket, "ppo %d %d %d %d\n",
        client->player->id, client->player->coords.x,
        client->player->coords.y, client->player->orientation);
}

void turn_right_exec(zappy_t *zappy, client_t *client)
{
    client->player->orientation += 1;
    if (client->player->orientation > 4)
        client->player->orientation = NORTH;
    dprintf(client->client_socket, "ok\n");
    if (zappy->gui)
        dprintf(zappy->gui->client_socket, "ppo %d %d %d %d\n",
        client->player->id, client->player->coords.x,
        client->player->coords.y, client->player->orientation);
}

void turn_left(zappy_t *zappy, client_t *client, char **cmd)
{
    time_t duration = time(NULL) + (7 / zappy->freq);

    (void)cmd;
    if (!client->player) {
        dprintf(client->client_socket, "You're not a player.\n");
        return;
    }
    push_back_task(client, duration, 0, &turn_left_exec);
}

void turn_right(zappy_t *zappy, client_t *client, char **cmd)
{
    time_t duration = time(NULL) + (7 / zappy->freq);

    (void)cmd;
    if (!client->player) {
        dprintf(client->client_socket, "You're not a player.\n");
        return;
    }
    push_back_task(client, duration, 0, &turn_right_exec);
}
