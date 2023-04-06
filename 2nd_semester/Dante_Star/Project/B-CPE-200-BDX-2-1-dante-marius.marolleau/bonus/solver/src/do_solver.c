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
    init_solver(&solver, map);
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
    print_char_by_char(solver.map);
    free_all(&solver);
    return SUCCESS_EPITECH;
}
