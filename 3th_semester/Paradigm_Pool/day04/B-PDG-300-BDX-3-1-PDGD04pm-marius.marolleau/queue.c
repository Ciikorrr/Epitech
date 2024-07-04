/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD04pm-marius.marolleau
** File description:
** queue
*/
#include "queue.h"
#include <stdio.h>

unsigned int queue_get_size(queue_t *queue)
{
    return list_get_size(queue);
}

bool queue_is_empty(queue_t *queue_ptr)
{
    return list_is_empty(queue_ptr);
}

bool queue_push(queue_t **queue_ptr, void *elem)
{
    return list_add_elem_at_front(queue_ptr, elem);
}

void queue_clear(queue_t **queue_ptr)
{
    return list_clear(queue_ptr);
}

void *queue_front(queue_t *queue)
{
    return list_get_elem_at_back(queue);
}
