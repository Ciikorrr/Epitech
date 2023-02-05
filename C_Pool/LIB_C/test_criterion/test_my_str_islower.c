/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** test_my_str_isnum
*/

#include <criterion/criterion.h>
int my_str_islower(char *str);

Test(my_str_islower1, Test)
{
    char str[] = "xmzpsxps"; 
    int res = my_str_islower(str);
    cr_assert_eq(res, 1);
}

Test(my_str_islower2, Test)
{
    char str[] = "  gjfpzm"; 
    int res = my_str_islower(str);
    cr_assert_eq(res, 0);
}

Test(my_str_isupper3, Test)
{
    char str[] = "JBGIifjr"; 
    int res = my_str_islower(str);
    cr_assert_eq(res, 0);
}

Test(my_str_islower4, Tests)
{
    char str[] = ""; 
    int res = my_str_islower(str);
    cr_assert_eq(res, 1);
}