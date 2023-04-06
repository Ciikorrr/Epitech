/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdlib.h>
#include <unistd.h>
#include "struct_mnishell.h"
#include "tableau.h"
#include "macros.h"
#include "utils.h"
#include "protos.h"

int check_for_builtin(msh_t *minish, char *command)
{
    for (int i = 0; i < TAB_SIZE; i += 1) {
        if (my_strcmp(command, tab_builtin[i].opt) == 0) {
            tab_builtin[i].function(minish);
            return minish->result;
        }
    }
    return ERROR_EPITECH;
}

char *exec_absolut_path(char *command)
{
    if (access(command, F_OK) != 0) {
        return command;
    }
    return NULL;
}

char *is_builtins(char *command)
{
    for (int i = 0; i < TAB_SIZE; i += 1) {
        if (my_strcmp(command, tab_builtin[i].opt) == 0) {
            return command;
        }
    }
    return NULL;
}

char *is_absolut(msh_t *minish, char *command)
{
    char *path_find = NULL;
    for (int i = 0; minish->tab_command[0][i] != '\0'; i += 1) {
        if (minish->tab_command[0][i] == '/')
            path_find = check_for_path(command);
    }
    if (path_find != NULL) {
        return path_find;
    }
    return path_find;
}

char *is_path(msh_t *minish, char *command)
{
    char *path_find = find_path(minish->env, my_strdup(minish->tab_command[0]));
    if (path_find == NULL)
        return NULL;
    if (access(path_find, F_OK) == 0) {
        free(command);
        return path_find;
    }
    return NULL;
}
