/*
** EPITECH PROJECT, 2022
** my_putnbr_base
** File description:
** ouais
*/

#include <stdio.h>

int my_put_nbr(int nb);
void my_putchar(char c);
int my_strlen(char const *str);

int my_putnbr_base(int nbr, char const *base)
{
    int temp = 0;
    int fact = my_strlen(base);
    if (nbr <= 0) {
        return (0);
    } else {
        temp = nbr % fact;
        nbr = nbr / fact;
        my_putnbr_base(nbr, base);
        my_putchar(base[temp]);
    }
    return (0);
}
