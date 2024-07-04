/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD04pm-marius.marolleau
** File description:
** stack1
*/
#include "stack.h"
#include <stdio.h>

void *stack_top(stack_t *stack)
{
    return list_get_elem_at_front(stack);
}
