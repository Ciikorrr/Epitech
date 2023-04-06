/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdlib.h>
#include <unistd.h>
#include "linked_list.h"

void free_all(sol_t *solver)
{
    for (int i = 0; i <= solver->height_max; i += 1) {
        free(solver->map[i]);
    }
    free(solver->map);
}
