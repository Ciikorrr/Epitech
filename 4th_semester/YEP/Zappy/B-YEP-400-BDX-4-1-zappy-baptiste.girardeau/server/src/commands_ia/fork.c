/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** fork
*/

#include "server.h"
#include "utils.h"

static void fork_player_exec(zappy_t *zappy, client_t *client)
{
    egg_t *egg = NULL;

    if (client->player->team->free_slot <= 0) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    egg = push_egg_back(zappy, client->player->team,
    client->player->coords, client->player->id);
    print_egg(zappy, egg);
    zappy->map[egg->pos.y][egg->pos.x].nb_eggs += 1;
    client->player->team->free_slot += 1;
    dprintf(client->client_socket, "ok\n");
}

void fork_player(zappy_t *zappy, client_t *client, char **cmd)
{
    time_t duration = time(NULL) + (42 / zappy->freq);

    (void)cmd;
    if (!client->player) {
        dprintf(client->client_socket, "You're not a player\n");
        return;
    }
    if (client->player->team->free_slot <= 0) {
        dprintf(client->client_socket, "ko\n");
        return;
    }
    if (zappy->gui)
        dprintf(zappy->gui->client_socket, "pfk %d\n", client->player->id);
    push_back_task(client, duration, 0, &fork_player_exec);
}
