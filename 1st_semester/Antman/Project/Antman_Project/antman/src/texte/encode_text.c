/*
** EPITECH PROJECT, 2023
** huffman
** File description:
** ui
*/

#include "../../include/protos_compress.h"
#include "../../../include/my.h"
#include "../../include/huffman_struct.h"
#include <stdbool.h>
#include <unistd.h>

int init_dict(encode_list_t **dict, char data, char *arr, int top)
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

int append_data_encode(encode_list_t **dict, char data, char *arr, int top)
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
    head->next = temp; temp->next = NULL;
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
