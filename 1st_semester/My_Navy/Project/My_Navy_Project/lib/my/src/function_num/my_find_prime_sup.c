/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** ouais
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (nb <= 0 || nb == 1)
        return (2);
    for (int i = nb; i < (nb * nb); i = i + 1) {
        if (my_is_prime(i) == 1 && i >= nb) {
            return (i);
        }
    }
}
