/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-marius.marolleau
** File description:
** operations
*/

#ifndef OPERATIONS_H_
    #define OPERATIONS_H_
    #include "mylist.h"

    list *action_sa(list *la);
    list *action_sb(list *lb);
    s_list *action_pb(s_list *lists);
    s_list *action_pa(s_list *lists);
    s_list *action_ra(s_list *lists);
    s_list *action_rb(s_list *lists);
    s_list *action_rra(s_list *lists);
    s_list *action_rrb(s_list *lists);
    s_list *action_rrr(s_list *lists);
    int my_printf(char const *format, ...);
#endif /* !OPERATIONS_H_ */
