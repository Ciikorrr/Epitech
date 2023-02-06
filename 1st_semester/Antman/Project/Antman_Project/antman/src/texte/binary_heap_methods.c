/*
** EPITECH PROJECT, 2023
** heap methods
** File description:
** ui
*/

#include "../../include/protos_compress.h"
#include <stdbool.h>
#include "../../include/huffman_struct.h"

heap_node_t *new_node(dict_t dico)
{
    heap_node_t *node = malloc(sizeof(heap_node_t));
    if (node == NULL)
        return NULL;
    node->left = NULL;
    node->right = NULL;

    node->dico.data = dico.data;
    node->dico.freq = dico.freq;

    return node;
}

heap_tree_t *create_heap_tree(int capacity)
{
    heap_tree_t *min_heap = malloc(sizeof(heap_tree_t));
    if (min_heap == NULL)
        return NULL;

    min_heap->size = 0;
    min_heap->capacity = capacity;

    min_heap->array = malloc(sizeof(heap_node_t *) * min_heap->capacity);
    if (min_heap->array == NULL)
        return NULL;

    return min_heap;
}

void swap_nodes(heap_node_t **a, heap_node_t **b)
{
    heap_node_t *temp = *a;
    *a = *b;
    *b = temp;
}

void minheapify(heap_tree_t *min_heap, int index)
{
    int smallest_element = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < min_heap->size && min_heap->array[left]->dico.freq <
            min_heap->array[smallest_element]->dico.freq)
        smallest_element = left;

    if (right < min_heap->size && min_heap->array[right]->dico.freq <
            min_heap->array[smallest_element]->dico.freq)
        smallest_element = right;

    if (smallest_element != index) {
        swap_nodes(&min_heap->array[smallest_element], &min_heap->array[index]);
        minheapify(min_heap, smallest_element);
    }
}

void insert_heap_node(heap_tree_t *min_heap, heap_node_t *node)
{
    min_heap->size += 1;
    int i = min_heap->size - 1;

    while (i && node->dico.freq < min_heap->array[(i - 1) / 2]->dico.freq) {
        min_heap->array[i] = min_heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    min_heap->array[i] = node;
}
