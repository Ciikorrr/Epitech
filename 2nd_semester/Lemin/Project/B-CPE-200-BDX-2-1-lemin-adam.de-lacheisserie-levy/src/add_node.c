/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-lemin-adam.de-lacheisserie-levy
** File description:
** add_node
*/

#include <stdlib.h>
#include "struct_lemin.h"

int add_node(node_t *old, node_t to_add, int *nb_node)
{
    node_t *new = NULL;

    *nb_node += 1;

    if ((new = malloc(sizeof(node_t) * *nb_node)) == NULL)
        return NULL;

    for (int i = 0; i < nb_node - 1; i += 1)
        new[i] = old[i];

    new[*nb_node - 1] = to_add;

    if (old != NULL)
        free(old);
    return new;
}
