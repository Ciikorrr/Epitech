/*
** EPITECH PROJECT, 2022
** my_param_to_list
** File description:
** param to list
*/

#include <stddef.h>
#include "mylist.h"
#include <stdlib.h>
#include "my.h"

void my_show_list(linked_list_t *list);
int my_list_size(linked_list_t *begin);

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list = NULL;
    for (int i = 0; i < ac; i += 1) {
        linked_list_t *element = malloc(sizeof(linked_list_t));
        if (element == NULL) {
            return NULL;
        }
        element->data = av[i];
        element->next = list;
        list = element;
    }
    return list;
}
