/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** check_args_srv
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "../../include/protos_srv.h"
#include "../../../include/macros.h"

static
int display_usage(void)
{
    char buffer[4096];
    int fd = open("server/src/error_handling/usage.txt", O_RDONLY);

    if (fd < 0) {
        return ERROR;
    }
    if (read(fd, buffer, 4096) < 0)
        return ERROR;
    printf("%s\n", buffer);
    return SUCCESS;
}

int check_args_srv(int argc, char **argv)
{
    if (argc == 2) {
        if (!argv || !argv[0] || !argv[1])
            return ERROR;
        if (strcmp(argv[1], "-help") == 0)
            return display_usage();
        if (string_is_num(argv[1]) == ERROR)
            return ERROR;
        if (atoi(argv[1]) > 65535 || atoi(argv[1]) < 1024)
            return ERROR;
        return SUCCESS;
    }
    return ERROR;
}
