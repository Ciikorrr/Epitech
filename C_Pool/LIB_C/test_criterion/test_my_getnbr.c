/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** test_my_str_isnum
*/

#include <criterion/criterion.h>
int my_getnbr(char *str);

Test(my_getnbr1, Test)
{
    char str[] = "1564851"; 
    int res = my_getnbr(str);
    cr_assert_eq(res, 1564851);
}

Test(my_getnbr2, Test)
{
    char str[] = "---85"; 
    int res = my_getnbr(str);
    cr_assert_eq(res, -85);
}

Test(my_getnbr3, Test)
{
    char str[] = "0000000045"; 
    int res = my_getnbr(str);
    cr_assert_eq(res, 45);
}

Test(my_getnbr4, Tests)
{
    char str[] = ""; 
    int res = my_getnbr(str);
    cr_assert_eq(res, 0);
}