/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD04pm-marius.marolleau
** File description:
** int_list_4
*/
#include <stdio.h>
#include "int_list.h"
#include <stdlib.h>

bool int_list_del_elem_at_front(int_list_t **front_ptr)
{
    int_list_t *temp = (*front_ptr);

    if (!front_ptr || !(*front_ptr))
        return false;
    if (int_list_is_empty(*front_ptr))
        return false;
    *front_ptr = temp->next;
    free(temp);
    return true;
}

bool int_list_del_elem_at_back(int_list_t **front_ptr)
{
    int_list_t *temp = NULL;

    if (!front_ptr || !(*front_ptr))
        return false;
    temp = (*front_ptr);
    if (int_list_is_empty(temp))
        return false;
    if (int_list_get_size(*front_ptr) == 1) {
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

bool int_list_del_elem_at_position
(int_list_t **front_ptr, unsigned int position)
{
    int_list_t *temp = NULL;
    int_list_t *temp2 = NULL;

    if (!front_ptr || !(*front_ptr))
        return false;
    temp = *front_ptr;
    if (int_list_is_empty(temp))
        return false;
    if ((int)position >= int_list_get_size(temp))
        return false;
    if (position == 0)
        return int_list_del_elem_at_front(front_ptr);
    while (position > 1) {
        temp = temp->next;
        position--;
    }
    temp2 = temp->next->next;
    free(temp->next);
    temp->next = temp2;
    return true;
}
