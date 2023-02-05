/*
** EPITECH PROJECT, 2022
** test_my_revstr
** File description:
** test 
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void disp_stdarg(char *s, ...);

Test(disp_stdarg1, basic, .init=cr_redirect_stdout)
{
    disp_stdarg("csi", "X","marius","18");
    cr_assert_stderr_eq_str("X\nmarius\n18\n", "");
}
