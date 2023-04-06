/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdlib.h>
#include <unistd.h>
#include "struct_mnishell.h"
#include "macros.h"
#include "protos.h"
#include "utils.h"

char *concat_command(char **command2, char **new_path, char **test,
char **command)
{
    char *path = NULL;
    *new_path = strcat_dup(my_strdup(*command2), my_strdup(*test));
    path = strcat_dup(my_strdup(*new_path), my_strdup(*command));
    return path;
}

int access_and_free(char **path, char **new_path, char **test, char **command2)
{
    if (access(*path, F_OK) == 0) {
        free(*new_path);
        free(*test);
        free(*command2);
        return 0;
    }
    return 1;
}

char *check_access(char **tab, char *path, char *command)
{
    char *test = my_strdup("/");
    char *command2 = NULL;
    char *new_path = NULL;

    for (int i = 1; tab[i] != NULL; i += 1) {
        command2 = my_strdup(tab[i]);
        path = concat_command(&command2, &new_path, &test, &command);
        if (access_and_free(&path, &new_path, &test, &command) != 0) {
            free(new_path);
            free(path);
            free(command2);
        } else {
            return path;
        }
    }
    free(test);
    return NULL;
}
