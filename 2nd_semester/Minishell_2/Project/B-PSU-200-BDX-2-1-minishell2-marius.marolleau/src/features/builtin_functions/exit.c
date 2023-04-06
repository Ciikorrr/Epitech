/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdlib.h>
#include "protos.h"
#include "struct_mnishell.h"
#include "macros.h"
#include "utils.h"

void fct_exit(msh_t *minish)
{
    if (length_tab(minish->tab_command) > 1) {
        my_putstr_choose("exit: Expression Syntax.\n", 2);
        minish->result = 1;
    } else {
        my_putstr("exit\n");
        minish->exit = 1;
    }
    return;
}
