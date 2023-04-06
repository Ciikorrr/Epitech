/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "protos.h"
#include "macros_errors.h"
#include "linked_list.h"
#include "utils.h"
#include "macros_bit.h"

int do_solver(char **map)

{
    sol_t solver = {NULL, 0, 0, 0, 0};
    if (init_solver(&solver, map) == ERROR_EPITECH)
        return ERROR_EPITECH;
    int finish = 0;
    while (finish == 0) {
        if (get_next(&solver) == ERROR_EPITECH) {
            free_all(&solver);
            return SUCCESS_EPITECH;
        }
        if (solver.pos_x == solver.width_max &&
        solver.pos_y == solver.height_max)
            finish = 1;
    }
    decrypte_map(&solver);
    if (print_tab(solver.map) == ERROR_EPITECH)
        return ERROR_EPITECH;
    free_all(&solver);
    return SUCCESS_EPITECH;
}
