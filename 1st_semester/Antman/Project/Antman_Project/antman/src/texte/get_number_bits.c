/*
** EPITECH PROJECT, 2023
** get_number_bytes
** File description:
** ui
*/

#include "../../include/protos_compress.h"
#include "../../../include/my.h"
#include "../../include/huffman_struct.h"
#include <stdbool.h>

static void test_char(encode_list_t *dict, char c, int *nb_bits)
{
    encode_list_t *temp = dict;

    while (temp != NULL) {
        if (c == temp->data) {
            *nb_bits += (temp->top);
            return;
        }
        temp = temp->next;
    }
}

int get_number_bits(encode_list_t *dict, char *file_content)
{
    int nb_bits = 0;
    for (int i = 0; file_content[i] != '\0'; i += 1) {
        test_char(dict, file_content[i], &nb_bits);
    }
    return nb_bits;
}
