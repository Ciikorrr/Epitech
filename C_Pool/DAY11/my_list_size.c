/*
** EPITECH PROJECT, 2022
** my_list_size
** File description:
** size of a list
*/
#include <stddef.h>
#include "mylist.h"
#include "my.h"

int my_list_size(linked_list_t *begin)
{
    int size = 0;

    while (begin != NULL) {
        size += 1;
        begin = begin->next;
    }
    return size;
}
