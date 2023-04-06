/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdio.h>
#include "cd.h"

int simple_cd(char **env, msh_t *minish)
{
    char *new_pwd = NULL;
    size_t len = 0;
    char *old_pwd = NULL;
    old_pwd = getcwd(old_pwd, len);
    new_pwd = get_path(env);
    if (new_pwd == NULL)
        return 1;
    if (chdir(new_pwd) == -1) {
        perror(new_pwd);
        return 1;
    }
    if (replace_old_pwd(old_pwd, minish) == 1
    || replace_new_pwd(new_pwd, minish) == 1) {
        return 1;
    }
    return 0;
}
