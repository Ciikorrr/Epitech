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
#include "utils.h"
#include "protos.h"

char *check_for_path(char *command)
{
    if (access(command, F_OK) != 0) {
        return NULL;
    }
    return command;
}

void fill_output(int fd, int output)
{
    char buffer;
    while ((read(fd, &buffer, 1)) > 0) {
        write(output, &buffer, 1);
    }
    return;
}

void read_fd(msh_t *minish)
{
    close(minish->pipe_fd[1]);
    if (minish->do_read == 1) {
        if (minish->fd_output != -1) {
            fill_output(minish->pipe_fd[0], minish->fd_output);
            close(minish->fd_output);
        } else {
            fill_output(minish->pipe_fd[0], 1);
        }
    }
    return;
}
