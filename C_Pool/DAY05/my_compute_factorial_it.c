/*
** EPITECH PROJECT, 2022
** my_cumpute_factorial_it
** File description:
** iteratif
*/

int my_compute_factorial_it(int nb)
{
    int res = 1;
    if (nb == 0) {
        return (1);
    }
    if (nb < 0 || nb >= 13) {
        return (0);
    }
    while (nb > 0) {
        res = res * nb;
        nb = nb - 1;
    }
    return (res);
}
