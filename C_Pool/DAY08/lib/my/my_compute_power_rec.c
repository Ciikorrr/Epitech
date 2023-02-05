/*
** EPITECH PROJECT, 2022
** my comput factorial rec
** File description:
** recurcive
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0) {
        return (1);
    }
    if (p < 0) {
        return (0);
    }
    int res = nb * my_compute_power_rec(nb, p - 1);
    return res;

}
