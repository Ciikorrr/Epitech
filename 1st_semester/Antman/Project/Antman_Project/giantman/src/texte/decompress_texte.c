/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "../../include/protos.h"
#include "../../../include/my.h"
#include "../../include/huffman_struct.h"
#include <stdbool.h>
#include <unistd.h>

heap_node_t *check_tree(heap_node_t *temp, heap_node_t *root, char c, int mem)
{
    if (is_leaf(temp)) {
        write(1, &temp->dico.data, 1);
        temp = root;
    }
    if ((((int)c >> mem)&1) == 1) {
        temp = temp->right;
    } else {
        temp = temp->left;
    }
    return temp;
}

int decode_text(char *str, heap_node_t *root, int start, int bits)
{
    heap_node_t *temp = root;
    int mem = 0;
    int bits_count = -1;
    for (int i = start + 1; bits_count < bits; i += 1) {
        for (; mem < 8 && bits_count < bits; mem++) {
            bits_count += 1;
            temp = check_tree(temp, root, str[i], mem);
        }
        mem = 0;
    }
    return 0;
}

int decompress_texte(char *str)
{
    if (str == NULL)
        return ERROR_EPITECH;
    if (my_strlen(str) == 0)
        return SUCCESS_EPITECH;
    int bits = 0;
    int start_file = 0;
    linkedlist_t *list = parse_header(str, &bits, &start_file);
    if (list == NULL)
        return 84;
    heap_node_t *root = create_huffman_tree(list);
    if (root == NULL)
        return 84;
    int return_value = decode_text(str, root, start_file, bits);
    free_linked_list(list);
    return return_value;
}
