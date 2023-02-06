/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include "macros_error.h"
#include "protos_map.h"


static char **add_boat_pos(char *line, char **tab, int i)
{
    if (line[2] == line[5]) {
        if (tab[(line[3] - '1') + i][(line[2] - 'A')] == '.') {
            tab[(line[3] - '1') + i][(line[2] - 'A')] = line[0];
        } else {
            return NULL;
        }
    }
    if (line[3] == line[6]) {
        if (tab[line[3] - '1'][(line[2] - 'A') + i] == '.') {
            tab[line[3] - '1'][(line[2] - 'A') + i] = line[0];
        } else {
            return NULL;
        }
    }
    return tab;
}

static char **add_boat_neg(char *line, char **tab, int i)
{
    if (line[2] == line[5]) {
        if (tab[(line[3] - '1') - i][(line[2] - 'A')] == '.') {
            tab[(line[3] - '1') - i][(line[2] - 'A')] = line[0];
        } else {
            return NULL;
        }
    }
    if (line[3] == line[6]) {
        if (tab[line[3] - '1'][(line[2] - 'A') - i] == '.') {
            tab[line[3] - '1'][(line[2] - 'A') - i] = line[0];
        } else {
            return NULL;
        }
    }
    return tab;
}

char **add_boat_in_pos_direction(int finish, char **tab, char *line)
{
    for (int i = 0; i < finish; i += 1) {
        tab = add_boat_pos(line, tab, i);
        if (tab == NULL)
            return NULL;
    }
    return tab;
}

char **add_boat_in_neg_direction(int finish, char **tab, char *line)
{
    for (int i = 0; i < finish; i += 1) {
        tab = add_boat_neg(line, tab, i);
        if (tab == NULL)
            return NULL;
    }
    return tab;
}

char **add_boat_on_map(char *line, char **tab)
{
    int finish = line[0] - 48;
    int direction = check_direction(line);
    if (direction == 1) {
        return add_boat_in_pos_direction(finish, tab, line);
    }
    if (direction == -1) {
        return add_boat_in_neg_direction(finish, tab, line);
    }
    return tab;
}
