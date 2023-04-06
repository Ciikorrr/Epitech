/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdlib.h>
#include "protos.h"
#include "utils.h"

char *find_path(char **env, char *path, char *command)
{
    char **tab = NULL;
    char *env_path = my_strdup("PATH=");

    for (int i = 0; env[i] != NULL; i += 1) {
        if (my_strncmp(env_path, env[i], 5) == 0) {
            tab = my_str_to_word_array_separator(env[i], ":=");
            path = check_access(tab, path, command);
            free_tab(tab);
            free(env_path);
            return path;
        }
    }
    free(env_path);
    return NULL;
}
