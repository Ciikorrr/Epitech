/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** player_chained_list
*/

#include "server.h"

static player_list_t *create_player(client_t *player)
{
    player_list_t *new_player = malloc(sizeof(player_list_t));

    if (!new_player)
        return NULL;
    new_player->client = player;
    new_player->next = NULL;
    return new_player;
}

void push_back_player(zappy_t *zappy, client_t *client)
{
    player_list_t *tmp = zappy->map
    [client->player->coords.y][client->player->coords.x].players;

    if (!tmp) {
        zappy->map
        [client->player->coords.y][client->player->coords.x].players =
        create_player(client);
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = create_player(client);
}

void pop_front_player(zappy_t *zappy, client_t *client)
{
    player_list_t *tmp = zappy->map
    [client->player->coords.y][client->player->coords.x].players;

    zappy->map
    [client->player->coords.y][client->player->coords.x].players = zappy->map
    [client->player->coords.y][client->player->coords.x].players->next;
    free(tmp);
}

void pop_player(zappy_t *zappy, client_t *client)
{
    player_list_t *tmp = zappy->map
    [client->player->coords.y][client->player->coords.x].players;
    player_list_t *prev;

    if (tmp && tmp->client->player->id == client->player->id) {
        pop_front_player(zappy, client);
        return;
    }
    while (tmp && tmp->client->player->id != client->player->id) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (!tmp)
        return;
    prev->next = tmp->next;
    free(tmp);
}
