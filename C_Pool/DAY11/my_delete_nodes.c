/*
** EPITECH PROJECT, 2022
** my_delete_nodes
** File description:
** rm a node
*/

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *discover = begin;
    linked_list_t *mem = NULL;
    while (discover != NULL) {
        if ( == )

        if ((*cmp)(discover->data, data_ref) == 0) {
            discover->next = mem->next->next;
        }
    }
}
