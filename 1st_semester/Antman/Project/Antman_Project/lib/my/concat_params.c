/*
** EPITECH PROJECT, 2022
** concat_params
** File description:
** ouais
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char *my_strcat(char *dest, char *src);

int arraylen(int n, char **str)
{
    int len = 0;
    for (int i = 0; i < n; i = i + 1) {
        for (int j = 0; str[i][j] != '\0'; j = j + 1) {
            len = len + 1;
        }
    }
    return (len);
}

char *concat_params(int argc, char **argv)
{
    char *str = NULL;
    int len = (arraylen(argc, argv)) + (argc - 1);
    str = malloc(sizeof(char) * len);
    for (int i = 0; i < argc; i = i + 1) {
        str = my_strcat(str, argv[i]);
        if (i != (argc - 1)) {
            str = my_strcat(str, "\n");
        } else {
            str = my_strcat(str, "\0");
        }
    }
    return (str);
}
