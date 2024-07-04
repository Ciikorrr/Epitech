/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** server
*/

#pragma once

#include <time.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include "game_utils.h"

#define ERROR 84
#define SUCCESS 0

typedef struct server_s {
    int socket_fd;
    int acceptation;
    struct sockaddr_in sockStruct;
    socklen_t peer_addr_size;
    int nb_clients;
} server_t;

typedef struct client_s {
    int client_socket;
    player_t *player;
} client_t;

typedef struct buffer_s {
    char *buf;
    struct buffer_s *next;
} buffer_t;

typedef struct zappy_s {
    int freq;
    int nb_teams;
    int nb_clients_per_team;
    int player_id;
    int egg_id;
    fd_set fdrw;
    team_t *teams;
    vector_t gd;
    server_t server;
    client_t clients[1024];
    client_t *gui;
    tile_t **map;
    time_t time_to_eat;
    time_t refill_ressources;
    buffer_t *cmds;
    int max_ressources[NB_RESSOURCES];
    int quantity_ressources[NB_RESSOURCES];
} zappy_t;

int setup_zappy(int argc, char **argv, zappy_t *zappy);
int launch_zappy_server(zappy_t *zappy);
void handle_command(char **cmd, zappy_t *zappy, client_t *client);
void handle_command_gui(char **cmd, zappy_t *zappy);
void fill_ressources(zappy_t *zappy);
void refill_ressources(zappy_t *zappy);
