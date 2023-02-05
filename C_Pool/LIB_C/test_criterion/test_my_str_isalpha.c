/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** test_my_str_isnum
*/

#include <criterion/criterion.h>
int my_str_isalpha(char *str);

Test(my_str_isalpha1, Test)
{
    char str[] = "idjIFJV"; 
    int res = my_str_isalpha(str);
    cr_assert_eq(res, 1);
}

Test(my_str_isalpha2, Test)
{
    char str[] = "621fv"; 
    int res = my_str_isalpha(str);
    cr_assert_eq(res, 0);
}

Test(my_str_isalpha3, Test)
{
    char str[] = "   __#2"; 
    int res = my_str_isalpha(str);
    cr_assert_eq(res, 0);
}

Test(my_str_isalpha4, Tests)
{
    char str[] = "   idjIFJV  "; 
    int res = my_str_isalpha(str);
    cr_assert_eq(res, 0);
}