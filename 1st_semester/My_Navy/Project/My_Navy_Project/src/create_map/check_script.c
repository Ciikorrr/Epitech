/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include "macros_error.h"
#include "protos_map.h"

int error_script(char *line, int size)
{
    if (check_syntaxe(line) == ERROR_EPITECH)
        return ERROR_EPITECH;
    if (check_nb_boat(line, size) == ERROR_EPITECH)
        return ERROR_EPITECH;
    if (check_position(line) == ERROR_EPITECH)
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}
