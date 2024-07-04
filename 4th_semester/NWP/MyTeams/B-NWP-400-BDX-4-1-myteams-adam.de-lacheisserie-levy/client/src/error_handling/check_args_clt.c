/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** check_args_clt
*/

#include "protos_clt.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/macros.h"

static
int display_usage(void)
{
    char buffer[4096];
    int fd = open("client/src/error_handling/usage.txt", O_RDONLY);

    if (fd < 0)
        return ERROR;
    if (read(fd, buffer, 4096) < 0)
        return ERROR;
    printf("%s\n", buffer);
    return SUCCESS;
}

int check_range(int byte)
{
    if (byte < 0 || byte > 255)
        return ERROR;
    return SUCCESS;
}

int check_ip(char *ip)
{
    char **tab = NULL;

    if (!ip)
        return ERROR;
    tab = my_str_to_word_array_separator(ip, ".");
    if (!tab)
        return ERROR;
    if (length_tab(tab) != 4)
        return ERROR;
    for (int i = 0; tab[i]; i++) {
        if (string_is_num(tab[i]) == ERROR)
            return ERROR;
        if (check_range(atoi(tab[i])) == ERROR)
            return ERROR;
    }
    if (!free_tab(tab))
        return ERROR;
    return SUCCESS;
}

int check_args_clt(int argc, char **argv)
{
    if (argc == 2) {
        if (!argv || !argv[0] || !argv[1])
            return ERROR;
        if (strcmp(argv[1], "-help") == 0)
            return display_usage();
        return ERROR;
    }
    if (argc == 3) {
        if (string_is_num(argv[2]) == ERROR)
            return ERROR;
        if (atoi(argv[2]) > 65535 || atoi(argv[2]) < 1024)
            return ERROR;
        return check_ip(argv[1]);
    }
    return ERROR;
}
