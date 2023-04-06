/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <fcntl.h>
#include "struct_mnishell.h"
#include "linked_list.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "protos.h"
#include "macros.h"
#include "utils.h"

int count_pipe(char *command)
{
    int nb_pipe = 0;
    for (int i = 0; command[i] != '\0'; i += 1) {
        if (command[i] == '|')
            nb_pipe += 1;
    }
    return nb_pipe;
}

void add_node_end(char *command, list_command_t *list)
{
    list_command_t *element = malloc(sizeof(list_command_t));
    if (element == NULL)
        return;
    element->next = NULL;
    element->tab = my_str_to_word_array_separator(command, " \t");
    list_command_t *tmp = list;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = element;
    return;
}

int fill_list_command(char *command, list_command_t *list)
{
    int j = 1;
    char **sous_tab = my_str_to_word_array_separator(command, "|");
    if (sous_tab[0] == NULL) {
        write(2, "Invalid null command.\n", 22);
        return ERROR_EPITECH;
    }
    list->tab = my_str_to_word_array_separator(sous_tab[0], " \t");
    list->next = NULL;
    if (length_tab(sous_tab) > 1) {
        for (; sous_tab[j] != NULL; j += 1) {
            add_node_end(sous_tab[j], list);
        }
    }
    if (count_pipe(command) >= j) {
        write(2, "Invalid null command.\n", 22);
        return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}

int parser(char *str, msh_t *minish)
{
    char **input = my_str_to_word_array_separator(str, ";\n");
    minish->nb_command = length_tab(input);
    minish->command = malloc(sizeof(list_command_t) * (minish->nb_command));
    for (int i = 0; input[i] != NULL; i += 1) {
        if (fill_list_command(input[i], &minish->command[i]) == ERROR_EPITECH)
            return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}
