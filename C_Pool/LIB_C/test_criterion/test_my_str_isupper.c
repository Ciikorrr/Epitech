/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** test_my_str_isnum
*/

#include <criterion/criterion.h>

int my_str_isupper(char *str);

Test(my_str_isupper1, Test)
{
    char str[] = "FJVFJVO"; 
    int res = my_str_isupper(str);
    cr_assert_eq(res, 1);
}

Test(my_str_isupper2, Test)
{
    char str[] = "  VJFVJFOK"; 
    int res = my_str_isupper(str);
    cr_assert_eq(res, 0);
}

Test(my_str_isupper3, Test)
{
    char str[] = "JBGIifjr"; 
    int res = my_str_isupper(str);
    cr_assert_eq(res, 0);
}

Test(my_str_isupper4, Tests)
{
    char str[] = ""; 
    int res = my_str_isupper(str);
    cr_assert_eq(res, 1);
}