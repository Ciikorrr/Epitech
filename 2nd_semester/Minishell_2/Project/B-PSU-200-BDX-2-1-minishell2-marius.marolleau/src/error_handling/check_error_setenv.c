/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdlib.h>
#include "linked_list.h"
#include "struct_mnishell.h"
#include "protos.h"
#include "macros.h"
#include "utils.h"

void check_char_1_args(msh_t *minish, int length_argv)
{
    if (length_argv == 2 || length_argv == 3) {
        if (my_str_isalpha(minish->tab_command[1]) == 0) {
            minish->result = 1;
            return;
        }
    }
    return;
}

void setenv_too_many_arg(msh_t *minish)
{
    write(2, "setenv: Too many arguments.\n", 28);
    minish->result = 1;
    minish->do_read = 1;
    return;
}

int no_alphanum_char(void)
{
    my_putstr_choose("setenv: Variable name must contain alphanumeric \
characters.\n", 2);
    return -1;
}

int check_error_setenv(int length_argv, list *env_list, msh_t *minish)
{
    (void)env_list;
    check_char_1_args(minish, length_argv);
    if (minish->result == 1) {
        minish->do_read = 1;
        return no_alphanum_char();
    }
    return 0;
}
