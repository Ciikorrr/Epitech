/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "macros.h"
#include "struct_mnishell.h"
#include "utils.h"
#include "protos.h"

int check_for_path(msh_t *minish, char *command)
{
    if (access(minish->tab_command[0], F_OK) == 0) {
        minish->result = fork_function(minish->tab_command,
        minish->env, command);
        return SUCCESS_EPITECH;
    } else {
        return ERROR_EPITECH;
    }
}

int check_absolut_path(msh_t *minish)
{
    char *command = my_strdup(minish->tab_command[0]);
    char *path_find = NULL;
    for (int i = 0; minish->tab_command[0][i] != '\0'; i += 1) {
        if (minish->tab_command[0][i] == '/')
            return check_for_path(minish, command);
    }
    path_find = find_path(minish->env, path_find,
    my_strdup(minish->tab_command[0]));
    if (path_find != NULL) {
        free(command);
        command = my_strdup(path_find);
    }
    if (access(command, F_OK) == 0) {
        minish->result = fork_function(minish->tab_command,
        minish->env, command);
        return SUCCESS_EPITECH;
    } else {
        return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}
