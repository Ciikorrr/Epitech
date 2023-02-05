/*
** EPITECH PROJECT, 2022
** my_show_list
** File description:
** show a list
*/
#include "mylist.h"
#include <stddef.h>
#include "my.h"


void my_show_list(linked_list_t *list)
{
    linked_list_t *tmp = NULL;
    tmp = list;
    while (tmp != NULL) {
        my_putstr(tmp->data);
        my_putchar('\n');
        tmp = tmp->next;
    }
}
