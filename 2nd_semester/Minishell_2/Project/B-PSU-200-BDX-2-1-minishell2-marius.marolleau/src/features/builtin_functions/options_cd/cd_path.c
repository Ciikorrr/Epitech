/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <unistd.h>
#include <stdio.h>
#include "protos.h"
#include "utils.h"
#include "cd.h"

int cd_with_path(char *new_path, char **env, char **tab, msh_t *minish)
{
    size_t len = 0;
    char *old_pwd = NULL;

    new_path = get_path(env);
    if (new_path == NULL)
        return 1;
    char *path = my_strdup(tab[1] + 1);
    char *str = strcat_dup(new_path, path);
    old_pwd = getcwd(old_pwd, len);
    if (chdir(str) == -1) {
        perror(str);
        return 1;
    }
    if (replace_old_pwd(old_pwd, minish) == 1 ||
    replace_new_pwd(str, minish) == 1)
        return 1;
    return 0;
}
