/*
** EPITECH PROJECT, 2022
** float
** File description:
** ouais
*/

#include <stdio.h>
int my_put_nbr(int i);
void my_putchar(char c);

int my_put_float_nbr(double n, int precision, int count)
{
    int nb = n;
    double temp = n - nb;
    count += my_put_nbr(nb);
    if (precision <= 0)
        return 0;
    my_putchar(',');
    count += 1;
    int i = 0;
    int multi = 10;
    while (i < (precision - 1)) {
        multi = multi * 10;
        i += 1;
    }
    int res = temp * multi;
    count += my_put_nbr(res);
    return count;
}
