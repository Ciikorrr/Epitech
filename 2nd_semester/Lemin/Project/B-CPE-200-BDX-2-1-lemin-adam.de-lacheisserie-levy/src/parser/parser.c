/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdlib.h>
#include "macros.h"
#include "protos.h"
#include "struct_lemin.h"

int link_is_present(char **name_node, char *link)
{
    if (name_node == NULL || link == NULL)
        return ERROR_EPITECH;
    for (int i = 0; name_node[i] != NULL; i += 1) {
        if (my_strcmp(name_node[i], link) == 0)
            return SUCCESS_EPITECH;
    }
    return ERROR_EPITECH;
}

int check_all_links(char **tab_link, char **name_node)
{
    char **links = NULL;
    if (tab_link == NULL || name_node == NULL)
        return ERROR_EPITECH;
    links = my_str_to_word_array_separator(tab_link[0], "-");
    if (link_is_present(name_node, links[0]) == ERROR_EPITECH)
        return ERROR_EPITECH;
    if (link_is_present(name_node, links[1]) == ERROR_EPITECH)
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}

int check_links(lemin_t *anthill)
{
    if (anthill->parser->origin == LINKS) {
        if (check_all_links(anthill->parser->tab, anthill->name_nodes) == ERROR_EPITECH) {
            return ERROR_EPITECH;
        }
    }
    return SUCCESS_EPITECH;
}

int check_rooms(lemin_t *anthill)
{
    if (anthill->parser->origin == ROOM || anthill->parser->origin == END ||
    anthill->parser->origin == START) {
        if (add_name_node(anthill, anthill->parser->tab[0]) == ERROR_EPITECH) {
            return ERROR_EPITECH;
        }
    }
    return SUCCESS_EPITECH;
}

int check_list_parse(lemin_t *anthill)
{
    if (anthill == NULL)
        return ERROR_EPITECH;
    while (anthill->parser != NULL) {
        if (check_rooms(anthill) == ERROR_EPITECH)
            return ERROR_EPITECH;
        else if (check_links(anthill) == ERROR_EPITECH)
            return ERROR_EPITECH;
        else
            return ERROR_EPITECH;
        anthill->parser = anthill->parser->next;
    }
    return SUCCESS_EPITECH;
}

int check_error(lemin_t *anthill)
{
    if (anthill == NULL)
        return ERROR_EPITECH;
    if (check_list_parse(anthill) == ERROR_EPITECH) {
        return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}
