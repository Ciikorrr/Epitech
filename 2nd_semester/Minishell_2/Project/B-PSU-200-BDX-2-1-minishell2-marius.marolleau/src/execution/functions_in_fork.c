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
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include "struct_mnishell.h"
#include "protos.h"
#include "macros.h"
#include "utils.h"

void action_on_fd(msh_t *minish, int last)
{
    close(minish->pipe_fd[0]);
    if (last != 1) {
        dup2(minish->pipe_fd[1], STDOUT_FILENO);
    } else {
        dup2(minish->fd_output, STDOUT_FILENO);
    }
    dup2(minish->fd_input, STDIN_FILENO);
    return;
}

int parent_fork(int res, int status, msh_t *minish, int last)
{
    close(minish->pipe_fd[1]);
    minish->fd_input = minish->pipe_fd[0];
    if (last == 1) {
        waitpid(res, &status, WUNTRACED);
        status = check_status(status);
        if (status != 0)
            minish->error_code = status;
    } else {
        waitpid(res, &status, WUNTRACED | WNOHANG);
    }
    return status;
}

int child_fork(char *command, int status, msh_t *minish, int last)
{
    if (check_for_builtin(minish, command) != ERROR_EPITECH) {
        exit(0);
    } else {
        action_on_fd(minish, last);
        execve(command, minish->tab_command, minish->env);
        minish->do_read = 1;
        if (errno != 0) {
            minish->result = 1;
            status = check_errno(command);
        }
        exit(status);
    }
    return status;
}

int fork_function(msh_t *minish, char *command, int last)
{
    int status = 0;
    int res = fork();
    if (res == 0) {
        child_fork(command, status, minish, last);
    } else {
        return parent_fork(res,status, minish, last);
    }
    return ERROR_EPITECH;
}
