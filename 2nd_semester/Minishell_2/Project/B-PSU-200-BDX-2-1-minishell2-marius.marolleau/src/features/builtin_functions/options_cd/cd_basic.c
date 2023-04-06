/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdlib.h>
#include "cd.h"
#include "struct_mnishell.h"

void cd_basic(msh_t *minish)
{
    size_t size = 0;
    char *current = NULL;
    char *old_pwd = NULL;

    old_pwd = getcwd(current, size);
    if (chdir(minish->tab_command[1]) == -1) {
            minish->result = check_status_cd(minish->tab_command[1]);
            free(old_pwd);
            return;
    }
    current = getcwd(current, size);
    replace_new_pwd(current, minish);
    replace_old_pwd(old_pwd, minish);
    return;
}
