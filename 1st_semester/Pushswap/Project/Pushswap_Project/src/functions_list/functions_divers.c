/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-marius.marolleau
** File description:
** functions_divers
*/
#include <unistd.h>
#include "my.h"
#include "mylist.h"
#include "operations.h"
#include "macros.h"

int search_min(s_list *lists)
{
    list *temp = lists->la;
    int max = temp->value;
    int i = 0;
    int index = 0;
    while (temp != NULL) {
        if (temp->value < max) {
            max = temp->value;
            index = i;
        }
        i += 1;
        temp = temp->next;
    }
    return index;
}

s_list *fill_list(int argc, char **argv, s_list *lists)
{
    lists->lb = malloc(sizeof(list));
    if (lists->lb == NULL)
        return NULL;
    lists->la = new_elem(my_getnbr(argv[1]));
    lists->lb = NULL;
    for (int i = 2; i < argc; i += 1) {
        add_elem_back(lists->la, my_getnbr(argv[i]));
    }
    return lists;
}

s_list *min_in_first(s_list *lists, int index_min)
{
    int i = 0;
    int len = length_list(lists->la) - 1;
    if (index_min > (length_list(lists->la) / 2)) {
        while (i < (length_list(lists->la) - index_min)) {
            action_rra(lists);
            write(1, "rra ", 4);
            i += 1;
        }
    } else {
        while (i < index_min) {
            action_ra(lists);
            write(1, "ra ", 3);
            i += 1;
        }
    }
    return lists;
}
