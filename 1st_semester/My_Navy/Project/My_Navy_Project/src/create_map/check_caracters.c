/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdio.h>
#include <stdlib.h>
#include "macros_error.h"
#include "protos_map.h"

int check_num(char *line, int i)
{
    if ((line[i] >= '1' && line[i] <= '8')) {
        return SUCCESS_EPITECH;
    }
    return ERROR_EPITECH;
}

int check_alpha(char *line, int i)
{
    if ((line[i] >= 'A' && line[i] <= 'H')) {
        return SUCCESS_EPITECH;
    }
    return ERROR_EPITECH;
}

int check_special_caracters(char *line, int i)
{
    if ((line[i] != ':' && line[i] != '\n' && line[i] != '\0')) {
        return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}

int check_syntaxe(char *line)
{
    if ((check_num(line, 0) == ERROR_EPITECH) ||
    (check_num(line, 3) == ERROR_EPITECH)
    || (check_num(line, 6) == ERROR_EPITECH))
        return ERROR_EPITECH;
    if ((check_alpha(line, 2) == ERROR_EPITECH) ||
    (check_alpha(line, 5) == ERROR_EPITECH))
        return ERROR_EPITECH;
    if ((check_special_caracters(line, 1) == ERROR_EPITECH) ||
    (check_special_caracters(line, 4) == ERROR_EPITECH))
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}
