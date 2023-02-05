/*
** EPITECH PROJECT, 2022
** my_compute_power_it
** File description:
** compute power
*/

int my_compute_power_it(int b, int p)
{
    int res = 1;
    if (p == 0) {
        return (res);
    }
    if (p < 0) {
        return (0);
    }
    while (p != 0) {
        res = res * b;
        p -= 1;
    }
    return (res);
}
