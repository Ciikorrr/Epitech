/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-marius.marolleau
** File description:
** protos
*/

#ifndef PROTOS_H_
    #define PROTOS_H_
    #include "mylist.h"
int check_isnum(int argc, char **argv);
s_list *fill_list(int argc, char **argv, s_list *lists);
int check_sort(list *l1);
s_list *min_in_first(s_list *lists, int max);
int search_min(s_list *lists);
int check_argc(int argc);
s_list *make_sort(s_list *lists);
void free_all(s_list *lists);
void free_element(list *li);
int my_isdigit_bis(char c);

#endif /* !PROTOS_H_ */
