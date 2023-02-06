/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** ouais
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    int bytes = my_strlen(str);
    write(1, str, bytes);
    return (0);
}
