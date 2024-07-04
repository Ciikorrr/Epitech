/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** game_utils
*/

#pragma once

#define NB_RESSOURCES 7

typedef struct client_s client_t;
typedef struct zappy_s zappy_t;

static const char *ressources[NB_RESSOURCES] = {"food", "linemate",
    "deraumere", "sibur", "mendiane", "phiras", "thystame"};

typedef enum Ressources_s {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
} Ressources_t;

typedef enum Orientation_s {
    NORTH = 1,
    EAST = 2,
    SOUTH = 3,
    WEST = 4
} Orientation_t;

typedef struct vector_s {
    int x;
    int y;
} vector_t;

typedef struct egg_s {
    int id;
    int player_id;
    vector_t pos;
    struct egg_s *next;
} egg_t;

typedef struct team_s {
    char *name;
    egg_t *eggs;
    int free_slot;
} team_t;

typedef struct tasks_s {
    int id;
    void (*func)(zappy_t *zappy, client_t *client);
    time_t time;
    Ressources_t ress;
    struct tasks_s *next;
} tasks_t;

typedef struct player_s {
    bool is_incanting;
    vector_t coords;
    Orientation_t orientation;
    team_t *team;
    tasks_t *tasks;
    int group_size;
    client_t **group_incantation;
    int inc_level;
    int id;
    int task_id;
    int inventory[NB_RESSOURCES];
    Ressources_t res_t_g;
    char *message;
} player_t;

typedef struct player_list_s {
    client_t *client;
    struct player_list_s *next;
} player_list_t;

typedef struct tile_s {
    int nbplayers;
    int nb_eggs;
    player_list_t *players;
    int ressources[NB_RESSOURCES];
} tile_t;
