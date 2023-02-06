/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../libday05.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_compute_factorial_it, test)
{
    cr_assert_eq(my_compute_factorial_it(3), 6);
}

Test (my_compute_factorial_rec, test)
{
    cr_assert_eq(my_compute_factorial_rec(4), 24);
}

Test (my_compute_power_it, test)
{
    cr_assert_eq(my_compute_power_it(2, 3), 8);
}

Test (my_compute_power_rec, test)
{
    cr_assert_eq(my_compute_power_rec(10, 3), 1000);
}

Test (my_find_prime_sup, test)
{
    cr_assert_eq(my_find_prime_sup(10), 11);
}

Test (my_is_prime, test)
{
    cr_assert_eq(my_is_prime(10), 0);
}

Test (my_is_prime_bis, test)
{
    cr_assert_eq(my_is_prime(7), 1);
}
