/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** test_sum_numbers
*/

#include <criterion/criterion.h>
int sum_numbers(int n, ...);

Test(sum_numbers1, test)
{
    int a = 2;
    int b = 10;
    int c = 10;
    int res = sum_numbers(a, b, c);
    cr_assert_eq(res, 20);
}

Test(sum_numbers2, test)
{
    int a = 2;
    int b = -5;
    int c = 10;
    int res = sum_numbers(a, b, c);
    cr_assert_eq(res, 5);
}

Test(sum_numbers3, test)
{
    int a = 1;
    int b = 80;
    int res = sum_numbers(a, b);
    cr_assert_eq(res, 80);
}

Test(sum_numbers4, test)
{
    int a = 1;
    int res = sum_numbers(a);
    cr_assert_eq(res, 0);
}