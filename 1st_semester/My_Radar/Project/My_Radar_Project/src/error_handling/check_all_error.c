/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include "protos.h"
#include <unistd.h>

int error_handling(const char *const *env)
{
    int count = 0;
    for (int i = 0; env[i] != NULL; i += 1) {
        if (my_strncmp("DISPLAY=", env[i], 8) == 0) {
            count += 1;
        }
    }
    return count;
}

int description(int argc, char **argv)
{
    char *str = "My radar : Air traffic simulation panel\n\
    The program needs a file where you give the informations \
about plane and tower :\nExemple :\n\
    For plane : A x_departure y_departure x_end y_end speed delay\n\
    For tower : T x_position y_position radius \
(tower control area in pourcentage)\n\nUSAGE :\n\
    ./my_radar [OPTIONS] path_to_script\n\
    path_to_script    The path to the script file.\n\nOPTION :\n\
    -h              print the usage and quit\n\nUSER INTERACTIONS\n\
    'S'     enable/desable hitboxes and areas.\n\
    'L'     enable/desable sprites.\n\
    'echap', 'q' and the cross close the program\n";
    int len = my_strlen(str);
    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            write(1, str, len);
            return SUCCESS_EPITECH;
        }
    }
    return ERROR_EPITECH;
}

int check_assets(game_t *game)
{
    game->assets_map = sfTexture_createFromFile("assets/map.jpg", NULL);
    if (game->assets_map == NULL)
        return ERROR_EPITECH;
    game->assets_plane = sfTexture_createFromFile("assets/plane.png", NULL);
    if (game->assets_plane == NULL)
        return ERROR_EPITECH;
    game->assets_tower = sfTexture_createFromFile("assets/tower.png", NULL);
    if (game->assets_tower == NULL)
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}

int check_arg(int argc, char **argv, const char *const *env)
{
    if (argc != 2)
        return ERROR_EPITECH;
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return ERROR_EPITECH;
    if (error_handling(env) == 0)
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}

int check_script(char **argv)
{
    int res = 0;
    int nb = 0;
    char *str = file_to_str(argv[1]);
    char **tab = my_str_to_word_array(str);
    for (int i = 0; tab[i] != NULL; i += 1) {
        if (check_char_plane(tab, i, res) == ERROR_EPITECH)
            return ERROR_EPITECH;
        if (check_char_tower(tab, i, nb) == ERROR_EPITECH)
            return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}
