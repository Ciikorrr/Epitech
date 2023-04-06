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
#include "macros_errors.h"
#include "utils.h"

int check_stat(struct stat file)
{
    if (!(file.st_mode & S_IRUSR))
        return ERROR_EPITECH;
    if (file.st_size == 0)
        return ERROR_EPITECH;
    if ((file.st_mode & __S_IFMT) != S_IFREG)
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}

int get_nb_line(char const *filepath)
{
    if (filepath == NULL)
        return -1;
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return -1;
    struct stat file;
    if (stat(filepath, &file) == -1)
        return -1;
    if (check_stat(file))
        return -1;
    char *str = malloc(sizeof(char) * (file.st_size + 1));
    if (str == NULL)
        return -1;
    str[file.st_size] = '\0';
    read(fd, str, file.st_size);
    int nb_line = get_line(str);
    free(str);
    return nb_line;
}

char **file_to_tab(char const *filepath)
{
    int nb_line = get_nb_line(filepath);
    if (nb_line == -1)
        return NULL;
    char **tab = malloc(sizeof(char *) * (nb_line + 1));
    if (tab == NULL)
        return NULL;
    FILE *stream = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    int i = 0;
    while ((nread = getline(&line, &len, stream)) != -1) {
        tab[i] = my_strdup(line);
        if (tab[i] == NULL)
            return NULL;
        i += 1;
    }
    tab[nb_line] = NULL;
    fclose(stream);
    return tab;
}
