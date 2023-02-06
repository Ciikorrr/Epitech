/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-myls-marius.marolleau
** File description:
** flag's function
*/
#include "protos.h"
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include "struct_flag.h"

void do_flag(struct dirent *entry, DIR *dir, char **argv, int argc)
{
    char flag_finded = find_flag(argv, argc);
    int index_flag = is_flag_ls(flag_finded);
    for (int i = 2; i < argc; i += 1) {
        tab_flag2[index_flag].function(entry, argv[i], argc, argv);
        my_putchar('\n');
    }
}

int is_flag_ls(char format)
{
    int count = 0;
    for (int i = 0; i < TAB_SIZE; i = i + 1) {
        if (format == tab_flag2[i].flag) {
            return (i);
        } else {
            count += 1;
        }
    }
    if (count == 5) {
        exit(84);
    }
}

int have_flag(int argc, char **argv)
{
    int flag = 0;
    for (int i = 0; i < argc - 1; i += 1) {
        if (argv[i][0] == '-') {
            flag = 1;
        }
    }
    return flag;
}

char find_flag(char **argv, int argc)
{
    for (int i = 1; i <= argc; i += 1) {
        if (argv[i][0] == '-') {
            return argv[i][1];
        }
    }
}

void do_flag_no_arg(struct dirent *entry, DIR *dir, char **argv, int argc)
{
    char flag_finded = find_flag(argv, argc);
    int index_flag = is_flag_ls(flag_finded);
    char *path = "./";
    tab_flag2[index_flag].function(entry, path, argc, argv);
    my_putchar('\n');
}
