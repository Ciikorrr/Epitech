/*
** EPITECH PROJECT, 2022
** Projet
** File description:
** get_info
*/
#include "protos.h"


char *file_to_str(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        return NULL;
    }
    struct stat file;
    stat(filepath, &file);
    char *str = malloc(sizeof(char) * (file.st_size));
    str[file.st_size] = '\0';
    read(fd, str, file.st_size);
    return str;
}

int nb_plane(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == 'A') {
            count += 1;
        }
    }
    return count;
}

int nb_tower(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == 'T') {
            count += 1;
        }
    }
    return count;
}

game_t *get_info(int argc, char **argv, game_t *game)
{
    char *str = file_to_str(argv[1]);
    game->nb_plane = nb_plane(str);
    int tower = nb_tower(str);
    char **tab = my_str_to_word_array(str);
    game->tab_plane = malloc(sizeof(plane_t) * (game->nb_plane));
    game->tab_tower = malloc(sizeof(tower_t) * (tower));
    game = fill_tab(tab, game);
    return game;
}
