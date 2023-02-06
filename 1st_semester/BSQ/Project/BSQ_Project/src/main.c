/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-bsbsq-marius.marolleau
** File description:
** main
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <fcntl.h>
#include <unistd.h>
#include "protos.h"
#include "macros.h"

void error_map(char **map)
{
    int count = my_strlen(map[1]);
    for (int i = 2; map[i] != NULL; i += 1) {
        if (my_strlen(map[i]) != count) {
            exit(ERROR_EPITECH);
        }
    }
}

void error_file(struct stat file, char *filepath)
{
    int res = stat(filepath, &file);
    if (res == -1) {
        exit(ERROR_EPITECH);
    }
    if (file.st_size == 0)
        exit(ERROR_EPITECH);
    switch (file.st_mode & S_IFMT) {
        case S_IFDIR: exit(ERROR_EPITECH);
    }
}

void error_handling(char *str, struct stat file)
{
    int x = 0;
    for (x; str[x] != '\0'; x += 1) {
        if (str[x] == '.' || str[x] == 'o') {
            break;
        }
    }
    for (int i = x; str[i] != '\0'; i += 1) {
        if (str[i] != '\n' && str[i] != '.' && str[i] != 'o') {
            free(str);
            exit(ERROR_EPITECH);
        }
    }
}

int main(int argc, char **argv)
{
    char **map = NULL;
    if (argc == 2) {
        bsq_basic(map, argv);
        return 0;
    }
    if (argc == 3) {
        good_argv(argv);
        bsq_gen(map, argv);
        return SUCCESS_EPITECH;
    } else {
        exit(ERROR_EPITECH);
    }
    return SUCCESS_EPITECH;
}
