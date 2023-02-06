/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** utils_list
*/

#include "mylist.h"

bool is_empty_list(list *li)
{
    if (li == NULL) {
        return true;
    }
    return false;
}

int length_list(list *li)
{
    int len = 0;
    while (li != NULL) {
        len += 1;
        li = li->next;
    }
    return len;
}

void print_list(list *li)
{
    if (li == NULL) {
        return;
    }
    while (li != NULL) {
        my_printf("%d ", li->value);
        li = li->next;
    }
}
