/*
** EPITECH PROJECT, 2023
** binary_tree
** File description:
** antman tree
*/

#ifndef STRUCT
    #define STRUCT
    #include <stdio.h>
    #include <stdlib.h>
    #include "macros.h"
    #include <stddef.h>

typedef struct node_s {
    char value;
    char *code;
    int occ;
    struct node_s *right;
    struct node_s *left;
} node_t;

typedef struct list_element {
    node_t value;
    struct list_element *next;
}list_t;

typedef struct antman {
    char *str_init;
    char *all_char;
    int nb_char;
    node_t **dico;
}ant_t;

#endif
