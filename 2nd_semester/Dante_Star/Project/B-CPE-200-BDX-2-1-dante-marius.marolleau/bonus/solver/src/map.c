/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include "protos.h"
#include "linked_list.h"
#include "macros_errors.h"
#include "macros_bit.h"

static void decrypte_char(sol_t *solver, int i, int j)
{
    if (IS_PATH(solver->map[i][j]) == PATH) {
        solver->map[i][j] = 'o';
        return;
    }
    if (IS_WALL(solver->map[i][j]) == WALL) {
        solver->map[i][j] = 'X';
        return;
    } else {
        solver->map[i][j] = '*';
        return;
    }
    return;
}

void decrypte_map(sol_t *solver)
{
    int i = 0;
    for (i = 0; solver->map[i] != NULL; i += 1) {
        for (int j = 0; j < solver->width_max + 1; j += 1) {
            decrypte_char(solver, i, j);
        }
    }
}

void replace_char(sol_t *solver, int i, int j)
{
    if (solver->map[i][j] == 'X') {
        solver->map[i][j] = WALL;
        return;
    }
    if (solver->map[i][j] == '*') {
        solver->map[i][j] = LIBRE;
    }
    return;
}

int go_other_movement(sol_t *solver, int res)
{
    if (solver->pos_x == 0 && solver->pos_y == 0) {
        write(2, "no solution found\n", 18);
        return ERROR_EPITECH;
    }
    if (res == ERROR_EPITECH) {
        go_back(solver);
        return SUCCESS_EPITECH;
    }
    return ERROR_EPITECH;
}
