/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** elevation
*/

#include "server.h"
#include "utils.h"

static void send_to_gui(zappy_t *zappy, client_t *client, vector_t pos)
{
    char buf[512];

    snprintf(buf, sizeof(buf), "pic %d %d %d %d ", pos.x, pos.y, 2,
    client->player->id);
    if (!client->player->group_incantation[0]) {
        free(client->player->group_incantation);
        client->player->group_size = 0;
        client->player->group_incantation = NULL;
        return;
    }
    for (int i = 0; i < client->player->group_size; i += 1) {
        snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), "%d ",
        client->player->group_incantation[i]->player->id);
    }
    if (zappy->gui)
        dprintf(zappy->gui->client_socket, "%s\n", buf);
}

static void send_elevation_underway
(int nb_msgs, client_t *client, int lvl, tile_t tile)
{
    player_list_t *tmp = tile.players;
    int count = 0;

    client->player->group_incantation = malloc(sizeof(client_t *) * nb_msgs);
    if (!client->player->group_incantation)
        return;
    client->player->group_incantation[0] = NULL;
    client->player->group_size = nb_msgs;
    while (tmp && count != nb_msgs) {
        if (tmp->client->player->inc_level == lvl &&
        tmp->client->client_socket != client->client_socket &&
        !tmp->client->player->is_incanting) {
            dprintf(tmp->client->client_socket, "Elevation underway\n");
            tmp->client->player->is_incanting = true;
            client->player->group_incantation[count] = tmp->client;
            count += 1;
        }
        tmp = tmp->next;
    }
}

static void level_one(zappy_t *zappy, client_t *client)
{
    vector_t pos = client->player->coords;
    time_t duration = time(NULL) + (300 / zappy->freq);

    if (zappy->map[pos.y][pos.x].ressources[LINEMATE] <= 0) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    dprintf(client->client_socket, "Elevation underway\n");
    client->player->is_incanting = true;
    if (zappy->gui)
        dprintf(zappy->gui->client_socket, "pic %d %d %d %d\n", pos.x, pos.y,
        1, client->player->id);
    push_back_task(client, duration, 0, &level_one_exec);
}

static void level_two(zappy_t *zappy, client_t *client)
{
    vector_t pos = client->player->coords;
    time_t duration = time(NULL) + (300 / zappy->freq);
    char buf[512];

    if (zappy->map[pos.y][pos.x].ressources[LINEMATE] <= 0 ||
        zappy->map[pos.y][pos.x].ressources[DERAUMERE] <= 0 ||
        zappy->map[pos.y][pos.x].ressources[SIBUR] <= 0 ||
        number_of_users(2, &zappy->map[pos.y][pos.x]) < 2) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    dprintf(client->client_socket, "Elevation underway\n");
    client->player->is_incanting = true;
    send_elevation_underway(1, client, 2, zappy->map[pos.y][pos.x]);
    send_to_gui(zappy, client, pos);
    push_back_task(client, duration, 0, &level_two_exec);
}

static void level_three(zappy_t *zappy, client_t *client)
{
    vector_t pos = client->player->coords;
    time_t duration = time(NULL) + (300 / zappy->freq);

    if (zappy->map[pos.y][pos.x].ressources[LINEMATE] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[PHIRAS] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[SIBUR] <= 0 ||
        number_of_users(3, &zappy->map[pos.y][pos.x]) < 2) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    dprintf(client->client_socket, "Elevation underway\n");
    client->player->is_incanting = true;
    send_elevation_underway(1, client, 3, zappy->map[pos.y][pos.x]);
    send_to_gui(zappy, client, pos);
    push_back_task(client, duration, 0, &level_three_exec);
}

