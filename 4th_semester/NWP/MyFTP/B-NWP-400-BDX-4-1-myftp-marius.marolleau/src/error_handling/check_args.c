/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** check_args
*/
#include "../../include/macros.h"
#include "../../include/error_handling.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

static int check_path(char const *str)
{
    DIR *directory = opendir(str);

    if (!directory)
        return ERROR;
    return SUCCESS;
}

static void display_usage(void)
{
    printf("USAGE: ./myftp port path\
    \n\tport  is thoe port number on which the server socket listens\
    \n\tpath  is the path to the home directory for the Anonymous user");
}

int check_args(const int nb_args, char const *argv[])
{
    if (nb_args == 2) {
        if (!argv || !argv[1])
            return ERROR;
        if (strcmp(argv[1], "-help") == 0) {
            display_usage();
            return EXIT;
        }
    }
    if (nb_args == 3) {
        if (!argv || !argv[1] || !argv[2])
            return ERROR;
        if (string_is_num(argv[1]) == ERROR)
            return ERROR;
        if (atoi(argv[1]) > 65535 || atoi(argv[1]) < 1024)
            return ERROR;
        if (check_path(argv[2]) == ERROR)
            return ERROR;
        return SUCCESS;
    }
    return ERROR;
}
