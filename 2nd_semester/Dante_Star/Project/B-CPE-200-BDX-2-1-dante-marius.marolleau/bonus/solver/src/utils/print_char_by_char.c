/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdio.h>
#include "macros_errors.h"

int print_char_by_char(char **map)
{
    if (map == NULL)
        return ERROR_EPITECH;
    int i = 0;
    for (; map[i + 1] != NULL; i += 1) {
        for (int j = 0; map[i][j] != '\0'; j += 1) {
            if (map[i][j] == '*') {
                printf("\033[47;37m \33[00m");
            }
            if (map[i][j] == 'X') {
                printf("\033[40;30m \33[00m");
            }
            if (map[i][j] == 'o') {
                printf("\033[42;42m \33[00m");
            }
        }
        printf("\n");
    }
    for (int j = 0; map[i][j] != '\0'; j += 1) {
        if (map[i][j] == '*') {
            printf("\033[47;37m \33[00m\33[00m");
        }
        if (map[i][j] == 'X') {
            printf("\033[40;40m \33[00m\33[00m");
        }
        if (map[i][j] == 'o') {
            printf("\033[42;42m \33[00m\33[00m");
        }
    }
    return SUCCESS_EPITECH;
}
