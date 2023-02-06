/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-myls-marius.marolleau
** File description:
** no_argument
*/
#include "my.h"
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
#include "protos.h"

void name(struct dirent *entry)
{
    if (entry->d_name[0] != '.') {
        my_putstr(entry->d_name);
        my_putchar('\n');
    }
}

int no_argument(struct dirent *entry, DIR *dir)
{
    dir = opendir(".");
    entry = readdir(dir);
    while (entry != NULL) {
        name(entry);
        entry = readdir(dir);
    }
    closedir(dir);
    return 0;
}

void do_l(struct dirent *file)
{
    int total = 0;
    if (file->d_name[0] != '.') {
        get_info(file->d_name, total);
        my_printf("\t%s\n",file->d_name);
    }
}

int my_strlen_tab(char **tab)
{
    int count = 0;
    for (int i = 0; tab[i] != NULL; i += 1) {
        count += 1;
    }
    return count;
}

int compteur(char *path)
{
    error_handling(path);
    error_permission(path);
    DIR *dir = opendir(path);
    struct dirent *entry;
    int count = 0;
    entry = readdir(dir);
    while (entry != NULL) {
        count += 1;
        entry = readdir(dir);
    }
    closedir(dir);
    return count;
}
