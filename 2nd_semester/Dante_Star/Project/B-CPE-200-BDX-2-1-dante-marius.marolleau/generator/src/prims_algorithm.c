/*
** EPITECH PROJECT, 2023
** prims algo
** File description:
** prims_algorithm
*/
#include <time.h>
#include "../include/protos.h"
#include "../include/prims_class.h"

static void set_all_borders(prims *maze, int x, int y)
{
    maze->base.add_border(&maze->base, (coords_t){x, y + 2});
    maze->base.add_border(&maze->base, (coords_t){x, y - 2});
    maze->base.add_border(&maze->base, (coords_t){x + 2, y});
    maze->base.add_border(&maze->base, (coords_t){x - 2, y});
}

static void set_maze_base(prims *maze, int idx)
{
    maze->base.maze[maze->base.list.array[idx].coords.x]
    [maze->base.list.array[idx].coords.y].visited = true;
    maze->base.maze[maze->base.list.array[idx].coords.x]
    [maze->base.list.array[idx].coords.y].cell_case = '*';
}

static void set_maze_base_border(prims *maze,int idx)
{
    maze->base.add_border(&maze->base,
    (coords_t){maze->base.list.array[idx].coords.x,
    maze->base.list.array[idx].coords.y + 2});
    maze->base.add_border(&maze->base,
    (coords_t){maze->base.list.array[idx].coords.x,
    maze->base.list.array[idx].coords.y - 2});
    maze->base.add_border(&maze->base,
    (coords_t){maze->base.list.array[idx].coords.x + 2,
    maze->base.list.array[idx].coords.y});
    maze->base.add_border(&maze->base,
    (coords_t){maze->base.list.array[idx].coords.x - 2,
    maze->base.list.array[idx].coords.y});
}

static void loop(prims *maze, int idx)
{
    while (maze->base.list.lenght > 0) {
        idx = rand() % maze->base.list.lenght;
        set_maze_base(maze, idx);
        random_neighbours(maze, idx);
        set_maze_base_border(maze, idx);
        maze->base.remove_border(&maze->base, idx);
    }
}

int prims_maze_generator(int row, int col, bool perfect)
{
    srand(time(NULL));
    prims *maze = new_prims(row, col);
    if (perfect == true)
        maze->base.perfect = true;
    else
        maze->base.perfect = false;
    int x = 0;
    int y = 0;
    maze->base.maze[x][y].cell_case = '*';
    maze->base.maze[x][y].visited = true;
    set_all_borders(maze, x, y);
    int idx = 0;
    loop(maze, idx);
    check_even(&maze->base, row, col);
    maze->base.display_maze(&maze->base);
    return 0;
}
