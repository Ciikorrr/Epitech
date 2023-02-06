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

linkedlist_t *init_new_list(linkedlist_t *list, char data, int freq)
{
    list = malloc(sizeof(linkedlist_t));
    if (list == NULL)
        return NULL;
    list->dico.data = data;
    list->dico.freq = freq;
    list->next = NULL;
    return list;
}

linkedlist_t *recreate_list(linkedlist_t *list, int *start, int len, char *str)
{
    char f_data = str[*start];
    int f_freq = my_special_getnbr(str, start);
    list = init_new_list(list, f_data, f_freq);
    int nb_pipe = 1;
    linkedlist_t *temp = list;
    int letter_idx = *start + 1;
    int getnbr_idx = *start + 2;
    for (int i = 0; i < len - nb_pipe; i += 1) {
        linkedlist_t *newData = malloc(sizeof(linkedlist_t));
        if (newData == NULL) return NULL;
        newData->dico.data = str[letter_idx];
        newData->dico.freq = my_special_getnbr(str, &getnbr_idx);
        newData->next = NULL;
        temp->next = newData;
        temp = temp->next;
        letter_idx = getnbr_idx + 1;
        getnbr_idx += 2;
    }
    *start = getnbr_idx - 2;
    return list;
}

linkedlist_t *parse_header(char *str, int *bits, int *idx)
{
    *bits = my_special_getnbr(str, idx);
    int len = my_special_getnbr(str, idx);
    *idx += 1;
    linkedlist_t *list = recreate_list(list, idx, len, str);
    if (list == NULL)
        return NULL;
    return list;
}
