/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** put number
*/

void my_putchar(char c);

void my_putstr(char const *str);

int my_put_unsignednbr(unsigned int nb)
{
    int count = 0;
    if (nb == -2147483647) {
        my_putstr("-2147483648");
        count += 11;
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        count += 1;
        nb = nb * -1;
    }
    if (nb > 9) {
        count += my_put_unsignednbr(nb / 10);
        my_putchar(nb % 10 + 48);
        count += 1;
    } else {
        my_putchar(nb + 48);
        count += 1;
    }
    return count;
}
