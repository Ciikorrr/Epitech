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

void get_codes(heap_node_t *root, encode_list_t **dict, char arr[], int top)
{
    if (root->left) {
        arr[top] = '0';
        get_codes(root->left, dict, arr, top + 1);
    }

    if (root->right) {
        arr[top] = '1';
        get_codes(root->right, dict, arr, top + 1);
    }

    if (is_leaf(root)) {
        add_data_encode(dict, root->dico.data, arr, top);
    }
}

void write_bytes(char *code, char *encode_text, int *idx, int top)
{
    int arr_index = 0;
    int bit_index = 0;
    for (int i = 0; i < top; i += 1) {
        arr_index = *idx / 8;
        bit_index = *idx % 8;
        if (code[i] == '1') {
            encode_text[arr_index] |= 1 << bit_index;
        }
        *idx += 1;
    }
}

void encode_text(encode_list_t *dict, char c, char *encoded_text, int *idx)
{
    encode_list_t *temp = dict;
    while (temp != NULL) {
        if (temp->data == c) {
            write_bytes(temp->arr, encoded_text, idx, temp->top);
            return;
        }
        temp = temp->next;
    }
}
