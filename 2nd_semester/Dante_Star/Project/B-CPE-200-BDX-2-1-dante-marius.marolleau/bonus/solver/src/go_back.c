/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdio.h>
#include <stdlib.h>
#include "protos.h"
#include "macros_bit.h"
#include "macros_errors.h"

void go_back_north(sol_t *solver)
{
    solver->map[solver->pos_y][solver->pos_x] -= PATH;
    solver->pos_y -= 1;
    return;
}

void go_back_south(sol_t *solver)
{
    solver->map[solver->pos_y][solver->pos_x] -= PATH;
    solver->pos_y += 1;
    return;
}

void go_back_west(sol_t *solver)
{
    solver->map[solver->pos_y][solver->pos_x] -= PATH;
    solver->pos_x -= 1;
    return;
}

void go_back_east(sol_t *solver)
{
    solver->map[solver->pos_y][solver->pos_x] -= PATH;
    solver->pos_x += 1;
    return;
}

void go_back(sol_t *solver)
{
    int direction = GET_PREV(solver->map[solver->pos_y][solver->pos_x]);

    if (direction == WEST) {
        go_back_west(solver);
        return;
    }
    if (direction == EAST) {
        go_back_east(solver);
        return;
    }
    if (direction == NORTH) {
        go_back_north(solver);
        return;
    }
    if (direction == SOUTH) {
        go_back_south(solver);
        return;
    }
    return;
}
