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

int my_putnbr_base(int nbr, char const *base, int *c, int precision)
{
    int i = 0;
    int temp = 0;
    int fact = my_strlen(base);
    if (nbr <= 0) {
        for (int i = 0; i < precision; i += 1) {
            my_putchar('0');
            *c += 1;
        }
        return (*c);
    } else {
        *c = *c + 1;
        temp = nbr % fact;
        nbr = nbr / fact;
        my_putnbr_base(nbr, base, c, precision - 1);
        my_putchar(base[temp]);
    }
    return (*c);
}
