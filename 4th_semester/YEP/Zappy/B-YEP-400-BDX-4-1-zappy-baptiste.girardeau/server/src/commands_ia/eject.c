/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** eject
*/

#include "server.h"
#include "utils.h"

static void send_eject_to_gui
(zappy_t *zappy, client_t *rm_client, Orientation_t orientation)
{
    dprintf(rm_client->client_socket, "eject: %d\n", orientation);
    if (!zappy->gui)
        return;
    dprintf(zappy->gui->client_socket, "pex %d\n", rm_client->player->id);
    dprintf(zappy->gui->client_socket, "ppo %d %d %d %d\n",
    rm_client->player->id, rm_client->player->coords.x,
    rm_client->player->coords.y, rm_client->player->orientation);
}

static egg_t *remove_egg
(zappy_t *zappy, team_t *team, egg_t *egg, vector_t pos)
{
    if (egg->pos.x != pos.x || egg->pos.y != pos.y)
        return egg->next;
    if (zappy->gui)
        dprintf(zappy->gui->client_socket, "edi %d\n", egg->id);
    return pop_egg(team, egg->id);
}

static void remove_eggs(zappy_t *zappy, vector_t pos)
{
    egg_t *tmp = NULL;

    for (int i = 0; i < zappy->nb_teams; i += 1) {
        tmp = zappy->teams[i].eggs;
        while (tmp)
            tmp = remove_egg(zappy, &zappy->teams[i], tmp, pos);
    }
    zappy->map[pos.y][pos.x].nb_eggs = 0;
}

static void eject_north(zappy_t *zappy, client_t *client, vector_t pos)
{
    player_list_t *tmp = zappy->map[pos.y][pos.x].players;
    tile_t *tile = &zappy->map[pos.y][pos.x];
    client_t *rm_client = NULL;

    while (tmp) {
        if (tmp->client->player->id == client->player->id) {
            tmp = tmp->next;
            continue;
        }
        rm_client = tmp->client;
        pop_player(zappy, tmp->client);
        tile->nbplayers -= 1;
        rm_client->player->coords.y =
        convert(rm_client->player->coords.y - 1, zappy->gd.y);
        push_back_player(zappy, rm_client);
        zappy->map[convert(pos.y - 1, zappy->gd.y)][pos.x].nbplayers += 1;
        tmp = zappy->map[pos.y][pos.x].players;
        send_eject_to_gui(zappy, rm_client, NORTH);
    }
}

static void eject_south(zappy_t *zappy, client_t *client, vector_t pos)
{
    player_list_t *tmp = zappy->map[pos.y][pos.x].players;
    tile_t *tile = &zappy->map[pos.y][pos.x];
    client_t *rm_client = NULL;

    while (tmp) {
        if (tmp->client->player->id == client->player->id) {
            tmp = tmp->next;
            continue;
        }
        rm_client = tmp->client;
        pop_player(zappy, tmp->client);
        tile->nbplayers -= 1;
        rm_client->player->coords.y =
        convert(rm_client->player->coords.y + 1, zappy->gd.y);
        push_back_player(zappy, rm_client);
        zappy->map[convert(pos.y + 1, zappy->gd.y)][pos.x].nbplayers += 1;
        tmp = zappy->map[pos.y][pos.x].players;
        send_eject_to_gui(zappy, rm_client, SOUTH);
    }
}

static void eject_east(zappy_t *zappy, client_t *client, vector_t pos)
{
    player_list_t *tmp = zappy->map[pos.y][pos.x].players;
    tile_t *tile = &zappy->map[pos.y][pos.x];
    client_t *rm_client = NULL;

    while (tmp) {
        if (tmp->client->player->id == client->player->id) {
            tmp = tmp->next;
            continue;
        }
        rm_client = tmp->client;
        pop_player(zappy, tmp->client);
        tile->nbplayers -= 1;
        rm_client->player->coords.x =
        convert(rm_client->player->coords.x + 1, zappy->gd.x);
        push_back_player(zappy, rm_client);
        zappy->map[pos.y][convert(pos.x + 1, zappy->gd.x)].nbplayers += 1;
        tmp = zappy->map[pos.y][pos.x].players;
        send_eject_to_gui(zappy, rm_client, EAST);
    }
}

static void eject_west(zappy_t *zappy, client_t *client, vector_t pos)
{
    player_list_t *tmp = zappy->map[pos.y][pos.x].players;
    tile_t *tile = &zappy->map[pos.y][pos.x];
    client_t *rm_client = NULL;

    while (tmp) {
        if (tmp->client->player->id == client->player->id) {
            tmp = tmp->next;
            continue;
        }
        rm_client = tmp->client;
        pop_player(zappy, tmp->client);
        tile->nbplayers -= 1;
        rm_client->player->coords.x =
        convert(rm_client->player->coords.x - 1, zappy->gd.x);
        push_back_player(zappy, rm_client);
        zappy->map[pos.y][convert(pos.x - 1, zappy->gd.x)].nbplayers += 1;
        tmp = zappy->map[pos.y][pos.x].players;
        send_eject_to_gui(zappy, rm_client, WEST);
    }
}

static void remove_players(zappy_t *zappy, client_t *client, vector_t pos)
{
    switch (client->player->orientation) {
        case NORTH:
            eject_north(zappy, client, pos);
            break;
        case SOUTH:
            eject_south(zappy, client, pos);
            break;
        case EAST:
            eject_east(zappy, client, pos);
            break;
        default:
            eject_west(zappy, client, pos);
            break;
    }
}

void eject_function_exec(zappy_t *zappy, client_t *client)
{
    vector_t pos = {client->player->coords.x, client->player->coords.y};

    if (zappy->map[pos.y][pos.x].nb_eggs <= 0 &&
    zappy->map[pos.y][pos.x].nbplayers <= 0) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    if (zappy->map[pos.y][pos.x].nb_eggs > 0)
        remove_eggs(zappy, pos);
    if (zappy->map[pos.y][pos.x].nbplayers > 0)
        remove_players(zappy, client, pos);
    dprintf(client->client_socket, "ok\n");
}

void eject_function(zappy_t *zappy, client_t *client, char **cmd)
{
    time_t duration = time(NULL) + (7 / zappy->freq);

    if (!client->player) {
        dprintf(client->client_socket, "You're not a player.\n");
        return;
    }
    push_back_task(client, duration, 0, &eject_function_exec);
}
