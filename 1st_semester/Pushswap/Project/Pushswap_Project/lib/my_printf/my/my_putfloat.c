/*
** EPITECH PROJECT, 2022
** my_putfloat
** File description:
** float
*/

int my_put_nbr(int nb);
void my_putchar(char c);

void my_putfloat(float nb)
{
    int n = 0;
    n = nb * 100;
    my_put_nbr(n / 100);
    my_putchar(',');
    my_put_nbr((n / 10) % 10);
    my_put_nbr(n % 10);
}
