/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include "cell_class.h"
#include "prims_class.h"

#ifndef PROTOS_H_
    #define PROTOS_H_

void add_neighbours(prims *maze, border_t *list, coords_t cell, coords_t bord);
void neighbours_lenght_positive(prims *maze, border_t *neighbours, sfRenderWindow *window);
void random_neighbours(prims *maze, int idx, sfRenderWindow *window);
void loop_maze_constructor(int row, int col, maze_t *maze);
void display_maze(maze_t *self);
#endif /* !PROTOS_H_ */
