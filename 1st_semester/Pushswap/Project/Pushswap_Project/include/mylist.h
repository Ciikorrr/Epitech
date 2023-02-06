/*
** EPITECH PROJECT, 2022
** Hub-Workshop
** File description:
** my
*/

#ifndef MYLIST
    #define MYLIST

    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>


typedef struct list_element {
    long long int value;
    struct list_element *next;
}list;

typedef struct struct_lists {
    list *la;
    list *lb;
}s_list;

// list.c
list *new_elem(int value);
list *add_elem_back(list *li, int value);
list *add_elem_front(list *li, int value);

// free_list.cd
list *pop_elem_back(list *li);
list *pop_elem_front(list *li);
void clear_list(list *li);

// utils_list.c
int length_list(list *li);
void print_list(list *li);
bool is_empty_list(list *li);

int my_printf(char const *format, ...);

#endif /* !MYLIST */
