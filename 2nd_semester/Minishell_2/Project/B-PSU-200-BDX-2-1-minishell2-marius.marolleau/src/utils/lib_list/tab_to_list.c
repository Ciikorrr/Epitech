/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdlib.h>
#include "linked_list.h"

list *fill_env_list(char **env, list *env_list)
{
    for (int i = 1; env[i] != NULL; i += 1) {
        env_list = add_elem_back(env_list, env[i]);
    }
    return 0;
}
