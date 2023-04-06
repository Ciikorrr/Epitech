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
#include "utils.h"

void search_variable(char **env, char *str)
{
    char *copy = my_strdup(str);
    char *egal = my_strdup("=");
    char *variable = strcat_dup(str, egal);
    for (int i = 0; env[i] != NULL; i += 1) {
        if (my_strncmp(variable, env[i], my_strlen(variable)) == 0) {
            printf("\033[32;01m%s\033[00m\n", env[i]);
            return;
        }
    }
    printf("\33[31;01m%s\033[00m", copy);
    printf("\033[31;01m: No environnement variable with this name.\033[00m\n");
    free(copy);
    return;

}

void fct_env(msh_t *minish)
{
    if (length_tab(minish->tab_command) >= 2) {
        for (int i = 1; minish->tab_command[i]; i += 1) {
            search_variable(minish->env, minish->tab_command[i]);
        }
    }
    if (length_tab(minish->tab_command) == 1){
        for (int i = 0; minish->env[i] != NULL; i += 1) {
            my_putstr(minish->env[i]);
            my_putstr("\n");
            minish->result = 0;
        }
    }
    return;
}
