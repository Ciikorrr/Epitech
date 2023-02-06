/*
** EPITECH PROJECT, 2022
** my_isneg
** File description:
** negative control
*/

#include <unistd.h>

void    my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
        my_putchar('\n');
    } else {
        my_putchar('P');
        my_putchar('\n');
    }
}
