/*
** EPITECH PROJECT, 2022
** my_strcapitalize
** File description:
** ouais
*/

#include <stdio.h>

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    if (str[0] >= 'a' || str[0] <= 'z')
        str[0] = str[0] - 32;
    for (int i = 1; str[i] != '\0'; i = i + 1) {
        if ((str[i] == '-' || str[i] == ' ' || str[i] == '+')
            && (str[i + 1] >= 'a' && str[i + 1] <= 'z'))
            str[i + 1] = str[i + 1] - 32;
    }
    return (str);
}
