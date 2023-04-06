/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdlib.h>
#include "struct_mnishell.h"
#include "protos.h"
#include "linked_list.h"
#include "utils.h"

int get_index_env_bis(list *env_list, char *arg);

void change_env(list *env_list, char *var)
{
    char * str = strcat_dup(my_strdup(var), my_strdup("="));
    int index = 0;
    list *node_to_delete = NULL;
    while (env_list != NULL) {
        if (my_strncmp(env_list->next->str, str, my_strlen(str)) == 0) {
            node_to_delete = env_list->next;
            env_list->next = node_to_delete->next;
            return;
        }
        env_list = env_list->next;
        index += 1;
    }
}

list *remove_variable(list *env_list, char *var, msh_t *minish)
{
    int index_env = get_index_env_bis(env_list, var);
    if (index_env == -1) {
        minish->result = 0;
        return env_list;
    }
    if (index_env == 0) {
        env_list = pop_elem_front(env_list);
    } else {
        change_env(env_list, var);
    }
    return env_list;
}

list *remove_all_arg(list *env_list, msh_t *minish)
{
    for (int i = 1; minish->tab_command[i] != NULL; i += 1) {
        env_list = remove_variable(env_list, minish->tab_command[i], minish);
    }
    return env_list;
}

list *do_unsetenv(msh_t *minish, list *env_list)
{
    int len = length_tab(minish->tab_command);
    if (len == 2) {
        env_list = remove_variable(env_list, minish->tab_command[1], minish);
    } else if (len > 2) {
        env_list = remove_all_arg(env_list, minish);
    } else {
        my_putstr_choose("unsetenv: Too few arguments.\n", 2);
        minish->result = 1;
        return env_list;
    }
    return env_list;
}

void fct_unsetenv(msh_t *minish)
{
    if (minish->env[0] == NULL) {
        minish->result = 0;
        return;
    }
    if (length_tab(minish->tab_command) == 1) {
        my_putstr_choose("unsetenv: Too few arguments.\n", 2);
        minish->result = 1;
        return;
    } else {
        list *env_list = new_elem(minish->env[0]);
        fill_env_list(minish->env, env_list);
        env_list = do_unsetenv(minish, env_list);
        minish->env = list_to_tab(env_list);
        free(env_list);
    }
    return;
}
