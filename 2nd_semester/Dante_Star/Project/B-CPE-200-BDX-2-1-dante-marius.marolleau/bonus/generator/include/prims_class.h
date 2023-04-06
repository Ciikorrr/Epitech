/*
** EPITECH PROJECT, 2023
** PRIMS_CLASS_
** File description:
** prims_class
*/

#include "../include/cell_class.h"

#ifndef PRIMS_CLASS_
    #define PRIMS_CLASS_

    typedef struct prims {

        maze_t base;

    } prims;

prims *new_prims(int row, int col);

#endif /* PRIMS_CLASS_ */
