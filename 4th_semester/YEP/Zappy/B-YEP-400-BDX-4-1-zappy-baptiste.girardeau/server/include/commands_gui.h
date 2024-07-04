/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** commands_gui
*/

#pragma once

#include "server.h"

void map_size(zappy_t *zappy, char **cmd);
void content_tile(zappy_t *zappy, char **cmd);
void content_tiles(zappy_t *zappy, char **cmd);
void print_teams(zappy_t *zappy, char **cmd);
void player_position(zappy_t *zappy, char **cmd);
void player_inventory(zappy_t *zappy, char **cmd);
void player_level(zappy_t *zappy, char **cmd);
void set_freq_time(zappy_t *zappy, char **cmd);
void freq_time(zappy_t *zappy, char **cmd);

typedef struct cmd_gui_s {
    char *flag;
    void (*func)(zappy_t *zappy, char **cmd);
} cmd_gui_t;

const cmd_gui_t CMD_GUI[] = {
    {"msz", &map_size},
    {"bct", &content_tile},
    {"mct", &content_tiles},
    {"tna", &print_teams},
    {"ppo", &player_position},
    {"plv", &player_level},
    {"pin", &player_inventory},
    {"sgt", &freq_time},
    {"sst", &set_freq_time},
};
