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
#include "tableau.h"
#include "struct_mnishell.h"
#include "opt_builtin.h"
#include "protos.h"
#include "macros.h"
#include "utils.h"

int check_for_builtin(msh_t *minish)
{
    for (int i = 0; i < TAB_SIZE; i += 1) {
        if (my_strcmp(minish->tab_command[0], tab_builtin[i].opt) == 0) {
            tab_builtin[i].function(minish);
            return minish->result;
        }
    }
    return ERROR_EPITECH;
}

int fork_function(char **tab, char **env, char *command)
{
    int status = 0;
    int res = fork();
    if (res != 0) {
        waitpid(res, &status, WUNTRACED);
        return check_status(status, command);
    } else {
        execve(command, tab, env);
        if (errno != 0)
            status = check_errno(command);
        exit(status);
    }
    return status;
}

char *check_access(char **tab, char *path, char *command)
{
    char *test = my_strdup("/");
    char *command2 = NULL;
    char *new_path = NULL;

    for (int i = 1; tab[i] != NULL; i += 1) {
        command2 = my_strdup(tab[i]);
        new_path = strcat_dup(my_strdup(command2), my_strdup(test));
        path = strcat_dup(my_strdup(new_path), my_strdup(command));
        if (access(path, F_OK) == 0) {
            free(new_path);
            free(test);
            free(command2);
            return path;
        }
        free(new_path);
        free(path);
        free(command2);
    }
    free(test);
    return NULL;
}

int do_exec(msh_t *minish)
{
    char *error = my_strdup(minish->tab_command[0]);
    char *command = my_strdup(minish->tab_command[0]);
    char *path_find = NULL;
    if (check_absolut_path(minish) == SUCCESS_EPITECH) {
    } else {
        error_exe(error);
        minish->result = 1;
    }
    free(path_find);
    free(command);
    free(error);
    return minish->result;
}

msh_t *do_command(char *str, msh_t *minish)
{
    minish->tab_command = my_str_to_word_array_separator(str, " \t\n");
    if (minish->tab_command[0] == NULL) {
    } else if ((minish->result = check_for_builtin(minish))
    != ERROR_EPITECH){
        return minish;
    } else {
        minish->result = do_exec(minish);
    }
    free_tab(minish->tab_command);
    return minish;
}
