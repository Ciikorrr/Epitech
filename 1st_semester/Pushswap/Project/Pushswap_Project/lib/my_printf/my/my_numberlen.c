/*
** EPITECH PROJECT, 2022
** numberlen
** File description:
** ouais
*/

int my_numberlen(int nb)
{
    int count = 1;
    if (nb < 0) {
        nb = nb * -1;
        count += 1;
    }
    if (nb < 10)
        return count;
    while (nb > 9) {
        nb = nb / 10;
        count += 1;
    }
    return count;
}
