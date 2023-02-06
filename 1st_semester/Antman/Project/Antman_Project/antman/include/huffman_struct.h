/*
** EPITECH PROJECT, 2023
** HUFFMAN_STRUCT_
** File description:
** ui
*/


#ifndef HUFFMAN_STRUCT_
    #define HUFFMAN_STRUCT_

    #include <stdbool.h>

    typedef struct dict_s {
        char data;
        unsigned freq;
    } dict_t;

    typedef struct heap_node_s {
        dict_t dico;

        struct heap_node_s *left;
        struct heap_node_s *right;

    } heap_node_t;

    typedef struct heap_tree_s {
        unsigned size;
        unsigned capacity;

        heap_node_t **array;
    } heap_tree_t;

    typedef struct linkedlist_s {
        dict_t dico;
        struct linkedlist_s *next;
    } linkedlist_t;

    typedef struct encode_list_s {
        char data;
        char *arr;
        int top;

        struct encode_list_s *next;
    } encode_list_t;

    heap_node_t *new_node(dict_t dico);
    heap_tree_t *create_heap_tree(int capacity);
    void swap_nodes(heap_node_t **a, heap_node_t **b);
    void minheapify(heap_tree_t *min_heap, int index);
    void insert_heap_node(heap_tree_t *min_heap, heap_node_t *node);
    linkedlist_t *determine_frequency(char *str);
    bool is_leaf(heap_node_t *node);
    void set_min_heap(heap_tree_t *min_heap);
    heap_tree_t *build_min_heap(linkedlist_t *list, int capacity);
    heap_node_t *remove_min(heap_tree_t *min_heap);
    int get_number_bits(encode_list_t *dict, char *file_content);
    int add_data_encode(encode_list_t **dict, char data, char arr[], int top);
    void get_codes(heap_node_t *root, encode_list_t **dict, char arr[], int t);
    void write_bytes(char *code, char *encode_text, int *idx, int top);
    void encode_text(encode_list_t *dict, char c, char *encode_text, int *idx);
    void free_linked_list(linkedlist_t *list);
    void free_encode_list(encode_list_t *dict);
    void free_encode_and_dict(linkedlist_t *list, encode_list_t *dict);

#endif /* HUFFMAN_STRUCT_ */
