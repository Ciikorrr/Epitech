/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD04pm-marius.marolleau
** File description:
** list2
*/
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

bool list_add_elem_at_position
(list_t **front_ptr, void *elem, unsigned int pos)
{
    list_t *temp = *front_ptr;
    list_t *temp2 = NULL;
    list_t *list = NULL;
    int length = list_get_size(*front_ptr);

    if (pos > length)
        return false;
    if (pos == 0)
        return list_add_elem_at_front(front_ptr, elem);
    list = init_list(elem);
    while (pos > 1) {
        temp = temp->next;
        pos -= 1;
    }
    temp2 = temp->next;
    temp->next = list;
    list->next = temp2;
    return true;
}

void *list_get_elem_at_front(list_t *list)
{
    if (!list)
        return NULL;
    if (list_is_empty(list))
        return 0;
    return list->value;
}

void *list_get_elem_at_back(list_t *list)
{
    list_t *temp = NULL;

    if (!list)
        return NULL;
    temp = list;
    if (list_is_empty(list))
        return NULL;
    while (temp->next != NULL)
        temp = temp->next;
    return temp->value;
}

void *list_get_elem_at_position(list_t *list, unsigned int position)
{
    list_t *temp = list;
    int len = list_get_size(list);

    if ((int)position >= len || list_is_empty(temp) || (int)position < 0)
        return 0;
    if (position == 0)
        return list_get_elem_at_front(temp);
    while (position != 0) {
        temp = temp->next;
        position--;
    }
    return temp->value;
}

bool list_del_elem_at_front(list_t **front_ptr)
{
    list_t *temp = NULL;

    if (!front_ptr || !(*front_ptr))
        return false;
    temp = (*front_ptr);
    if (list_is_empty(*front_ptr))
        return false;
    *front_ptr = temp->next;
    free(temp);
    return true;
}
