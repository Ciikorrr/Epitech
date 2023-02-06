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
#include <pwd.h>
#include <grp.h>

static char **malloc_tab(char *path, char **tab)
{
    int nbr_file = compteur(path);
    tab = malloc(sizeof(char *) * (nbr_file + 1));
    error_handling(path);
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
    int count = compteur(path);
    error_handling(path);
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

static int display_t(char **tab, int i)
{
    if (tab[i] == NULL) {
        return 0;
    }
    my_printf("%s\n", tab[i]);
    display_t(tab, i + 1);
}

int compare_time(char *tab1, char *tab2, char  *path)
{
    struct stat file;
    struct stat file2;
    char *new_path1 = my_strcat(path, tab1);
    char *new_path2 = my_strcat(path, tab2);
    stat(new_path1, &file);
    stat(new_path2, &file2);
    if (file.st_mtime < file2.st_mtime && tab2 != NULL) {
        return 1;
    }
    return 0;
}

int flag_t(struct dirent *entry, char *path, int argc, char **argv)
{
    char **tab = create_file(tab, path, entry);
    int i = 0;
    char *temp = NULL;
    int count = my_strlen_tab(tab);
    while (i < count - 1) {
        if (compare_time(tab[i], tab[i + 1], path) == 1) {
            temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;
            i = 0;
        } else {
            i += 1;
        }
    }
    for (int i = 0; tab[i] != NULL; i += 1) {
        my_printf("%s\n", tab[i]);
    }
    return 0;
}
