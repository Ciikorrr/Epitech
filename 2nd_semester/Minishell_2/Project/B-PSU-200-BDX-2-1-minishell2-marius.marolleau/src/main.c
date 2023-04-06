/*
** EPITECH PROJECT, 2022
** Start_projet
** File description:
** main
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <dirent.h>
#include "protos.h"
#include "struct_mnishell.h"
#include "macros.h"

int main(int argc, char **argv, char **env)
{
    (void)argv;
    if (env == NULL)
        return ERROR_EPITECH;
    if (get_error(argc, env) == ERROR_EPITECH)
        return ERROR_EPITECH;
    msh_t *minish = malloc(sizeof(msh_t));
    if (minish == NULL)
        return ERROR_EPITECH;
    minish->result = 0;
    minish->env = env;
    minish->exit = 0;
    minish->fd = 0;
    minish->do_read = -1;
    minish->fd_output = -1;
    minish->fd_input = 0;
    minish = mysh(minish);
    if (minish->error_code != 0)
        return minish->error_code;
    return minish->result;
}
