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
    printf("\33[31;01m%s: Command not found.\33[00m\n", argv);
}

int check_status(int status, char *command)
{
    (void)command;
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGFPE) {
            printf("\33[31;01mFloating exception\33[00m");
        } else {
            my_putstr_choose(strsignal(WTERMSIG(status)), 2);
        }
        if (WCOREDUMP(status)) {
            printf("\33[31;01m (core dumped)\33[00m");
        }
        my_putstr_choose("\n", 1);
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
        printf("\33[31;01m%s: Permission denied.\33[00m\n", command);
        return 1;
    }
    if (errno == 8) {
        printf("\33[31;01m%s: Exec format error. Wrong Architecture.\33[00\n", command);
        return 126;
    } else {
        perror(command);
    }
    return 1;
}
