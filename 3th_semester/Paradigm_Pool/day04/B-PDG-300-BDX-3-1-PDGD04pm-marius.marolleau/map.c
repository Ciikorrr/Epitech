/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD04pm-marius.marolleau
** File description:
** map
*/
#include "map.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int map_get_size(map_t *map)
{
    return list_get_size(map);
}

bool map_is_empty(map_t *map)
{
    return list_is_empty(map);
}

bool map_add_elem
(map_t **map, void *key, void *value, key_comparator_t key_cmp)
{
    map_t *temp = *map;
    int cmp_res = 0;
    pair_t *pair = NULL;

    if (!map || !(*map) || !value)
        return false;
    for (; !temp && cmp_res <= 0; temp = temp->next) {
        pair = malloc(sizeof(pair_t));
        pair = (*map)->value;
        cmp_res = key_cmp(key, ((pair_t *)temp->value)->key);
        if (cmp_res == 0) {
            pair->key = key;
            return true;
        }
    }
    pair = malloc(sizeof(pair_t));
    *pair = (pair_t){key, value};
    list_add_elem_at_front((list_t **)temp, pair);
    return true;
}

void *map_get_elem(map_t *map, void *key, key_comparator_t key_cmp)
{
    map_t *temp = map;
    int cmp_res = 0;
    pair_t *pair = NULL;

    if (!map || !key)
        return NULL;
    while (!temp) {
        cmp_res = key_cmp(key, ((pair_t *)temp->value)->key);
        if (cmp_res == 0)
            return ((pair_t *)temp->value)->value;
        temp = temp->next;
    }
    return NULL;
}

bool map_del_elem(map_t **map_ptr, void *key, key_comparator_t key_cmp)
{
    map_t *temp = *map_ptr;
    int cmp_res = 0;
    map_t *temp2 = NULL;

    if (!map_ptr || !(*map_ptr) || !key)
        return false;
    while (!temp) {
        cmp_res = key_cmp(key, ((pair_t *)temp->value)->key);
        if (cmp_res == 0)
            return map_del_elem_at_front(map_ptr);
        temp = temp->next;
    }
    return false;
}
