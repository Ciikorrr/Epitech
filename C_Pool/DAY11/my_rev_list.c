/*
** EPITECH PROJECT, 2022
** my_rev_list
** File description:
** reverse a list
*/

#include <stddef.h>
#include "mylist.h"
#include "my.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *element = *begin;
    linked_list_t *previous = NULL;
    linked_list_t *next = NULL;
    while (begin != NULL) {
        next = element->next;
        begin->next = previous;
        previous = element;
        element = next;
    }
    *begin = prev;
}
