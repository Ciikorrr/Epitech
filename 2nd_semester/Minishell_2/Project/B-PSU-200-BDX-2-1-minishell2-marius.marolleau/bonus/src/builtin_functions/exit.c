/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdlib.h>
#include <stdio.h>
#include "protos.h"
#include "struct_mnishell.h"
#include "macros.h"
#include "utils.h"

void fct_exit(msh_t *minish)
{
    if (length_tab(minish->tab_command) > 1) {
        printf("\33[31;01mexit: Expression Syntax.\33[00m\n");
        minish->result = 1;
    } else {
        my_putstr("exit\n");
        minish->exit = 1;
    }
    return;
}
