/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD04pm-marius.marolleau
** File description:
** array_id_2d
*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    int index = 0;

    *res = malloc(sizeof(int **) * (height + 1));
    *res[height] = NULL;
    for (int i = 0; i < height; i++) {
        (*res)[i] = malloc(sizeof(int) * (width + 1));
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            (*res)[i][j] = array[index];
            index += 1;
        }
    }
}

void array_2d_free(int **array, size_t height, size_t width)
{
    if (!array || !(*array))
        return;
    for (int i = 0; i < height; i++) {
        free(array[i]);
    }
    free(array);
}
