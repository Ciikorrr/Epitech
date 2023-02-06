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

linkedlist_t *init_linkedlist(char data)
{
    linkedlist_t *head = malloc(sizeof(linkedlist_t));
    if (head == NULL)
        return NULL;
    head->next = NULL;
    head->dico.data = data;
    head->dico.freq = 1;
    return head;
}
