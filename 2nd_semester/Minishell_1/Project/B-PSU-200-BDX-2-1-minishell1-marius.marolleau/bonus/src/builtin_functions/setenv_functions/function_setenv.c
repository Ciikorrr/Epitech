/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include "struct_mnishell.h"
#include "protos.h"
#include "macros.h"
#include "utils.h"

msh_t *check_char_1_args(msh_t *minish, int length_argv)
{
    if (length_argv >= 2) {
        if (my_str_isalpha(minish->tab_command[1]) == 0) {
            minish->result = 1;
            return minish;
        }
    }
    return minish;
}

int setenv_too_many_arg(list *env_list, msh_t *minish)
{
    printf("\33[31;01msetenv: Too many arguments.\33[00m\n");
    while (env_list->next != NULL) {
        pop_elem_back(env_list);
    }
    free_element(env_list);
    minish->result = 1;
    return -1;
}

int no_alphanum_char(list *env_list)
{
    printf("\33[31;01msetenv: Variable name must contain alphanumeric \
characters.\33[00m\n");
    while (env_list->next != NULL) {
        pop_elem_back(env_list);
    }
    return -1;
}

int check_error_setenv(int length_argv, list *env_list, msh_t *minish)
{
    if (length_argv > 3) {
        return setenv_too_many_arg(env_list, minish);
    }
    minish = check_char_1_args(minish, length_argv);
    if (minish->result == 1) {
        return no_alphanum_char(env_list);
    }
    return 0;
}
