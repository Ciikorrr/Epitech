/*
** EPITECH PROJECT, 2022
** my_lenstr
** File description:
** ouais
*/

#include <stdlib.h>

void my_putchar(char c);

int my_strlen(char const *str)
{
    if (str == NULL)
        return -1;
    int i = 0;
    while (str[i] != '\0')
        i = i + 1;
    return (i);
}
