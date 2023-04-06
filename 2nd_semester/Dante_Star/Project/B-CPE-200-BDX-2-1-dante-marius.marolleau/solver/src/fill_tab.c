/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "protos.h"
#include "linked_list.h"

void fill_tab(sol_t *solver)
{
    for (int i = 0; i <= solver->height_max; i += 1) {
        for (int j = 0; solver->map[i][j] != '\0'; j += 1) {
            replace_char(solver, i, j);
        }
    }
}
