/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** setup_zappy
*/

#include "server.h"
#include "utils.h"
#include "flags.h"

static void display_infos(zappy_t *zappy)
{
    printf("=======================ZAPPY INFOS========================\n");
    printf("Port: %d\n", htons(zappy->server.sockStruct.sin_port));
    printf("Width: %d\n", zappy->gd.x);
    printf("Height: %d\n", zappy->gd.y);
    printf("Clients per team: %d\n", zappy->nb_clients_per_team);
    printf("Freq: %d\n", zappy->freq);
    printf("Nb Teams: %d\n", zappy->nb_teams);
    for (int i = 0; i < zappy->nb_teams; i += 1) {
        printf("Team %s:\n", zappy->teams[i].name);
        printf("\tNb Players: %d\n", zappy->nb_clients_per_team -
        zappy->teams[i].free_slot);
        printf("\tNb eggs: %d\n", zappy->teams[i].free_slot);
    }
    printf("==========================================================\n");
}

static void set_max_ressources(zappy_t *zappy, vector_t dimensions)
{
    zappy->max_ressources[FOOD] = dimensions.x * dimensions.y * 0.5;
    zappy->max_ressources[LINEMATE] = dimensions.x * dimensions.y * 0.3;
    zappy->max_ressources[DERAUMERE] = dimensions.x * dimensions.y * 0.15;
    zappy->max_ressources[SIBUR] = dimensions.x * dimensions.y * 0.1;
    zappy->max_ressources[MENDIANE] = dimensions.x * dimensions.y * 0.1;
    zappy->max_ressources[PHIRAS] = dimensions.x * dimensions.y * 0.08;
    zappy->max_ressources[THYSTAME] = dimensions.x * dimensions.y * 0.05;
}

static void free_client_map(tile_t *tile)
{
    player_list_t *tmp;

    if (!tile->players)
        return;
    while (tile->players) {
        tmp = tile->players;
        tile->players = tile->players->next;
        free(tmp);
    }
}

void free_map(zappy_t *zappy)
{
    for (int y = 0; y < zappy->gd.y; y += 1) {
        for (int x = 0; x < zappy->gd.x; x += 1)
            free_client_map(&zappy->map[y][x]);
        free(zappy->map[y]);
    }
    free(zappy->map);
}

static void setup_struct_zappy(zappy_t *zappy)
{
    srand(time(NULL));
    zappy->server.nb_clients = 0;
    zappy->egg_id = 0;
    zappy->nb_clients_per_team = 5;
    zappy->nb_teams = 0;
    zappy->freq = 100;
    zappy->gd.x = 10;
    zappy->gd.y = 10;
    zappy->server.socket_fd = -1;
    zappy->teams = NULL;
    zappy->server.peer_addr_size = sizeof(struct sockaddr_in);
    zappy->gui = NULL;
    zappy->player_id = 0;
}

void init_ressources(int *ressources)
{
    for (int i = 0; i < 7; i += 1)
        ressources[i] = 0;
}

static tile_t **init_map(tile_t **map, vector_t dimensions)
{
    int index = 0;

    map = malloc(sizeof(tile_t *) * (dimensions.y));
    if (!map)
        return NULL;
    for (int y = 0; y < dimensions.y; y += 1) {
        map[y] = malloc(sizeof(tile_t) * dimensions.x);
        if (!map[y])
            return NULL;
        for (int x = 0; x < dimensions.x; x += 1) {
            map[y][x].nbplayers = 0;
            map[y][x].nb_eggs = 0;
            map[y][x].players = NULL;
            init_ressources(map[y][x].ressources);
        }
    }
    return map;
}

static int select_flag(int index, char **argv, zappy_t *zappy)
{
    if (!argv || !zappy)
        return ERROR;
    for (size_t i = 0; i < 6; i += 1)
        if (strcmp(FLAGS[i].flag, argv[index]) == 0)
            return FLAGS[i].func(index + 1, argv, zappy);
    return SUCCESS;
}

static int check_errors(zappy_t *zappy)
{
    if (zappy->server.socket_fd == -1) {
        printf("You have to specify a port number.\n");
        return ERROR;
    }
    if (zappy->nb_teams <= 0) {
        printf("You have to specify at least one team name.\n");
        return ERROR;
    }
    return SUCCESS;
}

int setup_zappy(int argc, char **argv, zappy_t *zappy)
{
    if (!argv || !zappy)
        return ERROR;
    setup_struct_zappy(zappy);
    for (size_t i = 1; i < argc; i += 1) {
        i += select_flag(i, argv, zappy);
        if (i >= 84)
            return ERROR;
    }
    if (check_errors(zappy) == ERROR)
        return ERROR;
    zappy->map = init_map(zappy->map, zappy->gd);
    for (int t = 0; t < zappy->nb_teams; t += 1)
        create_eggs_per_teams(zappy, &zappy->teams[t]);
    zappy->time_to_eat = time(NULL) + 126 / zappy->freq;
    zappy->refill_ressources = time(NULL) + 20 / zappy->freq;
    set_max_ressources(zappy, zappy->gd);
    fill_ressources(zappy);
    display_infos(zappy);
    return SUCCESS;
}
