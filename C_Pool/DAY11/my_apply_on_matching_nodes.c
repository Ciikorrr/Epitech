/*
** EPITECH PROJECT, 2022
** my_apply_on_matching_nodes
** File description:
** osef
*/

#include <stddef.h>
#include "mylist.h"
#include "my.h"

int my_apply_on_matching_nodes(linked_list_t *begin,
                               int (*f)(), void const *data_ref, int (*cmp)())
{
    linked_list_t *list = begin;
    while (list != NULL) {
        if ((*cmp)(list->data, data_ref) == 0) {
            list->data = (*f)(list->data);
        }
        list = list->next;
    }
    return 0;
}
