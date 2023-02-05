/*
** EPITECH PROJECT, 2022
** my_apply_to_node
** File description:
** apply a fonction to a node
*/

#include <stddef.h>
#include "mylist.h"
#include "my.h"

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    linked_list_t *list = begin;
    while (list != NULL) {
        list->data = (*f)(list->data);
        list = list->next;
    }
    return 0;
}
