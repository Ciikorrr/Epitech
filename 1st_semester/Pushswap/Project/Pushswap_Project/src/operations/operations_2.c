/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-marius.marolleau
** File description:
** operations_2
*/
#include <stdio.h>
#include "my.h"
#include "mylist.h"

s_list *action_ra(s_list *lists)
{
    if (is_empty_list(lists->la) == true)
        return NULL;
    int memo = lists->la->value;
    lists->la = add_elem_back(lists->la, memo);
    lists->la = pop_elem_front(lists->la);
    return lists;
}

s_list *action_rb(s_list *lists)
{
    if (is_empty_list(lists->lb) == true)
        return NULL;
    int memo = lists->lb->value;
    lists->lb = add_elem_back(lists->lb, memo);
    lists->lb = pop_elem_front(lists->lb);
    return lists;
}

s_list *action_rr(s_list *lists)
{
    lists = action_ra(lists);
    lists = action_rb(lists);
    return lists;
}
