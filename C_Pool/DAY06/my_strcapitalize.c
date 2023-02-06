/*
** EPITECH PROJECT, 2022
** my_strcapitalize
** File description:
** capitalize
*/
#include <stdio.h>
char *my_strlowcase(char *str);

int my_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' &&
        c <= 'Z')) {
        return 1;
    }
    return 0;
}

char *my_strcapitalize(char *str)
{
    int i = 1;

    my_strlowcase(str);
    if (my_alpha(str[0]) == 1) {
        str[0] = str[0] - 32;
    }
    while (str[i] != '\0') {
        if ((my_alpha(str[i]) == 1 && my_alpha(str[i - 1]) == 0)) {
            str[i] = str[i] - 32;
            i += 1;
        }
        i += 1;
    }
    return str;
}

