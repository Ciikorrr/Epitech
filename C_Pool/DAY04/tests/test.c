/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../libday04.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_putstr, test, .init = redirect_all_std)
{
    my_putstr("Hello World !");
    cr_assert_stdout_eq_str("Hello World !");
}
Test (my_strlen, test)
{
    int result = my_strlen("Hello guys");
    cr_assert_eq(result, 10);
}

Test (my_evil_str, test)
{
    cr_assert_str_eq(my_evil_str("hello"), "");
}

Test (my_getnbr, test)
{
    cr_assert_eq(my_getnbr("fdvds42f  sd"), 42);
}
