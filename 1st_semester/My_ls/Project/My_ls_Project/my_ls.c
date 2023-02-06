/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-myls-marius.marolleau
** File description:
** my_ls
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
#include <linux/types.h>

int find_type(char *argv, struct dirent *entry, int type)
{
    DIR *dir1;
    struct stat error;
    error_handling(argv);
    error_permission(argv);
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

int get_type(struct dirent *entry, char *argv, int type)
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

void display_name(struct dirent *entry)
{
    if (entry->d_name[0] != '.') {
        my_putchar(' ');
        my_putstr(entry->d_name);
    }
}

void search(char *argv, struct dirent *entry, int type, DIR *dir)
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
            display_name(entry);
            entry = readdir(dir);
        }
        closedir(dir);
        my_putchar('\n');
    }
}

int main(int argc, char **argv)
{
    DIR *dir;
    struct dirent *entry;
    int type;
    int flag = have_flag(argc, argv);
    if (argc == 1) {
        no_argument(entry, dir);
        return 0;
    }
    if (argc == 2 && argv[1][0] == '-') {
        do_flag_no_arg(entry, dir, argv, argc);
        return 0;
    }
    if (flag == 0) {
        for (int i = 1; i < argc; i += 1) {
            search(argv[i], entry, type, dir);
        }
    } else {
        do_flag(entry, dir, argv, argc);
    }
}
