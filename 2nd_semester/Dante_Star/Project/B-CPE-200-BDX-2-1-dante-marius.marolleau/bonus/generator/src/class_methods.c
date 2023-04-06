/*
** EPITECH PROJECT, 2023
** method
** File description:
** class_methods
*/

#include <stdio.h>
#include "../include/cell_class.h"
#include "../include/protos.h"

bool is_in_border_list(maze_t *self, coords_t border)
{
    for (int i = 0; i < self->list.lenght; i++)
        if (self->list.array[i].coords.x == border.x &&
        self->list.array[i].coords.y == border.y)
            return true;
    return false;
}

void remove_border(maze_t *self, int index, sfRenderWindow *window)
{
    self->list.array[index] = self->list.array[self->list.lenght - 1];
    self->list.lenght -= 1;

    if (self->show_front == 1)
    {
        for (int k = 0; k < self->list.lenght; k++)
        {
            sfRectangleShape_setPosition(self->front, (sfVector2f){self->list.array[k].coords.x * (1920.f / self->width), self->list.array[k].coords.y * (1080.f / self->height)});
            sfRenderWindow_drawRectangleShape(window, self->front, NULL);
        }
    }
}

void add_imperfect_border(maze_t *self, coords_t border)
{
    if (border.x >= 0 && border.x < self->width && border.y >= 0 &&
    border.y < self->height) {
        if (self->maze[border.x][border.y].visited == false) {
            self->list.array[self->list.lenght] =
            self->maze[border.x][border.y];
            self->list.lenght += 1;
        }
    }
}

void add_border(maze_t *self, coords_t border)
{
    if (self->perfect == false)
        return add_imperfect_border(self, border);
    if (border.x >= 0 && border.x < self->width && border.y >= 0 &&
    border.y < self->height) {
        if (self->maze[border.x][border.y].visited == false && self->maze[border.x][border.y].is_front == false) {
            self->maze[border.x][border.y].is_front = true;
            self->list.array[self->list.lenght] =
            self->maze[border.x][border.y];
            self->list.lenght += 1;
        }
    }
}

void check_even(maze_t *maze, int row, int col)
{
    if (row % 2 == 0 && col % 2 == 0) {
        maze->maze[row - 1][col - 1].cell_case = '*';
        maze->maze[row - 1][col - 2].cell_case = '*';
        return;
    }
    if (row % 2 == 0) {
        maze->maze[row - 1][col - 1].cell_case = '*';
    }
    if (col % 2 == 0) {
        maze->maze[row - 1][col - 1].cell_case = '*';
    }
}

maze_t *maze_constructor(maze_t *maze, int row, int col)
{
    maze->width = row;
    maze->height = col;
    maze->maze = malloc(sizeof(cell_t *) * (row + 1));
    maze->maze[row] = NULL;
    loop_maze_constructor(row, col, maze);
    maze->list.array = malloc(sizeof(cell_t) * (row * col));
    maze->list.lenght = 0;
    maze->display_maze = &display_maze;
    maze->add_border = &add_border;
    maze->remove_border = &remove_border;
    maze->is_in_border_list = &is_in_border_list;
    return maze;
}
