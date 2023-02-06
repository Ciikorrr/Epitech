/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-myls-marius.marolleau
** File description:
** info_l
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

int info_l(int total, int argc, char *path, char *temp)
{
    error_handling(path);
    DIR *dir = opendir(path);
    struct dirent *file = readdir(dir);
    compare(argc, dir, file);
    while (file != NULL) {
        if (file->d_name[0] != '.') {
            my_strcat(temp, file->d_name);
            total += get_info(temp, total);
            my_printf("\t%s\n",file->d_name);
            free(temp);
            temp = my_strdup(path);
        }
        file = readdir(dir);
    }
    return total;
}
