/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct_mnishell.h"
#include "protos.h"
#include "utils.h"

char *fill_oldpwd(char **env, int i)
{
    int len = 0;
    int j = 0;
    char *path = NULL;
    for (; env[i][j] != '='; j += 1);
    j += 1;
    len = my_strlen_index(env[i], j);
    path = malloc(sizeof(char) * (len + 1));
    for (int a = 0; env[i][j] != '\0'; j += 1) {
        path[a] = env[i][j];
        a += 1;
    }
    path[len] = '\0';
    return path;
}

char *get_old_pwd(char **env)
{
    char *path = NULL;
    int i = 0;
    for (; env[i] != NULL; i += 1) {
        if (my_strncmp("OLDPWD=", env[i], 7) == 0) {
            path = my_strdup(env[i]);
            path = fill_oldpwd(env, i);
            return path;
        }
    }
    my_putstr_choose(": No such file or directory.\n", 2);
    return NULL;
}
