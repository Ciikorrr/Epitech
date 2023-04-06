/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/protos.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (test1, test, .init = redirect_all_std)
{
    printf("hello\n");
    fflush(stdout);
    cr_assert_stdout_eq_str("hello\n");
}
