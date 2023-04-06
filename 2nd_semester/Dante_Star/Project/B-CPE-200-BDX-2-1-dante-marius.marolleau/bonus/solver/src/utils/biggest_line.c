/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-sokoban-marius.marolleau
** File description:
** biggest_line
*/
#include <stdio.h>

int length_map(char **map)
{
    if (map == NULL)
        return -1;
    int count = 0;
    for (int i = 0; map[i] != NULL; i += 1) {
        count += 1;
    }
    return count;

}

int do_width(char *map)
{
    if (map == NULL)
        return -1;
    int width = 0;
    for (int i = 0; map[i] != '\0'; i += 1) {
        width += 1;
    }
    return width;
}
