/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** Flags
*/

#pragma once
#include "server.h"

int parse_port(int index, char **argv, zappy_t *zappy);
int parse_height(int index, char **argv, zappy_t *zappy);
int parse_width(int index, char **argv, zappy_t *zappy);
int parse_nb_clients(int index, char **argv, zappy_t *zappy);
int parse_freq(int index, char **argv, zappy_t *zappy);
int parse_names(int index, char **argv, zappy_t *zappy);

typedef struct object_s {
    const char *flag;
    int (*func)(int, char **, zappy_t *);
} object_t;

const object_t FLAGS[] = {
    {"-p", &parse_port},
    {"-x", &parse_width},
    {"-y", &parse_height},
    {"-c", &parse_nb_clients},
    {"-f", &parse_freq},
    {"-n", &parse_names},
};
