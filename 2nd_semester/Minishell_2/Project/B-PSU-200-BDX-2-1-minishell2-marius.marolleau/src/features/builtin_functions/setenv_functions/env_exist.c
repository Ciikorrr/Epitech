/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdlib.h>
#include "struct_mnishell.h"
#include "linked_list.h"
#include "protos.h"
#include "utils.h"

void env_doesnt_exist(msh_t *minish, list *env_list)
{
    char *egal = my_strdup("=");
    char *pwd = NULL;
    char *path = strcat_dup(minish->tab_command[1], egal);
    if (length_tab(minish->tab_command) == 3) {
        pwd = strcat_dup(path, minish->tab_command[2]);
        env_list = new_elem(pwd);
    } else {
        env_list = new_elem(path);
    }
    minish->env = list_to_tab(env_list);
    free_list(env_list);
    return;
}

void do_setenv_one_arg(list *env_list, msh_t *minish)
{
    if (env_already_exist(env_list, minish->tab_command) == 0) {
    } else {
        setenv_one_argument(env_list, minish->tab_command);
    }
    return;
}

list *do_setenv(msh_t *minish, list *env_list)
{
    fill_env_list(minish->env, env_list);
    int length_argv = length_tab(minish->tab_command);
    if (length_argv == 1) {
        minish->do_read = 1;
        print_list(env_list, minish);
    }
    if (check_error_setenv(length_argv, env_list, minish) == -1) {
        return env_list;
    }
    if (length_argv == 2) {
        do_setenv_one_arg(env_list, minish);
    } else if (length_argv == 3) {
        setenv_two_argument(env_list, minish->tab_command);
    }
    return env_list;
}

void change_env_list(int index, list *env_list, char *argument, char *arg)
{
    int idx = 0;
    while (idx != index && env_list->next != NULL) {
        idx += 1;
        env_list = env_list->next;
    }
    arg = strcat_dup(arg, argument);
    env_list->str = my_strdup(arg);
    free(arg);
    return;
}

void add_new_env_var(list *env_list, char *argument, char *arg)
{
    while (env_list->next != NULL) {
        env_list = env_list->next;
    }
    arg = strcat_dup(arg, argument);
    env_list = add_elem_back(env_list, arg);
    return;
}
