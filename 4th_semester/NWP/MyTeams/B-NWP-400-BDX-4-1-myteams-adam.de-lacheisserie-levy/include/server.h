/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <unistd.h>
    #include <uuid/uuid.h>
    #include <arpa/inet.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <dlfcn.h>
    #include <time.h>
    #include "client.h"
    #include "../libs/myteams/logging_server.h"
    #include "../libs/myteams/logging_client.h"

typedef struct comment_s {
    char *content;
    time_t timestamp;
    uuid_t sender_uuid;
    user_t *users;
} comment_t;

typedef struct thread_s {
    uuid_t uuid;
    int nb_comment;
    char *title;
    char *content;
    time_t date;
    comment_t *comments;
} thread_t;

typedef struct channel_s {
    uuid_t uuid;
    char *name;
    char *channel_description;
    int nb_threads;
    thread_t *threads;
} channel_t;

typedef struct team_s {
    bool is_subscribe;
    int nb_channels;
    uuid_t uuid;
    char *name;
    char *team_description;
    channel_t *channels;
} team_t;

typedef struct server_s {
    int socket_fd;
    int acceptation;
    socklen_t peer_addr_size;
    struct sockaddr_in sockStruct;
} server_t;

typedef struct my_teams_s {
    int nb_clients_connected;
    int nb_users;
    int nb_team;
    char *path;
    team_t *teams;
    user_t *users;
    server_t server;
    char tmpUuid[37];
    void *h;
} my_teams_t;

#endif /* !SERVER_H_ */
