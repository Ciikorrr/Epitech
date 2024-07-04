/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** parse_freq
*/

#include "server.h"
#include "utils.h"

int parse_freq(int index, char **argv, zappy_t *zappy)
{
    if (!argv || !zappy || !argv[index] || !my_str_isnum(argv[index])) {
        printf("-f: Invalid Freq\n");
        return ERROR;
    }
    zappy->freq = atoi(argv[index]);
    if (zappy->freq <= 0) {
        printf("-f: Invalid Freq.\n");
        return ERROR;
    }
    return 1;
}
