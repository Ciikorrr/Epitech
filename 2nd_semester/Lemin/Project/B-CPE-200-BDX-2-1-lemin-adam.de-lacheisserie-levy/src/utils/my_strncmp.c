/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-adam.de-lacheisserie-levy
** File description:
** my_strncmp
*/

#include <unistd.h>

int my_strncmp(char *one, char *two, int n)
{
    int i = 0;
    if (one == NULL || two == NULL)
        return 1;
    for (; i < n; i += 1) {
        if (one[i] != two[i])
            return 1;
    }
    return 0;
}
