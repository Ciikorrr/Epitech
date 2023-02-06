/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}
