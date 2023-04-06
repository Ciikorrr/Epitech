/*
** EPITECH PROJECT, 2023
** CELL
** File description:
** cell_class
*/

#ifndef _CELL_
    #define _CELL_

    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

    typedef struct coords_s {

        int x;
        int y;

    } coords_t;

    typedef struct cell_s {

        coords_t coords;

        bool visited;
        bool is_front;
        char cell_case;

    } cell_t;

    typedef struct border_s {

        cell_t *array;
        int lenght;

    } border_t;

    typedef struct maze_class {

        bool perfect;

        cell_t **maze;
        border_t list;

        int width;
        int height;

        void(*display_maze)(struct maze_class *self);
        void(*add_border)(struct maze_class *self, coords_t border);
        void(*remove_border)(struct maze_class *self, int index);
        bool(*is_in_border_list)(struct maze_class *self, coords_t border);

    } maze_t;

    maze_t *maze_constructor(maze_t *maze, int row, int col);
    void maze_destructor(maze_t *maze);
    void check_even(maze_t *maze, int row, int col);

#endif /* CELL */
