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
        if (head->dico.data == '|')
            len += 1;
        len += 1;
        head = head->next;
    }
    return len;
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
