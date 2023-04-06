/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** free_list
*/
#include <stdlib.h>
#include <unistd.h>
#include "protos.h"
#include "linked_list.h"
#include "utils.h"

void free_element(list *li)
{
    li->next = NULL;
    free(li);
}

list *pop_elem_back(list *li)
{
    list *index = li;
    if (li == NULL) {
        return NULL;
    }
    while (index->next->next != NULL) {
        index = index->next;
    }
    free(index->next);
    index->next = NULL;
    return li;
}

list *pop_elem_front(list *li)
{
    list *new = li->next;
    free_element(li);
    return (new);
}

void clear_list(list *li)
{
    while (li != NULL) {
        li = pop_elem_front(li);
    }
}

void print_list(list *li, msh_t *minish)
{
    if (li == NULL) {
        return;
    }
    while (li != NULL) {
        my_putstr_choose(li->str, minish->pipe_fd[1]);
        my_putstr_choose("\n", minish->pipe_fd[1]);
        li = li->next;
    }
}
