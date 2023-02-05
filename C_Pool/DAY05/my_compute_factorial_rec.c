/*
** EPITECH PROJECT, 2022
** my_compute_factorial_rec
** File description:
** factorial
*/

int my_compute_factorial_rec(int nb)
{
    int res = 1;
    if (nb < 0 || nb >= 13) {
        return (0);
    }
    if (nb == 0) {
        return (res);
    } else {
        res = nb * my_compute_factorial_rec((nb - 1));
    }
    return (res);
}
