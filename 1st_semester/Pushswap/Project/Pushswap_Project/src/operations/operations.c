/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-marius.marolleau
** File description:
** sa
*/

#include <stdio.h>
#include "my.h"
#include "mylist.h"

list *action_sa(list *la)
{
    int memo = la->value;
    la->value = la->next->value;
    la->next->value = memo;
}

list *action_sb(list *lb)
{
    int memo = lb->value;
    lb->value = lb->next->value;
    lb->next->value = memo;
}

list *action_sc(s_list *lists)
{
    lists->la = action_sa(lists->la);
    lists->lb = action_sb(lists->lb);
}

s_list *action_pa(s_list *lists)
{
    if (is_empty_list(lists->lb) == true)
        return NULL;
    int memo = lists->lb->value;
    lists->lb = pop_elem_front(lists->lb);
    lists->la = add_elem_front(lists->la, memo);

    return lists;
}

s_list *action_pb(s_list *lists)
{
    if (is_empty_list(lists->la) == true)
        return NULL;
    int memo = lists->la->value;
    lists->la = pop_elem_front(lists->la);
    lists->lb = add_elem_front(lists->lb, memo);
    return lists;
}
