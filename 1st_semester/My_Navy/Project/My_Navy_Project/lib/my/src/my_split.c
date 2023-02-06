/*
** EPITECH PROJECT, 2022
** split
** File description:
** ouais
*/

#include <stdlib.h>
#include <stdio.h>

int find_n(char *str, char occurrence);
int my_getnbr(char *str);

int get_len(char *str, char separator, int *index)
{
    int c = 0;
    for (int i = *index; str[i] != '\0'; i += 1) {
        if (str[i] == separator) {
            *index = i + 1;
            return c;
        }
        c += 1;
    }
    return c;
}

char *my_strncpyn(char *result, char *str, int start, char separator)
{
    int i = 0;
    while (str[start] != separator)
        result[i++] = str[start++];
    return result;
}

char **my_split(char *str, char separator)
{
    int n_separator = 0;
    int index = 0;
    int len = 0;
    int temp = 0;
    n_separator = find_n(str, separator);
    char **result = malloc(sizeof(char *) * (n_separator + 1));
    result[n_separator] = NULL;

    for (int i = 0; i < n_separator; i += 1) {
        len = get_len(str, separator, &index);
        result[i] = malloc(sizeof(char) * (len + 1));
        result[i][len] = '\0';
        my_strncpyn(result[i], str, temp, separator);
        temp = index;
    }
    return result;
}
