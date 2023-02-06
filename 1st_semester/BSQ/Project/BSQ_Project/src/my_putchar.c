/*
** EPITECH PROJECT, 2022
** my_programm
** File description:
** programm
*/
#include <unistd.h>
char my_putchar(char c)
{
    write(1, &c, 1);
}
