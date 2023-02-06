/*
** EPITECH PROJECT, 2022
** Pushswap
** File description:
** list
*/

#ifndef LIST_H_
    #define LIST_H_

typedef struct list_element {
    int value;
    struct list_element *next;
    struct list_element *prv;
}node;

typedef struct head_list {
    int size;
    node *head;
}head_list;

#endif /* !LIST_H_ */
