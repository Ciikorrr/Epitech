/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** find prime sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (nb < 0) {
        return (2);
    }
    int i = 0;
    for (i = nb;i <= 2147483646; i += 1) {
        if (my_is_prime(i) == 1) {
            return (i);
        }
    }
}
