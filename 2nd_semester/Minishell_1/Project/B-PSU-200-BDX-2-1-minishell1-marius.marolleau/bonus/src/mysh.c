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
#include "protos.h"

void check_exit(int *check, msh_t *minish)
{
    if (minish->exit == 1) {
        (*check) = 0;
    }
}

msh_t *mysh(msh_t *minish)
{
    char *str = NULL;
    int check = 1;
    while (check == 1) {
        write(1, "$> ", 3);
        str = get_input();
        if (str == NULL)
            check = 0;
        if (str != NULL && (minish = do_command(str, minish))){
            check_exit(&check, minish);
        }
    }
    free(str);
    return minish;
}
