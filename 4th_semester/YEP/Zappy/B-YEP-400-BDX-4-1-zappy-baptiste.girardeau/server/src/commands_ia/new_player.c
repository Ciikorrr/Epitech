/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** new_player
*/

#include "server.h"
#include "utils.h"

static int set_player_infos(client_t *client, zappy_t *zappy, int team_ind)
{
    int egg_id = zappy->teams[team_ind].eggs->id;

    client->player = malloc(sizeof(player_t));
    if (!client->player)
        return -1;
    client->player->coords = zappy->teams[team_ind].eggs->pos;
    zappy->teams[team_ind].eggs = pop_front_egg(&zappy->teams[team_ind]);
    zappy->map[client->player->coords.y]
    [client->player->coords.x].nb_eggs -= 1;
    client->player->task_id = 0;
    client->player->orientation = random_number(SOUTH, WEST);
    client->player->tasks = NULL;
    client->player->inc_level = 1;
    client->player->group_incantation = NULL;
    client->player->group_size = 0;
    client->player->is_incanting = false;
    init_ressources(client->player->inventory);
    return egg_id;
}

static void send_new_player_gui(client_t *client, zappy_t *zappy, int egg_id)
{
    if (!zappy->gui)
        return;
    dprintf(zappy->gui->client_socket, "pnw %d %d %d %d %d %s\n",
    client->player->id, client->player->coords.x, client->player->coords.y,
    client->player->orientation, client->player->inc_level,
    client->player->team->name);
    dprintf(zappy->gui->client_socket, "pin %d %d %d %d %d %d %d %d %d %d\n",
    client->player->id, client->player->coords.x, client->player->coords.y,
    client->player->inventory[0], client->player->inventory[1],
    client->player->inventory[2], client->player->inventory[3],
    client->player->inventory[4], client->player->inventory[5],
    client->player->inventory[6]);
    dprintf(zappy->gui->client_socket, "ebo %d\n", egg_id);
    dprintf(zappy->gui->client_socket, "edi %d\n", egg_id);
}

void new_player(zappy_t *zappy, client_t *client, int team_index)
{
    int egg_id = 0;

    if (zappy->teams[team_index].free_slot <= 0 ||
    !zappy->teams[team_index].eggs || client->player) {
        dprintf(client->client_socket, "No eggs available\n");
        return;
    }
    egg_id = set_player_infos(client, zappy, team_index);
    client->player->id = zappy->player_id;
    zappy->player_id += 1;
    client->player->team = &zappy->teams[team_index];
    zappy->teams[team_index].free_slot -= 1;
    client->player->inventory[FOOD] = 10;
    push_back_player(zappy, client);
    zappy->map[client->player->coords.y]
    [client->player->coords.x].nbplayers += 1;
    send_new_player_gui(client, zappy, egg_id);
    dprintf(client->client_socket, "%d\n", zappy->teams[team_index].free_slot);
    dprintf(client->client_socket, "%d %d\n",
    zappy->gd.x, zappy->gd.y);
}
