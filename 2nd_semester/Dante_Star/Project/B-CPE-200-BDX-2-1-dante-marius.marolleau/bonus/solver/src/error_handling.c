/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include "utils.h"
#include "macros_errors.h"
#include "protos.h"

int compare(char **map, int i)
{
    if (map == NULL)
        return ERROR_EPITECH;
    for (int j = 0; map[i][j] != '\0'; j += 1) {
        if (map[i][j] != '*' && map[i][j] != 'X' && map[i][j] != '\n') {
            return ERROR_EPITECH;
        }
    }
    return SUCCESS_EPITECH;
}

int check_map(char **map)
{
    if (map == NULL)
        return ERROR_EPITECH;
    for (int i = 0; map[i] != NULL; i += 1) {
        if (compare(map, i) == ERROR_EPITECH)
            return ERROR_EPITECH;
    }
    for (int col = 0; map[col] != NULL; col += 1) {
        if (my_strlen(map[col]) != my_strlen(map[0]))
            return ERROR_EPITECH;
    }
    if (map[0][0] != '*')
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}

int error_handling(int argc, char **argv, char ***map)
{
    if (argv == NULL || argv[0] == NULL || argv[1] == NULL)
        return ERROR_EPITECH;
    if (argc != 2)
        return ERROR_EPITECH;
    (*map) = file_to_tab(argv[1]);
    if ((*map) == NULL)
        return ERROR_EPITECH;
    if (check_map((*map)) == ERROR_EPITECH)
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}
