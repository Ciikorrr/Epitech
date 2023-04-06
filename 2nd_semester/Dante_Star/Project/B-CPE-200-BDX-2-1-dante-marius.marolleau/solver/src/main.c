/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdio.h>
#include "protos.h"
#include "macros_errors.h"

int main(int argc, char **argv)
{
    char **map = NULL;
    if (error_handling(argc, argv, &map) == ERROR_EPITECH) {
        return ERROR_EPITECH;
    }
    return do_solver(map);
}
