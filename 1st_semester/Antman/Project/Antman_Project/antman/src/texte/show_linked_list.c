/*
** EPITECH PROJECT, 2023
** print linked list
** File description:
** ui
*/

#include "../../include/huffman_struct.h"
#include "../../../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int get_len(linkedlist_t *list)
{
    linkedlist_t *head = list;

    int len = 0;
    while (head != NULL) {
        len += 1;
        head = head->next;
    }
    return len;
}

void show_linked_list(linkedlist_t *list)
{
    char pipe = '|';
    linkedlist_t *head = list;
    int len = get_len(list);
    char *len_list = my_itoa(len);
    write(1, len_list, my_strlen(len_list));
    write(1, &pipe, 1);
    while (head != NULL) {
        write(1, &head->dico.data, 1);
        char *str = my_itoa(head->dico.freq);
        int len = my_strlen(str);
        write(1, str, len);
        write(1, &pipe, 1);
        head = head->next;
    }
}

void free_linked_list(linkedlist_t *list)
{
    linkedlist_t *tmp;

    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

void free_encode_list(encode_list_t *dict)
{
    encode_list_t *tmp;

    while (dict != NULL) {
        tmp = dict;
        dict = dict->next;
        free(tmp->arr);
        free(tmp);
    }
}

void free_encode_and_dict(linkedlist_t *list, encode_list_t *dict)
{
    free_encode_list(dict);
    free_linked_list(list);
}
