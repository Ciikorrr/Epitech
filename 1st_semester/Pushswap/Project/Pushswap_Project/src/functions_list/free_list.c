/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** free_list
*/

#include "mylist.h"

void free_element(list *li)
{
    li->next = NULL;
    free(li);
}

list *pop_elem_back(list *li)
{
    list *index = li;
    if (li == NULL) {
        return NULL;
    }
    while (index->next->next != NULL) {
        index = index->next;
    }
    free(index->next);
    index->next = NULL;
    return li;
}

list *pop_elem_front(list *li)
{
    list *new = li->next;
    free_element(li);
    return (new);
}

void clear_list(list *li)
{
    while (li != NULL) {
        li = pop_elem_front(li);
    }
}
