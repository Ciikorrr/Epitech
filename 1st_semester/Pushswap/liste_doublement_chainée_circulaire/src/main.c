/*
** EPITECH PROJECT, 2022
** Start_projet
** File description:
** main
*/
#include <stdio.h>
#include "my.h"
#include "list.h"
void add_elem(head_list *list, int nb);
void *create_head(head_list *list, int nb);
node *create_element(node *li, int nb);

int main(int argc, char **argv)
{
    head_list *la = malloc(sizeof(head_list));
    la->size = 0;
    if (la == NULL)
        return NULL;
        add_elem(la, my_getnbr(argv[1]));
    for (int i = 2; i < argc; i += 1) {
        int nb = my_getnbr(argv[i]);
        add_elem(la, nb);
    }
    for (int j = 0; j < la->size; j += 1) {
        printf("%d\n", la->head->value);
        la->head = la->head->next;
    }
}
