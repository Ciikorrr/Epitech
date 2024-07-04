/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** eggs_creator
*/

#include "server.h"

static egg_t *create_egg(int id, int player_id, vector_t pos)
{
    egg_t *egg = malloc(sizeof(egg_t));

    if (!egg)
        return NULL;
    egg->id = id;
    egg->player_id = player_id;
    egg->pos = pos;
    egg->next = NULL;
    return egg;
}

egg_t *push_egg_back(zappy_t *zappy, team_t *team, vector_t pos, int id_player)
{
    egg_t *tmp = team->eggs;

    if (!tmp) {
        team->eggs = create_egg(zappy->egg_id, id_player, pos);
        zappy->egg_id += 1;
        return team->eggs;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = create_egg(zappy->egg_id, id_player, pos);
    zappy->egg_id += 1;
    return tmp->next;
}

egg_t *pop_front_egg(team_t *team)
{
    egg_t *tmp = team->eggs;

    team->eggs = team->eggs->next;
    free(tmp);
    return team->eggs;
}

egg_t *pop_egg(team_t *team, int id)
{
    egg_t *tmp = team->eggs;
    egg_t *prev;

    if (tmp && tmp->id == id)
        return pop_front_egg(team);
    while (tmp && tmp->id != id) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (!tmp)
        return NULL;
    prev->next = tmp->next;
    free(tmp);
    return prev->next;
}

void free_eggs(team_t *team)
{
    egg_t *tmp = NULL;

    while (team->eggs) {
        tmp = team->eggs;
        team->eggs = team->eggs->next;
        free(tmp);
    }
}
