/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include "protos.h"
#include "linked_list.h"
#include "utils.h"

int get_index_env(char **env)
{
    for (int i = 0; env[i] != NULL; i += 1) {
        if (my_strncmp("OLDPWD=", env[i], 7) == 0) {
            return i;
        }
    }
    return -1;
}

int get_index_env_bis(list *env_list, char *arg)
{
    char * str = strcat_dup(my_strdup(arg), my_strdup("="));
    for (int i = 0; env_list != NULL; env_list = env_list->next) {
        if (my_strncmp(str, env_list->str, my_strlen(str)) == 0) {
            return i;
        }
        i += 1;
    }
    return -1;
}
