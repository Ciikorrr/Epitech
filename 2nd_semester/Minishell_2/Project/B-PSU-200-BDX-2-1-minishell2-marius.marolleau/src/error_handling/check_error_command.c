/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stdbool.h>
#include "protos.h"
#include "macros.h"
#include "utils.h"
#include <signal.h>

int get_error(int argc, char **env)
{
    if (env == NULL)
        return ERROR_EPITECH;
    if (argc != 1)
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}

void error_exe(char *argv)
{
    my_putstr_choose(argv, 2);
    my_putstr_choose(": Command not found.\n", 2);
}

int check_status(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGFPE) {
            my_putstr_choose("Floating exception", 2);
        } else {
            my_putstr_choose(strsignal(WTERMSIG(status)), 2);
        }
        if (WCOREDUMP(status)) {
            my_putstr_choose(" (core dumped)", 2);
        }
        my_putstr_choose("\n", 2);
        return status;
    }
    if (WIFEXITED(status)) {
        return WEXITSTATUS(status);
    }
    if (WIFSTOPPED(status)) {
        return WSTOPSIG(status);
    }
    return status;
}

int check_errno(char *command)
{
    if (errno == 13) {
        my_putstr_choose(command, 2);
        my_putstr_choose(": Permission denied.\n", 2);
        return 1;
    }
    if (errno == 8) {
        my_putstr_choose(command, 2);
        my_putstr_choose(": Exec format error. Wrong Architecture.\n", 2);
        return 126;
    } else {
        perror(command);
    }
    return 1;
}
