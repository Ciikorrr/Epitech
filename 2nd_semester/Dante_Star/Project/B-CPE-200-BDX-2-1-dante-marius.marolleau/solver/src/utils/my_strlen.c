/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>

int my_strlen(char const *str)
{
    if (str == NULL)
        return -1;
    int len = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        len += 1;
    }
    return len;
}
