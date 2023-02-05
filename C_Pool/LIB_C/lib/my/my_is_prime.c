/*
** EPITECH PROJECT, 2022
** my_is_prime
** File description:
** number is prime
*/

int my_is_prime(int nb)
{
    if (nb <= 0 || nb == 1) {
        return (0);
    }
    int i = 1;
    int compteur = 0;
    for (i = 1; i < nb; i += 1) {
        if (nb % i == 0) {
            compteur = compteur + 1;
        }
    }
    if (compteur >= 2) {
        return (0);
    } else {
        return (1);
    }
}
