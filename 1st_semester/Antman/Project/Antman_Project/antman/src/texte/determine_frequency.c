/*
** EPITECH PROJECT, 2023
** text_compression
** File description:
** compress a text
*/

#include "../../include/protos_compress.h"
#include "../../../include/my.h"
#include "../../include/huffman_struct.h"
#include <stdbool.h>

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

void add_data(linkedlist_t *head, char data)
{
    linkedlist_t *temp = head;
    while (temp != NULL) {
        if (temp->dico.data == data) {
            temp->dico.freq += 1;
            return;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    linkedlist_t *newData = init_linkedlist(data);
    temp->next = newData;
}

linkedlist_t *determine_frequency(char *buffer)
{
    linkedlist_t *head = init_linkedlist(buffer[0]);

    for (int i = 1; buffer[i] != '\0'; i += 1)
        add_data(head, buffer[i]);
    return head;
}
