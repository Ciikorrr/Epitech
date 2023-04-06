/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-sokoban-marius.marolleau
** File description:
** info_tab
*/
#include <stddef.h>

int get_line(char const *file)
{
    if (file == NULL)
        return -1;
    int ligne = 0;
    for (int i = 0; file[i] != '\0'; i += 1) {
        if (file[i] == '\n') {
            ligne += 1;
        }
    }
    return ligne + 1;
}
