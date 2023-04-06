/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include "struct_mnishell.h"

#ifndef MYLIST
    #define MYLIST

typedef struct list_element {
    char *str;
    struct list_element *next;
}list;

list *new_elem(char *value);
list *add_elem_back(list *li, char *value);
void print_list(list *li, msh_t *minish);
list *pop_elem_back(list *li);
void free_element(list *li);
int length_list(list *li);
list *add_elem_front(list *li, char *value);
char **list_to_tab(list *env_list);
list *fill_env_list(char **env, list *env_list);
int free_list(list *env_list);
list *pop_elem_front(list *li);


#endif /* !MYLIST */
