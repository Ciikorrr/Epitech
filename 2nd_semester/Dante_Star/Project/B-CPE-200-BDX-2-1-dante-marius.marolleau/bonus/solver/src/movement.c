/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "macros_errors.h"
#include "linked_list.h"
#include "protos.h"
#include "macros_bit.h"

int go_right(sol_t *solver)
{
    if (solver->pos_x + 1 <= solver->width_max &&
    CAN_BE_NEXT(solver->map[solver->pos_y][solver->pos_x + 1]) == LIBRE) {
        solver->pos_x += 1;
        solver->map[solver->pos_y][solver->pos_x] += WEST << 2;
        solver->map[solver->pos_y][solver->pos_x] += EXPLORED;
        solver->map[solver->pos_y][solver->pos_x] += PATH;
        return SUCCESS_EPITECH;
    }
    return ERROR_EPITECH;
}

int go_down(sol_t *solver)
{
    if (solver->pos_y + 1 <= solver->height_max &&
    CAN_BE_NEXT(solver->map[solver->pos_y + 1][solver->pos_x]) == LIBRE) {
        solver->pos_y += 1;
        solver->map[solver->pos_y][solver->pos_x] += NORTH << 2;
        solver->map[solver->pos_y][solver->pos_x] += EXPLORED;
        solver->map[solver->pos_y][solver->pos_x] += PATH;
        return SUCCESS_EPITECH;
    }
    return ERROR_EPITECH;
}

int go_up(sol_t *solver)
{
    if (solver->pos_y - 1 >= 0 &&
    CAN_BE_NEXT(solver->map[solver->pos_y - 1][solver->pos_x]) == LIBRE) {
        solver->pos_y -= 1;
        solver->map[solver->pos_y][solver->pos_x] += SOUTH << 2;
        solver->map[solver->pos_y][solver->pos_x] += EXPLORED;
        solver->map[solver->pos_y][solver->pos_x] += PATH;
        return SUCCESS_EPITECH;
    }
    return ERROR_EPITECH;
}

int go_left(sol_t *solver)
{
    if (solver->pos_x - 1 >= 0 &&
    CAN_BE_NEXT(solver->map[solver->pos_y][solver->pos_x - 1]) == LIBRE) {
        solver->pos_x -= 1;
        solver->map[solver->pos_y][solver->pos_x] += EAST << 2;
        solver->map[solver->pos_y][solver->pos_x] += EXPLORED;
        solver->map[solver->pos_y][solver->pos_x] += PATH;
        return SUCCESS_EPITECH;
    }
    return ERROR_EPITECH;
}

int get_next(sol_t *solver)
{
    int res = 0;
    if ((res = go_right(solver)) == SUCCESS_EPITECH) {
        return SUCCESS_EPITECH;
    }
    if ((res = go_down(solver)) == SUCCESS_EPITECH) {
        return SUCCESS_EPITECH;
    }
    if ((res = go_left(solver)) == SUCCESS_EPITECH) {
        return SUCCESS_EPITECH;
    }
    if ((res = go_up(solver)) == SUCCESS_EPITECH) {
        return SUCCESS_EPITECH;
    } else {
        return go_other_movement(solver, res);
    }
    return ERROR_EPITECH;
}
