/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** inventory
*/

#include "server.h"
#include "utils.h"

static void display_inventory_exec(zappy_t *zappy, client_t *client)
{
    char buf[512];

    snprintf(buf, sizeof(buf), "[");
    for (int i = 0; i < NB_RESSOURCES; i += 1) {
        if (i + 1 == NB_RESSOURCES)
            snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf),
            "%s %d]", ressources[i], client->player->inventory[i]);
        else
            snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf),
            "%s %d, ", ressources[i], client->player->inventory[i]);
    }
    dprintf(client->client_socket, "%s\n", buf);
}

void display_inventory(zappy_t *zappy, client_t *client, char **cmd)
{
    time_t duration = time(NULL) + (1 / zappy->freq);

    (void)cmd;
    if (!client->player) {
        dprintf(client->client_socket, "You're not a player.\n");
        return;
    }
    push_back_task(client, duration, 0, &display_inventory_exec);
}
