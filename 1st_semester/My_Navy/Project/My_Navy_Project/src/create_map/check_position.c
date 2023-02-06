/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdio.h>
#include <stdlib.h>
#include "macros_error.h"

int check_nb_boat(char *line, int size)
{
    if ((line[0] - 48) != (size + 1))
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}

int check_direction(char *line)
{
    if (line[2] == line[5]) {
        if ((line[3] - 48) > (line[6] - 48))
            return -1;
        if ((line[3] - 48) < (line[6] - 48))
            return 1;
    }
    if (line[3] == line[6]) {
        if ((line[2] - 64) > (line[5] - 64))
            return -1;
        if ((line[2] - 64) < (line[5] - 64))
            return 1;
    }
}

int check_correct_position_pos(char *line)
{
    if (line[2] == line[5]) {
        if ((((line[3] - 48) + (line[0] - 48) - 1) == (line[6] - 48))) {
            return SUCCESS_EPITECH;
        } else {
            return ERROR_EPITECH;
        }
    }
    if (line[3] == line[6]) {
        if (((line[2] - 64) + (line[0] - 48) - 1) == (line[5] - 64)) {
            return SUCCESS_EPITECH;
        } else {
            return ERROR_EPITECH;
        }
    }
}

int check_correct_position_neg(char *line)
{
    if (line[2] == line[5]) {
        if (((line[3] - 48) - (line[0] - 48) + 1) != (line[6] - 48)) {
            return ERROR_EPITECH;
        }
    }
    if (line[3] == line[6]) {
        if (((line[2] - 64) - (line[0] - 48) + 1) != (line[5] - 64)) {
            return ERROR_EPITECH;
        }
    }
    return SUCCESS_EPITECH;
}

int check_position(char *line)
{
    if ((line[2] != line[5]) && (line[3] != line[6]))
        return ERROR_EPITECH;
    if ((line[2] == line[5]) && (line[3] == line[6]))
        return ERROR_EPITECH;
    int direction = check_direction(line);
    if (direction == 1) {
        if (check_correct_position_pos(line) == ERROR_EPITECH)
            return ERROR_EPITECH;
    }
    if (direction == -1) {
        if (check_correct_position_neg(line) == ERROR_EPITECH)
            return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}
