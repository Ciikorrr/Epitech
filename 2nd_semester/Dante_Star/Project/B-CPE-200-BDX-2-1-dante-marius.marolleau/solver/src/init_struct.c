/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdio.h>
#include "linked_list.h"
#include "macros_bit.h"
#include "utils.h"
#include "macros_errors.h"
#include "protos.h"

int init_solver(sol_t *solver, char **map)
{
    solver->map = map;
    solver->height_max = (length_map(map) - 1);
    solver->width_max = (do_width(map[0]) - 1);
    if (solver->map[solver->height_max][solver->width_max] != '*') {
        if (printf("no solution found1") < 0)
            return ERROR_EPITECH;
        return ERROR_EPITECH;
    }
    solver->pos_x = 0;
    solver->pos_y = 0;
    fill_tab(solver);
    solver->map[0][0] = LIBRE;
    solver->map[0][0] += PATH;
    solver->map[0][0] += EXPLORED;
    return 0;
}
