/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdio.h>
#include "cd.h"

int cd_moins(char **env, msh_t *minish)
{
    size_t size = 0;
    char *current_pwd = NULL;
    char *old_pwd = get_old_pwd(env);
    if (old_pwd == NULL)
        return 1;
    current_pwd = getcwd(current_pwd, size);
    if (chdir(old_pwd) == -1) {
        perror(old_pwd);
        return 1;
    }
    if (replace_old_pwd(current_pwd, minish) == 1 ||
    replace_new_pwd(old_pwd, minish) == 1) {
        return 1;
    }
    return 0;
}