static void level_four(zappy_t *zappy, client_t *client)
{
    vector_t pos = client->player->coords;
    time_t duration = time(NULL) + (300 / zappy->freq);

    if (zappy->map[pos.y][pos.x].ressources[LINEMATE] <= 0 ||
        zappy->map[pos.y][pos.x].ressources[DERAUMERE] <= 0 ||
        zappy->map[pos.y][pos.x].ressources[SIBUR] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[PHIRAS] <= 0 ||
        number_of_users(4, &zappy->map[pos.y][pos.x]) < 4) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    dprintf(client->client_socket, "Elevation underway\n");
    client->player->is_incanting = true;
    send_elevation_underway(3, client, 4, zappy->map[pos.y][pos.x]);
    send_to_gui(zappy, client, pos);
    push_back_task(client, duration, 0, &level_four_exec);
}

static void level_five(zappy_t *zappy, client_t *client)
{
    vector_t pos = client->player->coords;
    time_t duration = time(NULL) + (300 / zappy->freq);

    if (zappy->map[pos.y][pos.x].ressources[LINEMATE] <= 0 ||
        zappy->map[pos.y][pos.x].ressources[DERAUMERE] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[SIBUR] <= 0 ||
        zappy->map[pos.y][pos.x].ressources[MENDIANE] <= 2 ||
        number_of_users(5, &zappy->map[pos.y][pos.x]) < 4) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    dprintf(client->client_socket, "Elevation underway\n");
    client->player->is_incanting = true;
    send_elevation_underway(3, client, 5, zappy->map[pos.y][pos.x]);
    send_to_gui(zappy, client, pos);
    push_back_task(client, duration, 0, &level_five_exec);
}

static void level_six(zappy_t *zappy, client_t *client)
{
    vector_t pos = client->player->coords;
    time_t duration = time(NULL) + (300 / zappy->freq);

    if (zappy->map[pos.y][pos.x].ressources[LINEMATE] <= 0 ||
        zappy->map[pos.y][pos.x].ressources[DERAUMERE] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[SIBUR] <= 2 ||
        zappy->map[pos.y][pos.x].ressources[PHIRAS] <= 0 ||
        number_of_users(6, &zappy->map[pos.y][pos.x]) < 6) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    dprintf(client->client_socket, "Elevation underway\n");
    client->player->is_incanting = true;
    send_elevation_underway(5, client, 6, zappy->map[pos.y][pos.x]);
    send_to_gui(zappy, client, pos);
    push_back_task(client, duration, 0, &level_six_exec);
}

static void level_seven(zappy_t *zappy, client_t *client)
{
    vector_t pos = client->player->coords;
    time_t duration = time(NULL) + (300 / zappy->freq);

    if (zappy->map[pos.y][pos.x].ressources[LINEMATE] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[DERAUMERE] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[SIBUR] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[MENDIANE] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[PHIRAS] <= 1 ||
        zappy->map[pos.y][pos.x].ressources[THYSTAME] <= 0 ||
        number_of_users(7, &zappy->map[pos.y][pos.x]) < 6) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    dprintf(client->client_socket, "Elevation underway\n");
    client->player->is_incanting = true;
    send_elevation_underway(5, client, 6, zappy->map[pos.y][pos.x]);
    send_to_gui(zappy, client, pos);
    push_back_task(client, duration, 0, &level_seven_exec);
}

void elevation(zappy_t *zappy, client_t *client, char **cmd)
{
    (void)cmd;
    if (!client->player) {
        dprintf(client->client_socket, "You're not a player.\n");
        return;
    }
    if (client->player->inc_level == 1)
        return level_one(zappy, client);
    if (client->player->inc_level == 2)
        return level_two(zappy, client);
    if (client->player->inc_level == 3)
        return level_three(zappy, client);
    if (client->player->inc_level == 4)
        return level_four(zappy, client);
    if (client->player->inc_level == 5)
        return level_five(zappy, client);
    if (client->player->inc_level == 6)
        return level_six(zappy, client);
    if (client->player->inc_level == 7)
        return level_seven(zappy, client);
}
