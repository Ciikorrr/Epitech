/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdlib.h>
#include "linked_list.h"
#include "protos.h"
#include "utils.h"

char **list_to_tab(list *env_list)
{
    int i = 0;
    int len = length_list(env_list);
    char **tab = malloc(sizeof(char *) * (len + 1));
    tab[len] = NULL;
    while (env_list != NULL) {
        tab[i] = my_strdup(env_list->str);
        env_list = env_list->next;
        i += 1;
    }
    return tab;
}
