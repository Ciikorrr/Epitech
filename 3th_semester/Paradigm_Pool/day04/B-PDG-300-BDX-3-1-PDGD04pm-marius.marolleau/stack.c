/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD04pm-marius.marolleau
** File description:
** stack
*/
#include "stack.h"
#include <stdio.h>

unsigned int stack_get_size(stack_t *stack)
{
    return list_get_size(stack);
}

bool stack_is_empty(stack_t *stack)
{
    return list_is_empty(stack);
}

bool stack_push(stack_t **stack_ptr, void *elem)
{
    return list_add_elem_at_front(stack_ptr, elem);
}

bool stack_pop(stack_t **stack_ptr)
{
    return list_del_elem_at_front(stack_ptr);
}

void stack_clear(stack_t **stack_ptr)
{
    return list_clear(stack_ptr);
}
