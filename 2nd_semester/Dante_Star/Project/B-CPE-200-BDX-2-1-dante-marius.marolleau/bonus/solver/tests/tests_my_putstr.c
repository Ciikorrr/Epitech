/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_putstr_true, test1, .init = redirect_all_std) {
    int result = my_putstr("HELLO");
    cr_assert_eq(result, 0);
    cr_assert_stdout_eq_str("HELLO");
}

Test (my_putstr_false, test1, .init = redirect_all_std) {
    int result = my_putstr(NULL);
    cr_assert_eq(result, -1);
}
