/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #include <uuid/uuid.h>
    #include <arpa/inet.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <dlfcn.h>
    #include <unistd.h>
    #include "macros.h"

typedef struct team_s team_t;

typedef enum context_s {
    UNDEFINED,
    TEAM,
    CHANNEL,
    THREAD
} context_t;

typedef struct messages_s {
    char *sender_uuid;
    char *msg;
    time_t timestamp;
} messages_t;

typedef struct chat_s {
    int nb_msg;
    messages_t *mess;
    char *user_id;
} chat_t;

typedef struct user_s {
    uuid_t uuid;
    int nb_sockets;
    int tm_ctxt;
    int chl_ctxt;
    int thd_ctxt;
    int nb_team;
    context_t context;
    int is_logged;
    char *user_name;
    int client_socket[10];
    struct sockaddr_in client_struct;
    team_t *teams;
    chat_t *chats;
    int nb_chats;
} user_t;

typedef struct client_s {
    int client_socket;
    int index_socket;
    struct sockaddr_in client_struct;
    user_t *user;
} client_t;

#endif /* !CLIENT_H_ */
