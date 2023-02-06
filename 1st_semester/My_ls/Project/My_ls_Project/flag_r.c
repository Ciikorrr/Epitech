/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-myls-marius.marolleau
** File description:
** flag_r
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

int compteur_r(char *path)
{
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

static char **malloc_tab(char *path, char **tab)
{
    int nbr_file = compteur_r(path);
    tab = malloc(sizeof(char *) * (nbr_file + 1));
    DIR *dir = opendir(path);
    struct dirent *file;
    file = readdir(dir);
    for (int i = 0; i < nbr_file; i += 1) {
        if (file->d_name[0] != '.') {
            int size = my_strlen(file->d_name);
            tab[i] = malloc(sizeof(char) * size + 1);
        }
        file = readdir(dir);
    }
    return tab;
}

static char **create_file(char **tab, char *path, struct dirent *entry)
{
    tab = malloc_tab(path, tab);
    int count = compteur_r(path);
    DIR *dir = opendir(path);
    entry = readdir(dir);
    int indice = 0;
    for (int i = 0; i < count; i += 1) {
        if (entry->d_name[0] != '.') {
            tab[indice] = entry->d_name;
            indice += 1;
        }
        entry = readdir(dir);
    }
    tab[indice] = NULL;
    return tab;
}

static int display_rev(char **tab, int i)
{
    if (tab[i] == NULL) {
        return 0;
    }
    display_rev(tab, i + 1);
    my_printf("%s\n", tab[i]);
}

int flag_r(struct dirent *entry, char *path, int argc, char **argv)
{
    error_handling(path);
    error_permission(path);
    char **tab = create_file(tab, path, entry);
    int i = 0;
    display_rev(tab, i);

    return 0;
}
