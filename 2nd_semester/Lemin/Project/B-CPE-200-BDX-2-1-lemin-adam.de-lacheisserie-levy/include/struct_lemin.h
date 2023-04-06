/*
** EPITECH PROJECT, 2023
** Lemin
** File description:
** struct_lemin
*/

#ifndef STRUCT_LEMIN_H_
    #define STRUCT_LEMIN_H_

typedef struct list_s {
    char **tab;
    int origin;
    struct list_s *next;
}list_t;

typedef struct node_s {
    int distance_from_end;
    int ant;
    int *links;
} node_t;

typedef struct lemin_s {
    int nb_node;
    int nb_ant;
    int start;
    int end;
    list_t *parser;
    char **name_nodes;
    node_t *all_nodes;
    int *order_nodes;
} lemin_t;

#endif /* !STRUCT_LEMIN_H_ */
