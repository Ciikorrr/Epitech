/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-sokoban-marius.marolleau
** File description:
** file_to_str
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "protos.h"
#include "macros.h"

char *file_to_str(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        exit(ERROR_EPITECH);
    }
    struct stat file;
    stat(filepath, &file);
    char *str = malloc(sizeof(char) * (file.st_size + 1));
    str[file.st_size] = '\0';
    read(fd, str, file.st_size);
    return str;
}

char **str_to_tab(char const *str)
{
    int x = get_line(str);
    char **tab = malloc(sizeof(char *) * (x + 1));
    tab[x] = NULL;
    int index1 = 0;
    for (int i = 0; i < x; i += 1) {
        int taille = nb_char(str, index1);
        index1 += next_index(str, index1);
        tab[i] = malloc(sizeof(char) * (taille + 1));
        tab[i][taille] = '\0';
    }
    int index = 0;
    int count = 0;
    for (int i = 0; i < x; i += 1) {
        count = nb_char(str, index);
        for (int e = 0; e <= count; e += 1) {
            tab[i][e] = str[e + index];
        }
        index += next_index(str, index);
    }
    return tab;
}
