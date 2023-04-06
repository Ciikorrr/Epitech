/*
** EPITECH PROJECT, 2023
** check_even.c
** File description:
** check_even
*/

#include "../include/cell_class.h"

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
