/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-myls-marius.marolleau
** File description:
** flag_d
*/
#include "protos.h"
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <unistd.h>
#include <stdio.h>

int flag_d(struct dirent *entry, char *path, int argc, char **argv)
{
    struct stat error;
    error_handling(path);
    error_permission(path);
    int res = stat(path, &error);
    if (res == -1) {
        exit(84);
    }
    (void)entry;
    (void)argc;
    (void)argv;
    my_putstr(path);
    return 0;
}
