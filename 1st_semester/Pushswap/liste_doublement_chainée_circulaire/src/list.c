/*
** EPITECH PROJECT, 2022
** Pushswap
** File description:
** list
*/

#include <stdio.h>
#include "list.h"

node *create_element(node *li, int nb)
{
    node *elem = malloc(sizeof(node));
    if (elem == NULL)
        return NULL;
    elem->value = nb;
    elem->prv = NULL;
    elem->next = NULL;
    return elem;
}

void *create_head(head_list *list, int nb)
{
    node *node = malloc(sizeof(node));
    if (node == NULL)
        return NULL;
    node->value = nb;
    node->prv = node;
    node->next = node;
    list->head = node;
}

void add_elem(head_list *list, int nb)
{
    if (list->size == 0) {
        create_head(list, nb);
        list->size += 1;
        return;
    }
    node *elem = malloc(sizeof(node));
    if (elem == NULL)
        return NULL;
    elem->value = nb;
    elem->next = list->head;
    elem->prv = list->head->prv;
    list->head->prv->next = elem;
    list->head->prv = elem;
    elem = list->head;
    list->size += 1;
}

// void pop_element(head_list *list)
// {
//     if (list->size == 1)


// }
