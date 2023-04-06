/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "opt_builtin.h"
#include "struct_mnishell.h"
#include "protos.h"
#include "macros.h"
#include "utils.h"

int setenv_one_argument(list *env_list, char **tab)
{
    char * arg = my_strdup(tab[1]);
    char *path = my_strdup("=");
    arg = strcat_dup(arg, path);
    add_elem_back(env_list, arg);
    return SUCCESS_EPITECH;
}

int get_index_already_exist(list *env_list, char **tab)
{
    char *arg = my_strdup(tab[1]);
    char *path = my_strdup("=");
    arg = strcat_dup(arg, path);
    int index = 0;
    while (env_list != NULL) {
        if (my_strncmp(arg, env_list->str, my_strlen(arg)) == 0) {
            free(arg);
            return index;
        }
        env_list = env_list->next;
        index += 1;
    }
    return -1;
}

int setenv_two_argument(list *env_list, char **tab)
{
    char *arg = my_strdup(tab[1]);
    char *argument = my_strdup(tab[2]);
    char *path = my_strdup("=");
    int index = get_index_already_exist(env_list, tab);
    arg = strcat_dup(arg, path);
    if (index != -1) {
        change_env_list(index, env_list, argument, arg);
        return SUCCESS_EPITECH;
    }
    if (index == -1) {
        add_new_env_var(env_list, argument, arg);
        return SUCCESS_EPITECH;
    }
    return SUCCESS_EPITECH;
}

int env_already_exist(list *env_list, char **tab)
{
    char *arg = my_strdup(tab[1]);
    char *path = my_strdup("=");
    arg = strcat_dup(arg, path);
    while (env_list != NULL) {
        if (my_strncmp(arg, env_list->str, my_strlen(arg)) == 0) {
            env_list->str = my_strcpy(env_list->str, arg);
            free(arg);
            return SUCCESS_EPITECH;
        }
        env_list = env_list->next;
    }
    return ERROR_EPITECH;
}

void fct_setenv(msh_t *minish)
{
    minish->result = 0;
    list *env_list = NULL;
    if (minish->env[0] != NULL) {
        env_list = new_elem(minish->env[0]);
    } else {
        env_exist(minish, env_list);
        return;
    }
    env_list = do_setenv(minish, env_list);
    minish->env = list_to_tab(env_list);
    free_list(env_list);
    return;
}
