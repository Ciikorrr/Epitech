/*
** EPITECH PROJECT, 2022
** Hub-Workshop
** File description:
** list_command
**/

#include <unistd.h>
#include <stdlib.h>
#include "struct_lemin.h"

list_t *new_elem(char **tab, int value)
{
    list_t *new_element = malloc(sizeof(list_t*));
    if (new_element == NULL)
        return (NULL);
    new_element->origin = value;
    new_element->tab = tab;
    new_element->next = NULL;
    return new_element;
}

list_t *add_elem_back(list_t *li, char **tab, int value)
{
    list_t *new_element = new_elem(tab, value);
    list_t *index = li;
    if (new_element == NULL)
        return NULL;
    if (li == NULL)
        return NULL;
    while (index->next != NULL) {
        index = index->next;
    }
    index->next = new_element;
    return li;
}

int length_list_command(list_t *li)
{
    int compteur = 0;
    while (li != NULL) {
        compteur += 1;
        li = li->next;
    }
    return compteur;
}
