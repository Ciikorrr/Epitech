/*
** EPITECH PROJECT, 2022
** my_is_prime
** File description:
** ouais
*/

int my_is_prime(int nb)
{
    if (nb <= 0 || nb == 1)
        return (0);
    for (int i = 2; i <= (nb / 2); i = i + 1) {
        if (nb % i == 0) {
            return (0);
        }
    }
    return (1);
}
