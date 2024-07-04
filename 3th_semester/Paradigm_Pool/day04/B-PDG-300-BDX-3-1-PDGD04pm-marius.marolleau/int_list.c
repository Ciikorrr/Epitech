/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD04pm-marius.marolleau
** File description:
** int_list
*/
#include "int_list.h"
#include <stdlib.h>
#include <stdio.h>

static int_list_t *init_list(int elem)
{
    int_list_t *node = malloc(sizeof(int_list_t));

    if (node == NULL)
        return NULL;
    node->next = NULL;
    node->value = elem;
    return node;
}

bool int_list_add_elem_at_back(int_list_t **front_ptr, int elem)
{
    int_list_t *temp = *front_ptr;

    if (temp == NULL) {
        temp = init_list(elem);
        *front_ptr = temp;
        return true;
    }
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = init_list(elem);
    temp = (*front_ptr);
    return true;
}

void int_list_dump(int_list_t *list)
{
    while (list != NULL) {
        printf("%d\n", list->value);
        list = list->next;
    }
}

unsigned int int_list_get_size(int_list_t *list)
{
    int len = 0;

    if (!list)
        return len;
    while (list != NULL) {
        len++;
        list = list->next;
    }
    return len;
}

bool int_list_is_empty(int_list_t *list)
{
    if (list == NULL)
        return true;
    return false;
}

static int_list_t *pop_elem_front(int_list_t *list)
{
    int_list_t *temp = list->next;

    free(list);
    return temp;
}

void int_list_clear(int_list_t **front_ptr)
{
    int len = 0;
    int i = 0;

    if (!front_ptr || !(*front_ptr))
        return;
    len = int_list_get_size((*front_ptr));
    while (i < len) {
        (*front_ptr) = pop_elem_front((*front_ptr));
        i++;
    }
}
