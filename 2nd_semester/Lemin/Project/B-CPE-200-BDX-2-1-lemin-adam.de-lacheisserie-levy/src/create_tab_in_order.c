/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-lemin-adam.de-lacheisserie-levy
** File description:
** create_tab_in_order
*/

#include <stdlib.h>
#include <stdbool.h>
#include "struct_lemin.h"
#include "macros.h"
void set_distance_from_end(lemin_t *anthill);

static int *add_ind_node(int *old, int to_add, int *nb_node)
{
    int *new = NULL;

    *nb_node += 1;
    if ((new = malloc(sizeof(int) * *nb_node)) == NULL)
        return NULL;
    for (int i = 0; i < nb_node - 1; i += 1)
        new[i] = old[i];
    new[*nb_node - 1] = to_add;
    if (old != NULL)
        free(old);
    return new;
}

static int add_all_sons(lemin_t *anthill, node_t node, int *nb_node)
{
    int dist = node.distance_from_end;

    for (int i = 0; i < node.nb_links; i += 1) {
        if (anthill->all_nodes[node.links[i]].in_list == false
        && anthill->all_nodes[node.links[i]].distance_from_end > dist)
            anthill->in_order =
            add_ind_node(anthill->in_order, node.links[i], nb_node);
        if (anthill->in_order == NULL)
            return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}

int create_tab_in_order(lemin_t *anthill)
{
    int i = 0;
    int nb_node = 0;

    set_distance_from_end(anthill);

    if ((anthill->in_order =
    add_ind_node(anthill->in_order, anthill->end, &nb_node)) == ERROR_EPITECH)
        return ERROR_EPITECH;

    while (i != nb_node) {
        if (add_all_sons(anthill, anthill->all_nodes[anthill->in_order[i]],
        &nb_node) == ERROR_EPITECH)
            return ERROR_EPITECH;
        i += 1;
    }
}
