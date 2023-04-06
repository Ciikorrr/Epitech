/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int prims_maze_generator(int row, int col, bool perfect);

int main(int argc, char *argv[])
{
    if (argc != 3 && argc != 4)
        return 84;

    int col = atoi(argv[1]);
    int row = atoi(argv[2]);

    if (argc == 3)
        return prims_maze_generator(row, col, false);

    if (argc == 4 && strcmp(argv[3], "perfect") == 0)
        return prims_maze_generator(row, col, true);
    else
        return 84;
}
