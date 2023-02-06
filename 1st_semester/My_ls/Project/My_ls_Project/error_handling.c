/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-myls-marius.marolleau
** File description:
** error_handling
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
#include <pwd.h>
#include <grp.h>

void error_handling(char *path)
{
    struct stat error;
    int res = stat(path, &error);
    if (res == -1) {
        exit(84);
    }
}

void error_permission(char *path)
{
    struct stat error;
    stat(path, &error);
    if (!(error.st_mode & S_IRUSR)) {
        exit(84);
    }
}
