/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-lemin-adam.de-lacheisserie-levy
** File description:
** get_distance_from_end
*/

#include <stdbool.h>
#include "struct_lemin.h"
#include "macros.h"

static bool is_ended(lemin_t *lemin)
{
    for (int i = 0; i < lemin->nb_node; i += 1) {
        if (lemin->all_nodes[i].distance_from_end == -1)
            return false;
    }
    return true;
}

static void set_all_sons(lemin_t *anthill, int distance, node_t from)
{
    for (int i = 0; i < from.nb_links; i += 1) {
        if (anthill->all_nodes[from.links[i]].distance_from_end == -1)
            anthill->all_nodes[from.links[i]].distance_from_end = distance;
    }
}

static void set_next_distance(lemin_t *anthill, int distance)
{
    for (int i = 0; i < anthill->nb_node; i += 1) {
        if (anthill->all_nodes[i].distance_from_end == distance)
            set_all_sons(anthill, distance, anthill->all_nodes[i]);
    }
}

void set_distance_from_end(lemin_t *anthill)
{
    int start = anthill->start;
    int end = anthill->end;
    int dist = 0;

    anthill->all_nodes[end].distance_from_end = 0;
    while (is_ended(anthill) == false) {
        calc_next_distance(anthill, dist);
        dist += 1;
    }
}
