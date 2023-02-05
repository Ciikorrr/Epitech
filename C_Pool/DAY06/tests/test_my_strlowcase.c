/*
** EPITECH PROJECT, 2022
** my_strloxcase;c
** File description:
** test
*/

#include <criterion/criterion.h>

char *my_strlowcase(char *str);

Test(my_strlowcase, low_case)
{
    char str = my_strlowcase("TEST");
    cr_assert_str_eq(res, "test");
}

Test(my_strlowcase2, low_case)
{
    char str = my_strlowcase("test");
    cr_assert_str_eq(res, "test");
}

Test(my_strlowcase3, low_case)
{
    char str = my_strlowcase("TeST");
    cr_assert_str_eq(res, "test");
}

