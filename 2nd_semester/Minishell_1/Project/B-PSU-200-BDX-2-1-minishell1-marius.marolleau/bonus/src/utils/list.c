/*
** EPITECH PROJECT, 2022
** Hub-Workshop
** File description:
** list
*/

#include <unistd.h>
#include <stdlib.h>
#include "linked_list.h"
list *new_elem(char *value)
{
    list *new_list = malloc(sizeof(list));
    if (new_list == NULL) {
        return NULL;
    }
    new_list->str = value;
    new_list->next = NULL;
    return new_list;
}

list *add_elem_back(list *li, char *value)
{
    list *element = new_elem(value);
    list *temp = li;
    if (element == NULL) {
        return NULL;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = element;
    return li;
}

list *add_elem_front(list *li, char *value)
{
    list *element = new_elem(value);
    if (element == NULL) {
        return NULL;
    }
    element->next = li;
    return element;
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

int free_list(list *env_list)
{
    while (env_list->next != NULL) {
        pop_elem_back(env_list);
    }
    free_element(env_list);
    return 0;
}
