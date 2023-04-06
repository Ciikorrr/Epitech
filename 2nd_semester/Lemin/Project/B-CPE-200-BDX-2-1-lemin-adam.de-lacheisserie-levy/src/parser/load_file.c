/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <unistd.h>
#include <stdio.h>
#include "macros.h"
#include "struct_lemin.h"
list_t *new_elem(char **tab, int value);
list_t *add_elem_back(list_t *li, char **tab, int value);
char **my_str_to_word_array_separator(char *str, char *separator);
int my_strncmp(char *one, char *two, int n);
int my_str_isnum(char const *str);
int length_tab(char **tab);

static void fill_room_links(lemin_t *data, char *line)
{
    char **tab = my_str_to_word_array_separator(line, " \n");
    int length = length_tab(tab);
    if (length == 3) {
        add_elem_back(data->parser, tab, ROOM);
    } else {
        add_elem_back(data->parser, tab, LINKS);
    }
}

static int fill_start_end(lemin_t *data, char *line, size_t len)
{
    if (my_strncmp(line, "##start", 7) == 0) {
        getline(&line, &len, stdin);
        add_elem_back(data->parser,
        my_str_to_word_array_separator(line, " \n"), START);
        return SUCCESS_EPITECH;
    }
    if (my_strncmp(line, "##end", 5) == 0) {
        getline(&line, &len, stdin);
        add_elem_back(data->parser,
        my_str_to_word_array_separator(line, " \n"), END);
        return SUCCESS_EPITECH;
    }
    return ERROR_EPITECH;
}

static int get_tab_without_coms(lemin_t *data)
{
    char *line = NULL;
    size_t len;

    getline(&line, &len, stdin);
    data->parser =
    new_elem(my_str_to_word_array_separator(line, " \n"), NB_ANTS);
    if (length_tab(data->parser->tab) != 1 ||
    my_str_isnum(data->parser->tab[0]) == 1)
        return ERROR_EPITECH;
    while (getline(&line, &len, stdin) > 0) {
        if (fill_start_end(data, line, len) == ERROR_EPITECH &&
        line[0] != '#') {
            fill_room_links(data, line);
        }
    }
    return SUCCESS_EPITECH;
}

int parser(lemin_t *data)
{
    if (get_tab_without_coms(data) == ERROR_EPITECH)
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}
