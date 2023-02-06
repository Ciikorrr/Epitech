/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-marius.marolleau
** File description:
** operations_3
*/

#include <stdio.h>
#include "my.h"
#include "mylist.h"

s_list *action_rra(s_list *lists)
{
    if (is_empty_list(lists->la) == true)
        return NULL;
    list *temp = lists->la;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    int memo = temp->value;
    lists->la = add_elem_front(lists->la, memo);
    lists->la = pop_elem_back(lists->la);
    return lists;
}

s_list *action_rrb(s_list *lists)
{
    if (is_empty_list(lists->lb) == true)
        return NULL;
    list *temp = lists->lb;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    int memo = temp->value;
    lists->lb = add_elem_front(lists->lb, memo);
    lists->lb = pop_elem_back(lists->lb);
    return lists;
}

s_list *action_rrr(s_list *lists)
{
    lists = action_rra(lists);
    lists = action_rrb(lists);
    return lists;
}
