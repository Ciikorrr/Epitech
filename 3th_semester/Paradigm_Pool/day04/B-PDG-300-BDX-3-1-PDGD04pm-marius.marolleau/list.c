/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD04pm-marius.marolleau
** File description:
** list
*/
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

list_t *init_list(void *elem)
{
    list_t *node = malloc(sizeof(list_t));

    if (node == NULL)
        return NULL;
    node->next = NULL;
    node->value = elem;
    return node;
}

unsigned int list_get_size(list_t *list)
{
    list_t *temp = list;
    int len = 0;

    if (!list)
        return len;
    while (temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

bool list_is_empty(list_t *list)
{
    if (list == NULL)
        return true;
    return false;
}

bool list_add_elem_at_front(list_t **front_ptr, void *elem)
{
    list_t *new = init_list(elem);

    if (new == NULL)
        return false;
    new->next = (*front_ptr);
    (*front_ptr) = new;
    return true;
}

bool list_add_elem_at_back(list_t **front_ptr, void *elem)
{
    list_t *temp = *front_ptr;

    if (temp == NULL) {
        temp = init_list(elem);
        *front_ptr = temp;
        return true;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = init_list(elem);
    temp = (*front_ptr);
    return true;
}
