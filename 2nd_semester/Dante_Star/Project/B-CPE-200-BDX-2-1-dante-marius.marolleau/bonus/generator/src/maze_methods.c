/*
** EPITECH PROJECT, 2023
** maze methods
** File description:
** oui
*/

#include "../include/cell_class.h"
#include "../include/prims_class.h"

prims *new_prims(int row, int col)
{
    prims *maze = malloc(sizeof(prims));
    maze_constructor((maze_t*)maze, row, col);

    return maze;
}

void loop(maze_t *self, int i)
{
    for (int j = 0; j < self->height; j++) {
        printf("%c", self->maze[i][j].cell_case);
        if ((j + 1) % self->height == 0 && (i + 1) != self->width)
            printf("\n");
        if ((i) == self->width)
            write(1, "\0", 1);
    }
}

void display_maze(maze_t *self)
{
    for (int i = 0; i < self->width; i++) {
        loop(self, i);
    }
}
