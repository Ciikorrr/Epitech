/*
** EPITECH PROJECT, 2022
** btree
** File description:
** btree
*/

#IFNDEF BTREE
    #DEFINE BTREE

typedef struct btree
{
    struct btree *left;
    struct btree *right;
    void *item;
} btree_t;

#ENDIF
