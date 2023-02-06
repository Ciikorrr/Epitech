/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** ouais
*/

#include <stdio.h>
#include <string.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i = i + 1) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i = i + 1;
    }
    return (0);
}
