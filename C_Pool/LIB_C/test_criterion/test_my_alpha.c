/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** test_my_str_isnum
*/

#include <criterion/criterion.h>
int my_alpha(char c);

Test(my_alpha1, Test)
{
    char c = 'i'; 
    int res = my_alpha(c);
    cr_assert_eq(res, 1);
}

Test(my_alpha2, Test)
{
    char c = '5'; 
    int res = my_alpha(c);
    cr_assert_eq(res, 0);
}

Test(my_alpha3, Test)
{
    char c = ' '; 
    int res = my_alpha(c);
    cr_assert_eq(res, 0);
}

Test(my_alpha4, Tests)
{
    char c = 'A'; 
    int res = my_alpha(c);
    cr_assert_eq(res, 1);
}