/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD04pm-marius.marolleau
** File description:
** lint_list_bis
*/
#include <stdio.h>
#include "int_list.h"
#include <stdlib.h>

static int_list_t *init_list(int elem)
{
    int_list_t *node = malloc(sizeof(int_list_t));

    if (node == NULL)
        return NULL;
    node->next = NULL;
    node->value = elem;
    return node;
}

bool int_list_add_elem_at_front(int_list_t **front_ptr, int elem)
{
    int_list_t *new = init_list(elem);

    if (new == NULL)
        return false;
    new->next = (*front_ptr);
    (*front_ptr) = new;
    return true;
}

bool int_list_add_elem_at_position
(int_list_t **front_ptr, int elem, unsigned int position)
{
    int_list_t *temp = *front_ptr;
    int_list_t *temp2 = NULL;
    int_list_t *list = NULL;
    int length = int_list_get_size(*front_ptr);

    if (position > length)
        return false;
    if (position == 0)
        return int_list_add_elem_at_front(front_ptr, elem);
    list = init_list(elem);
    while (position > 1) {
        temp = temp->next;
        position -= 1;
    }
    temp2 = temp->next;
    temp->next = list;
    list->next = temp2;
    return true;
}
