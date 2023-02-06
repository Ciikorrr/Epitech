/*
** EPITECH PROJECT, 2022
** square_root
** File description:
** ouais
*/

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb)
{
    for (int i = 0; i <= nb; i = i + 1) {
        if (my_compute_power_rec(i, 2) == nb) {
            return (i);
        }
    }
    return (0);
}
