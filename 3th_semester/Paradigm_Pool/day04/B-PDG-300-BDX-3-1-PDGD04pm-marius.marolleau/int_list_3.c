/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD04pm-marius.marolleau
** File description:
** int_list_3
*/
#include "int_list.h"
#include <stdio.h>

int int_list_get_elem_at_front(int_list_t *list)
{
    if (!list)
        return 0;
    if (int_list_is_empty(list))
        return 0;
    return list->value;
}

int int_list_get_elem_at_back(int_list_t *list)
{
    int_list_t *temp = NULL;

    if (!list)
        return 0;
    temp = list;
    if (int_list_is_empty(list))
        return 0;
    while (temp->next != NULL)
        temp = temp->next;
    return temp->value;
}

int int_list_get_elem_at_position(int_list_t *list, unsigned int position)
{
    int_list_t *temp = list;
    int len = int_list_get_size(list);

    if ((int)position >= len || int_list_is_empty(temp) || (int)position < 0)
        return 0;
    if (position == 0)
        return int_list_get_elem_at_front(temp);
    while (position != 0) {
        temp = temp->next;
        position--;
    }
    return temp->value;
}
