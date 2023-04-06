/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include "protos.h"
#include "utils.h"

void fct_env(msh_t *minish)
{
    if (length_tab(minish->tab_command) >= 2) {
        my_putstr_choose("env: '", 2);
        my_putstr_choose(minish->tab_command[1], 2);
        my_putstr_choose("': No such file or directory\n", 2);
        minish->result = 127;
    } else {
        for (int i = 0; minish->env[i] != NULL; i += 1) {
            my_putstr(minish->env[i]);
            my_putstr("\n");
            minish->result = 0;
        }
    }
    return;
}
