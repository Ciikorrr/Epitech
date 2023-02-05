/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** rush3
*/

void display(int x, int y, int rush)
{
    my_putstr("[rush1-");
    my_put_nbr(rush);
    my_putchar(']');
    my_putchar(' ');
    my_put_nbr(x);
    my_putchar(' ');
    my_put_nbr(y);
    my_putchar('\n');
}

void display_d(int x, int y)
{
    my_putstr("[rush1-3] ");
    my_put_nbr(x);
    my_putchar(' ');
    my_put_nbr(y);
    my_putstr(" || [rush1-4] ");
    my_put_nbr(x);
    my_putchar(' ');
    my_put_nbr(y);
    my_putstr(" || [rush1-5] ");
    my_put_nbr(x);
    my_putchar(' ');
    my_put_nbr(y);
    my_putchar('\n');
}
