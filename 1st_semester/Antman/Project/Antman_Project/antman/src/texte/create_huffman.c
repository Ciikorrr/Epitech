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

void show_encode_list(encode_list_t *dict);
void show_linked_list(linkedlist_t *list);

heap_node_t *create_huffman_tree(linkedlist_t *list)
{
    heap_node_t *top;
    heap_node_t *left;
    heap_node_t *right;
    heap_tree_t *min_heap = build_min_heap(list, 255);
    if (min_heap == NULL)
        return NULL;

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

char *memset_text(char *encoded_text, int bits)
{
    encoded_text = malloc(sizeof(char) * (bits / 8 + 1));

    if (encoded_text == NULL)
        return NULL;

    for (int i = 0; i < (bits / 8) + 1; i += 1)
        encoded_text[i] = 0;

    return encoded_text;
}

void display_encoded_text(int bits, linkedlist_t *list, char *encoded_text)
{
    char *bits_str = my_itoa(bits);
    int bits_len = my_strlen(bits_str);
    write(1, bits_str, bits_len);
    my_printf("|");
    show_linked_list(list);
    write(1, encoded_text, (bits / 8) + 1);
}

int huffman_compression(linkedlist_t *list, char *str)
{
    heap_node_t *root = create_huffman_tree(list);
    if (root == NULL)
        return ERROR_EPITECH;
    int idx = 0;
    int top = 0;
    int bits = 0;
    char arr[255];
    encode_list_t *dict = NULL;
    get_codes(root, &dict, arr, top);
    bits = get_number_bits(dict, str);
    char *encoded_text = memset_text(encoded_text, bits);
    if (encoded_text == NULL)
        return ERROR_EPITECH;
    for (int i = 0; str[i] != '\0'; i += 1)
        encode_text(dict, str[i], encoded_text, &idx);
    display_encoded_text(bits, list, encoded_text);
    free_encode_and_dict(list, dict);
    free(encoded_text);
    return 0;
}

int huffman_compression_main(char *file_content)
{
    if (file_content == NULL)
        return ERROR_EPITECH;
    if (my_strlen(file_content) == 0) {
        my_printf("\0");
        return SUCCESS_EPITECH;
    }
    linkedlist_t *list = determine_frequency(file_content);
    if (list == NULL)
        return ERROR_EPITECH;
    return huffman_compression(list, file_content);
}
