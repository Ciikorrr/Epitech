/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include "struct_lemin.h"
#include "macros.h"
#include "protos.h"

int add_name_node(lemin_t *anthill, char *name)
{
    char **new_tab = NULL;
    if (anthill == NULL || name == NULL)
        return ERROR_EPITECH;
    if (anthill->name_nodes == NULL) {
        anthill->name_nodes = malloc(sizeof(char *) * 2);
        if (anthill->name_nodes == NULL)
            return ERROR_EPITECH;
        anthill->name_nodes[0] = my_strdup(name);
        anthill->name_nodes[1] = NULL;
    } else {
        int len_tab = length_tab(anthill->name_nodes);
        new_tab = malloc(sizeof(char *) * (len_tab + 2));
        if (new_tab == NULL)
            return ERROR_EPITECH;
        new_tab[len_tab + 1] = NULL;
        new_tab = fill_new_tab(anthill->name_nodes, new_tab, name);
        if (new_tab == NULL)
            return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}
