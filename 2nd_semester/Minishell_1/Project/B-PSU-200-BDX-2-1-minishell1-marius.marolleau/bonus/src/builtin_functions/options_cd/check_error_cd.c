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
        printf("\33[31;01m: Too many arguments.\033[00m\n");
        minish->result = 1;
        return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}

int check_status_cd(char *command)
{
    if (errno == 20) {
        printf("\033[31;01m %s: Not a directory.\033[00m\n", command);
        return 1;
    }
    if (errno == 13) {
        printf("\033[31;01m %s: Permission denied.\033[00m\n", command);
        return 1;
    }
    if (errno == 2) {
        printf("\033[31;01m %s: No such file or directory.\033[00m\n", command);
        return 1;
    } else {
        perror(command);
    }
    return 1;
}
