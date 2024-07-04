/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** commands
*/

#pragma once
#include "server.h"

void display_inventory(zappy_t *zappy, client_t *client, char **cmd);
void new_player(zappy_t *zappy, client_t *client, int team_index);
void turn_left(zappy_t *zappy, client_t *client, char **cmd);
void turn_right(zappy_t *zappy, client_t *client, char **cmd);
void display_connect_nbr(zappy_t *zappy, client_t *client, char **cmd);
void move_forward(zappy_t *zappy, client_t *client, char **cmd);
void create_gui_client(zappy_t *zappy, client_t *client, char **cmd);
void fork_player(zappy_t *zappy, client_t *client, char **cmd);
void elevation(zappy_t *zappy, client_t *client, char **cmd);
void look_function(zappy_t *zappy, client_t *client, char **cmd);
void take_object(zappy_t *zappy, client_t *client, char **cmd);
void set_object(zappy_t *zappy, client_t *client, char **cmd);
void broadcast_text(zappy_t *zappy, client_t *client, char **cmd);
void eject_function(zappy_t *zappy, client_t *client, char **cmd);

typedef struct cmd_s {
    char *flag;
    void (*func)(zappy_t *zappy, client_t *client, char **cmd);
} cmd_t;

const cmd_t COMMANDS[] = {
    {"Inventory", &display_inventory},
    {"Left", &turn_left},
    {"Right", &turn_right},
    {"Connect_nbr", &display_connect_nbr},
    {"Forward", &move_forward},
    {"Fork", &fork_player},
    {"Incantation", &elevation},
    {"Take", &take_object},
    {"Set", &set_object},
    {"Look", &look_function},
    {"Broadcast", &broadcast_text},
    {"Eject", &eject_function},
    {"GRAPHIC", &create_gui_client},
};
