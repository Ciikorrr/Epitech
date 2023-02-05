/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** test_my_strlowcase
*/


#include <criterion/criterion.h>

char *my_strlowcase(char *str);

Test(my_strlowcase, low_case)
{
    char str[] = "TEST"; 
    char *res = my_strlowcase(str);
    cr_assert_str_eq(res, "test");
}

Test(my_strlowcase2, low_case)
{
    char str[] = "TEST"; 
    char *res = my_strlowcase(str);
    cr_assert_str_eq(res, "test");
}

Test(my_strlowcase3, low_case)
{
    char str[] = "TEST"; 
    char *res = my_strlowcase(str);
    cr_assert_str_eq(res, "test");
}