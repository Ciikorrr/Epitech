/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** test_my_str_isnum
*/

#include <criterion/criterion.h>
int my_str_isnum(char *str);

Test(my_str_isnum1, Test)
{
    char str[] = "1522"; 
    int res = my_str_isnum(str);
    cr_assert_eq(res, 1);
}

Test(my_str_isnum2, Test)
{
    char str[] = "621fv"; 
    int res = my_str_isnum(str);
    cr_assert_eq(res, 0);
}

Test(my_str_isnum3, Test)
{
    char str[] = "   __#2"; 
    int res = my_str_isnum(str);
    cr_assert_eq(res, 0);
}

Test(my_str_isnum4, Test)
{
    char str[] = "   1 5  22"; 
    int res = my_str_isnum(str);
    cr_assert_eq(res, 0);
}