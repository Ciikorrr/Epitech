/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD04pm-marius.marolleau
** File description:
** list3
*/
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

bool list_del_elem_at_back(list_t **front_ptr)
{
    list_t *temp = NULL;

    if (!front_ptr || !(*front_ptr))
        return false;
    temp = (*front_ptr);
    if (list_is_empty(temp))
        return false;
    if (list_get_size(*front_ptr) == 1) {
        *front_ptr = NULL;
        free(temp);
        return true;
    }
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    return true;
}

bool list_del_elem_at_position(list_t **front_ptr, unsigned int position)
{
    list_t *temp = NULL;
    list_t *temp2 = NULL;

    if (!front_ptr || !(*front_ptr))
        return false;
    temp = *front_ptr;
    if (list_is_empty(temp))
        return false;
    if (position < 0 || (int)position >= list_get_size(temp))
        return false;
    if (position == 0)
        return list_del_elem_at_front(front_ptr);
    while (position > 1) {
        temp = temp->next;
        position--;
    }
    temp2 = temp->next->next;
    free(temp->next);
    temp->next = temp2;
    return true;
}

static list_t *pop_elem_front(list_t *list)
{
    list_t *temp = list->next;

    if (!list)
        return NULL;
    free(list);
    return temp;
}

void list_clear(list_t **front_ptr)
{
    int len = 0;
    int i = 0;

    if (!front_ptr || !(*front_ptr))
        return;
    len = list_get_size((*front_ptr));
    while (i < len) {
        (*front_ptr) = pop_elem_front((*front_ptr));
        if ((*front_ptr) == NULL)
            return;
        i++;
    }
}
