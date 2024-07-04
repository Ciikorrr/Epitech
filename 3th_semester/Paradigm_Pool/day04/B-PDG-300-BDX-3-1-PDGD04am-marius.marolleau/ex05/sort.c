/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD04am-marius.marolleau
** File description:
** sort
*/
#include <stdio.h>

void sort_int_array(int *array, size_t nmemb)
{
    int memo;
    int i = 0;

    while (i < nmemb) {
        if (array[i] > array[i + 1]) {
            memo = array[i];
            array[i] = array[i + 1];
            array[i + 1] = memo;
            i = 0;
        } else {
            i += 1;
        }
    }
}
