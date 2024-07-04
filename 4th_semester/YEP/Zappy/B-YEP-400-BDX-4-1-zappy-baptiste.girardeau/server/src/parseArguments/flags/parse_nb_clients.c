/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** parse_nb_clients
*/

#include "server.h"
#include "utils.h"

int parse_nb_clients(int index, char **argv, zappy_t *zappy)
{
    if (!argv || !zappy || !argv[index] || !my_str_isnum(argv[index])) {
        printf("-c: Invalid number of clients.\n");
        return ERROR;
    }
    zappy->nb_clients_per_team = atoi(argv[index]);
    if (zappy->nb_clients_per_team <= 0) {
        printf("-c: Invalid number of clients.\n");
        return ERROR;
    }
    if (zappy->teams)
        for (int i = 0; i < zappy->nb_teams; i += 1)
            zappy->teams[i].free_slot = zappy->nb_clients_per_team;
    return 1;
}
