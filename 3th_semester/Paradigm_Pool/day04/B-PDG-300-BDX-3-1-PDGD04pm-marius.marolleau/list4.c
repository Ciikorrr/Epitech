/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD04pm-marius.marolleau
** File description:
** list4
*/
#include "list.h"
#include <stdio.h>

void list_dump(list_t *list, value_displayer_t val_disp)
{
    while (list != NULL) {
        val_disp(list->value);
        list = list->next;
    }
}
