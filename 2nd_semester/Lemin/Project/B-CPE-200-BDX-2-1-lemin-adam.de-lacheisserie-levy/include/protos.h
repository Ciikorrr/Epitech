/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-myls-marius.marolleau
** File description:
** macros
*/
#include "struct_lemin.h"

#ifndef PROTOS_H_
    #define PROTOS_H_

char *my_strdup(char *src);
int length_tab(char **tab);
int check_error(lemin_t *anthill);
int my_strcmp(char const *s1, char const *s2);
char **fill_new_tab(char **old_tab, char **new_tab, char *name);
int add_name_node(lemin_t *anthill, char *name);
char **my_str_to_word_array_separator(char *str, char *separator);

#endif /* PROTOS_H_ */
