/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct_mnishell.h"
#include "protos.h"
#include "macros.h"
#include "utils.h"

int check_error_cd(msh_t *minish)
{
    if (length_tab(minish->tab_command) >= 3) {
        write(1, "cd: Too many arguments.\n", 24);
        minish->result = 1;
        return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}

int check_status_cd(char *command)
{
    if (errno == 20) {
        my_putstr_choose(command, 2);
        my_putstr_choose(": Not a directory.\n", 2);
        return 1;
    }
    if (errno == 13) {
        my_putstr_choose(command, 2);
        my_putstr_choose(": Permission denied.\n", 2);
        return 1;
    }
    if (errno == 2) {
        my_putstr_choose(command, 2);
        my_putstr_choose(": No such file or directory.\n", 2);
        return 1;
    } else {
        perror(command);
    }
    return 1;
}
