/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** ouais
*/

#include <stdio.h>
#include <string.h>
int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && i < n) {
        if (s1[i] < s2[i]) {
            return s1[i] - s2[i];
        }
        if (s1[i] > s2[i]) {
            return s2[i] - s1[i];
        }
        i += 1;
    }
    return 0;
}
