/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "protos.h"
#include "opt_builtin.h"
#include "utils.h"

int home_exist(char **env)
{
    for (int env_index = 0; env[env_index] != NULL; env_index += 1) {
        if (my_strncmp("HOME=", env[env_index], 5) == 0) {
            return env_index;
        }
    }
    return -1;
}

char *fill_new_path(int env_index, int index, int len, char **env)
{
    int i = 0;
    char *new_path = malloc(sizeof(char) * (len +1));

    for (; i < len; i += 1) {
        new_path[i] = env[env_index][index];
        index += 1;
    }
    new_path[len] = '\0';
    return new_path;
}

char *get_path(char **env)
{
    int index = 0;
    int len = 0;
    int tmp = 0;
    char *new_path = NULL;
    int env_index = home_exist(env);

    if (env_index == -1) {
        printf("\033[31;01m: No home directory.\033[00m\n");
        return NULL;
    }
    while (env[env_index][index] != '=')
        index += 1;
    tmp = index + 1;
    for (; env[env_index][tmp] != '\0'; tmp += 1)
        len += 1;
    index += 1;
    new_path = fill_new_path(env_index, index, len, env);
    return new_path;
}

int replace_old_pwd(char *old_pwd, msh_t *minish)
{
    minish->tab_command = malloc(sizeof(char *) * 4);
    minish->tab_command[0] = my_strdup("setenv");
    minish->tab_command[1] = my_strdup("OLDPWD");
    minish->tab_command[2] = my_strdup(old_pwd);
    minish->tab_command[3] = NULL;
    fct_setenv(minish);
    free(old_pwd);
    return 0;
}

int replace_new_pwd(char *new_pwd, msh_t *minish)
{
    free_tab(minish->tab_command);
    minish->tab_command = malloc(sizeof(char *) * 4);
    minish->tab_command[0] = my_strdup("setenv");
    minish->tab_command[1] = my_strdup("PWD");
    minish->tab_command[2] = my_strdup(new_pwd);
    minish->tab_command[3] = NULL;
    fct_setenv(minish);
    free(new_pwd);
    return 0;
}
