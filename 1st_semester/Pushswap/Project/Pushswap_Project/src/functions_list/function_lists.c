/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-marius.marolleau
** File description:
** function_lists
*/
#include <unistd.h>
#include "my.h"
#include "mylist.h"
#include "operations.h"
#include "macros.h"
#include "protos.h"

int check_sort(list *l1)
{
    while (l1->next != NULL) {
        if (l1->value <= l1->next->value)
            l1 = l1->next;
        else {
            return 1;
        }
    }
    return SUCCESS_EPITECH;
}

void free_all(s_list *lists)
{
    clear_list(lists->la);
    free(lists);
}

s_list *make_sort(s_list *lists)
{
    while (!(is_empty_list(lists->la))) {
        int min = search_min(lists);
        min_in_first(lists, min);
        action_pb(lists);
        write(1,"pb ",3);
    }
    while (lists->lb->next != NULL) {
        action_pa(lists);
        write(1, "pa ", 3);
    }
    action_pa(lists);
        write(1, "pa", 2);
    return lists;
}
