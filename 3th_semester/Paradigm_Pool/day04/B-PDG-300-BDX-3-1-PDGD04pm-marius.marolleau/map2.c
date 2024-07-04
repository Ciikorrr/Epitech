/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD04pm-marius.marolleau
** File description:
** map2
*/
#include "map.h"
#include <stdio.h>
#include <stdlib.h>

bool map_del_elem_at_front(list_t **front_ptr)
{
    list_t *temp = (*front_ptr)->next;

    if (list_is_empty(*front_ptr))
        return false;
    if (list_get_size(*front_ptr) == 1) {
        temp = NULL;
        free(temp);
        return true;
    }
    free(((pair_t *)(*front_ptr)->value));
    free(*front_ptr);
    *front_ptr = temp;
    return true;
}

void map_clear(map_t **map_ptr)
{
    while (*map_ptr != NULL) {
        if ((*map_ptr)->value != NULL)
            free((*map_ptr)->value);
        list_del_elem_at_front(map_ptr);
    }
}
