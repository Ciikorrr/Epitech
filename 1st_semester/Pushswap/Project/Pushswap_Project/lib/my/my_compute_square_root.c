/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** square root
*/

int my_compute_power_rec(int nb, int i);

int my_compute_square_root(int nb)
{
    int i = 0;
    for (i; i <= nb; i += 1) {
        if (my_compute_power_rec(i, 2) == nb) {
            return (i);
        }
    }
    return (0);
}
