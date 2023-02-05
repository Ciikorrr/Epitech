/*
** EPITECH PROJECT, 2022
** my_strcapitalize
** File description:
** capitalize
*/

#include "my.h"
#include <stdio.h>

int my_alpha(char c)
{
    if ((c >= 'a' && c <= 'z' || c >= 'A' &&
        c <= 'Z')) {
        return 1;
    }
    return 0;
}

char *my_strcapitalize(char *str)
{   
    int space = 0;
    int i = 1;
    my_strlowcase(str);
    if (my_alpha(str[0]) == 1) {
        str[0] = str[0] - 32;
    }
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            space += 1;
            i += 1;
        }
        if (my_alpha(str[i]) == 1 && space > 0) {
            str[i] -= 32;
            i += 1;
            space = 0;
        }
        i += 1;
    }
    return str;
}
