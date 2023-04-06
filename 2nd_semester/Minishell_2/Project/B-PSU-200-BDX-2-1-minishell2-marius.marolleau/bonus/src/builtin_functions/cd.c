/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdio.h>
#include "cd.h"
#include "struct_mnishell.h"
#include "macros.h"

int do_cd_with_other_opt(msh_t *minish)
{
    if (minish->tab_command[1][0] == '-' &&
    minish->tab_command[1][1] == '\0') {
        minish->result = cd_moins(minish->env, minish);
        return minish->result;
    } else {
        cd_basic(minish);
    }
    return minish->result;
}

void choose_cd(msh_t *minish)
{
    char *new_path = NULL;
    if (minish->tab_command[1] == NULL ||
    (minish->tab_command[1][0] == '~' && minish->tab_command[1][1] == '\0')) {
        minish->result = simple_cd(minish->env, minish);
        return;
    }
    if (minish->tab_command[1][0] == '~' &&
    minish->tab_command[1][1] == '/') {
        minish->result = cd_with_path(new_path, minish->env,
        minish->tab_command, minish);
        return;
    }
    minish->result = do_cd_with_other_opt(minish);
    return;
}

void fct_cd(msh_t *minish)
{
    minish->result = 0;
    if (check_error_cd(minish) == ERROR_EPITECH)
        return;
    choose_cd(minish);
    return;
}
