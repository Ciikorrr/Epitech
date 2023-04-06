/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "struct_mnishell.h"
#include "opt_builtin.h"
#include "protos.h"
#include "macros.h"
#include "utils.h"

void do_execution(msh_t *minish, int last)
{
    char *command = NULL;
    if ((command = check_cmd_exec(minish)) == NULL) {
        error_exe(minish->tab_command[0]);
        minish->result = 1;
        return;
    } else {
        minish->result = fork_function(minish, command, last);
    }
    return;
}

int last_cmd(msh_t *minish, list_command_t *tmp)
{
    minish->tab_command = tmp->tab;
    if (get_fd_redirect(minish) == ERROR_EPITECH) {
        minish->result = 1;
        return ERROR_EPITECH;
    }
    if (pipe(minish->pipe_fd) == -1) {
        minish->result = 1;
        return ERROR_EPITECH;
    }
    if (check_for_builtin(minish, minish->tab_command[0]) != ERROR_EPITECH) {
        return SUCCESS_EPITECH;
    } else {
        minish->do_read = 1;
        do_execution(minish, 1);
        free_tab(minish->tab_command);
    }
    return SUCCESS_EPITECH;
}

int do_command_pipe(msh_t *minish, int i)
{
    list_command_t *tmp = &minish->command[i];
    while (tmp->next != NULL) {
        minish->tab_command = tmp->tab;
        if (manage_redirection(minish) == ERROR_EPITECH)
            return ERROR_EPITECH;
        if (pipe(minish->pipe_fd) == -1) {
            minish->result = 1;
            return ERROR_EPITECH;
        }
        do_execution(minish, 0);
        free_tab(minish->tab_command);
        tmp = tmp->next;
    }
    if (last_cmd(minish, tmp) == ERROR_EPITECH)
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}

msh_t *do_command(char *str, msh_t *minish)
{
    if (parser(str, minish) == ERROR_EPITECH) {
        minish->result = 1;
        return minish;
    }
    for (int i = 0; i < minish->nb_command; i += 1) {
        minish->do_read = -1;
        minish->fd_output = -1;
        if (do_command_pipe(minish, i) == SUCCESS_EPITECH)
            read_fd(minish);
    }
    return minish;
}

char *check_cmd_exec(msh_t *minish)
{
    char *path_find = NULL;
    char *command = my_strdup(minish->tab_command[0]);
    if ((is_builtins(command)) != NULL) {
        return command;
    }
    if ((path_find = is_absolut(minish, command)) != NULL) {
        return path_find;
    }
    if ((path_find = is_path(minish, command)) != NULL)
        return path_find;
    free(command);
    free(path_find);
    return NULL;
}
