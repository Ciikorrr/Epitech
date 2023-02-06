/*
** EPITECH PROJECT, 2022
** Hub-Workshop
** File description:
** list
*/

#include "mylist.h"

list *new_elem(int value)
{
    list *new_list = malloc(sizeof(list));
    if (new_list == NULL) {
        return NULL;
    }
    new_list->value = value;
    new_list->next = NULL;
    return new_list;
}

list *add_elem_back(list *li, int value)
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

list *add_elem_front(list *li, int value)
{
    list *element = new_elem(value);
    if (element == NULL) {
        return NULL;
    }
    element->next = li;
    return element;
}
