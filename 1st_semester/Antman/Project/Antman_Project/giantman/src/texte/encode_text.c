/*
** EPITECH PROJECT, 2023
** encode text
** File description:
** ui
*/

#include "../../include/protos.h"
#include "../../../include/my.h"
#include "../../include/huffman_struct.h"
#include <stdbool.h>
#include <unistd.h>

void print_codes(heap_node_t *root, encode_list_t **dict, char arr[], int top)
{
    if (root->left) {
        arr[top] = '0';
        print_codes(root->left, dict, arr, top + 1);
    }

    if (root->right) {
        arr[top] = '1';
        print_codes(root->right, dict, arr, top + 1);
    }

    if (is_leaf(root)) {
        add_data_encode(dict, root->dico.data, arr, top);
    }
}

void write_bytes(char *code, char *encode_text, int *idx, int top)
{
    int arr_index = 0;
    int bit_index = 0;
    for (int i = top - 1; i > -1; i -= 1) {
        arr_index = *idx / 8;
        bit_index = *idx % 8;
        if (code[i] == '1') {
            encode_text[arr_index] |= 1 << bit_index;
        }
        *idx += 1;
    }
}
