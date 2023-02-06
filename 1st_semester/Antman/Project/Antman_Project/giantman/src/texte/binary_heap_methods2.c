/*
** EPITECH PROJECT, 2023
** heap methods
** File description:
** ui
*/

#include "../../include/protos.h"
#include <stdbool.h>
#include "../../include/huffman_struct.h"

bool is_leaf(heap_node_t *node)
{
    if (node->left == NULL && node->right == NULL)
        return true;
    return false;
}

void set_min_heap(heap_tree_t *min_heap)
{
    int k = min_heap->size - 1;
    int i = 0;

    for (i = (k - 1) / 2; i >= 0; i -= 1)
        minheapify(min_heap, i);
}

heap_tree_t *build_min_heap(linkedlist_t *list, int capacity)
{
    heap_tree_t *min_heap = create_heap_tree(capacity);
    linkedlist_t *head = list;
    int i = 0;
    while (head != NULL) {
        min_heap->array[i] = new_node(head->dico);
        head = head->next;
        i += 1;
    }

    min_heap->size = i;
    set_min_heap(min_heap);
    return min_heap;
}

heap_node_t *remove_min(heap_tree_t *min_heap)
{
    heap_node_t *min = min_heap->array[0];

    min_heap->array[0] = min_heap->array[min_heap->size - 1];
    min_heap->size -= 1;

    minheapify(min_heap, 0);
    return min;
}
