/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils.h"

Test (my_putchar, test1, .init = redirect_all_std) {
    my_putchar('A');
    cr_assert_stdout_eq_str("A");
}
