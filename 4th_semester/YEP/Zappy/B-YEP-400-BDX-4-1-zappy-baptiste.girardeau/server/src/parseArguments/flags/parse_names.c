/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** parse_names
*/

#include "server.h"
#include "utils.h"

void create_eggs_per_teams(zappy_t *zappy, team_t *team)
{
    vector_t pos = {0, 0};

    for (int i = 0; i < team->free_slot; i += 1) {
        pos.x = random_number(0, zappy->gd.x - 1);
        pos.y = random_number(0, zappy->gd.y - 1);
        push_egg_back(zappy, team, pos, -1);
        zappy->map[pos.y][pos.x].nb_eggs += 1;
    }
}

static int is_team_existing(zappy_t *zappy, char *team)
{
    if (strcmp(team, "") == 0) {
        printf("-n: An empty team name is forbidden.\n");
        return ERROR;
    }
    for (int i = 0; i < zappy->nb_teams; i += 1) {
        if (strcmp(zappy->teams[i].name, team) == 0) {
            printf("-n: Team %s already exists.\n");
            return ERROR;
        }
    }
    return SUCCESS;
}

int parse_names(int index, char **argv, zappy_t *zappy)
{
    int increment = 0;
    int name_ind = 0;

    if (!argv || !zappy || !argv[index])
        return ERROR;
    zappy->teams = malloc(sizeof(team_t) * 64);
    if (!zappy->teams)
        return ERROR;
    for (; argv[index] && argv[index][0] != '-'; index += 1) {
        if (is_team_existing(zappy, argv[index]) == ERROR)
            return ERROR;
        zappy->teams[name_ind].name = strdup(argv[index]);
        zappy->teams[name_ind].eggs = NULL;
        if (zappy->nb_clients_per_team != -1)
            zappy->teams[name_ind].free_slot = zappy->nb_clients_per_team;
        zappy->nb_teams += 1;
        name_ind += 1;
        increment += 1;
    }
    return increment;
}
