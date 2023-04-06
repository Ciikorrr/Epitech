/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include "struct_mnishell.h"
#include "protos.h"
#include "macros.h"
#include "utils.h"
#include <unistd.h>
#include <stdio.h>

int double_redirection_left(msh_t *minish, char *to_compare)
{
    int pipe_fd[2]; char *line = NULL; size_t len = 0;
    minish->tab_command = remake_tab(minish->tab_command, "<");
    if (minish->tab_command[0] == NULL) {
        write(2, "Invalid null command.\n", 22);
        return -1;
    }
    char *to_concat = my_strdup(to_compare);
    char *back_slash = my_strdup("\n");
    if (pipe(pipe_fd) == -1)
        return -1;
    write(1,"? ",2);
    char *new_to_compare = strcat_dup(to_concat, back_slash);
    getline(&line, &len, stdin);
    while (my_strcmp(new_to_compare, line) != 0) {
        write(1, "? ", 2);
        my_putstr_choose(line, pipe_fd[1]);
        getline(&line, &len, stdin);
    }
    close(pipe_fd[1]);
    return pipe_fd[0];
}

int manage_redirection(msh_t *minish)
{
    if (error_redirection(minish->tab_command, 0) == ERROR_EPITECH) {
        minish->result = 1;
        return ERROR_EPITECH;
    }
    if (get_fd_redirect(minish) == ERROR_EPITECH) {
        minish->result = 1;
        return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}
