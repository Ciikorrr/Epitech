/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-myls-marius.marolleau
** File description:
** flag_a
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

int find_type_a(char *argv, struct dirent *entry, int type)
{
    DIR *dir1;
    dir1 = opendir("./");
    while (entry != NULL) {
        entry = readdir(dir1);
        if (my_strcmp(argv, entry->d_name) == 0) {
            type = get_type(entry, argv, type);
            break;
        }
    }
    closedir(dir1);
    return type;
}

int get_type_a(struct dirent *entry, char *argv, int type)
{
    struct stat entry_type;
    stat(argv, &entry_type);
    switch (entry_type.st_mode & S_IFMT) {
        case S_IFDIR:  type = 0;          break;
        case S_IFREG:  type = 1;          break;
        default:       type = -1;         break;
    }
    return type;
}

void name_a(struct dirent *entry)
{
    my_putstr(entry->d_name);
    my_putchar(' ');
}

void search_a(char *argv, struct dirent *entry, int type, DIR *dir)
{
    type = find_type(argv, entry, type);
    if (type == 1) {
        my_putstr(argv);
        my_putchar('\n');
    }
    if (type == 0) {
        dir = opendir(argv);
        entry = readdir(dir);
        while (entry != NULL) {
            name_a(entry);
            entry = readdir(dir);
        }
        closedir(dir);
        my_putchar('\n');
    }
}

int flag_a(struct dirent *entry, char *path, int argc, char **argv)
{
    DIR *dir;
    int type;
    if (path[0] != '-') {
        search_a(path, entry, type, dir);
    }
    return 0;
}
