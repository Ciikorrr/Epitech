/*
** EPITECH PROJECT, 2023
** huffman
** File description:
** ui
*/

#include "../../include/protos.h"
#include "../../../include/my.h"
#include "../../include/huffman_struct.h"
#include <stdbool.h>
#include <unistd.h>

heap_node_t *create_huffman_tree(linkedlist_t *list)
{
    heap_node_t *top;
    heap_node_t *left;
    heap_node_t *right;
    heap_tree_t *min_heap = build_min_heap(list, 2000);

    while (min_heap->size > 1) {
        left = remove_min(min_heap);
        right = remove_min(min_heap);

        top = new_node((dict_t){'\a', left->dico.freq + right->dico.freq});

        top->left = left;
        top->right = right;
        insert_heap_node(min_heap, top);
    }
    return remove_min(min_heap);
}

static int init_dict(encode_list_t **dict, char data, char *arr, int top)
{
    (*dict) = malloc(sizeof(encode_list_t));
    if (*dict == NULL)
        return ERROR_EPITECH;
    (*dict)->data = data;
    (*dict)->arr = malloc(sizeof(char) * (top));
    if ((*dict)->arr == NULL)
        return ERROR_EPITECH;
    (*dict)->top = top;
    for (int i = 0; i < top; i += 1)
        (*dict)->arr[i] = arr[i];
    (*dict)->next = NULL;
    return SUCCESS_EPITECH;
}

static int append_data_encode(
    encode_list_t **dict,
    char data,
    char *arr,
    int top)
{
    encode_list_t *head = (*dict);
    encode_list_t *temp = malloc(sizeof(encode_list_t));
    if (temp == NULL)
        return ERROR_EPITECH;
    temp->data = data;
    temp->arr = malloc(sizeof(char) * (top));
    temp->top = top;
    if (temp->arr == NULL)
        return ERROR_EPITECH;
    for (int i = 0; i < top; i += 1)
        temp->arr[i] = arr[i];
    while (head->next != NULL)
        head = head->next;
    head->next = temp;
    temp->next = NULL;
    return SUCCESS_EPITECH;
}

int add_data_encode(encode_list_t **dict, char data, char *arr, int top)
{
    if ((*dict) == NULL) {
        return init_dict(dict, data, arr, top);
    } else {
        return append_data_encode(dict, data, arr, top);
    }
}
