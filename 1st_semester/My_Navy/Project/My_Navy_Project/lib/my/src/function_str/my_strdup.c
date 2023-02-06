/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** ouais
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
char *my_strdup(char const *str)
{
    int len = 0;
    char *new_str = NULL;
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        len = len + 1;
    }
    new_str = malloc(sizeof(char) * len);
    for (int i = 0; i < len; i = i + 1) {
        new_str[i] = str[i];
    }
    return (new_str);
}
