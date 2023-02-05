/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** test_strupxase
*/

#include <criterion/criterion.h>

char *my_strupcase(char *str);

Test(my_strupcase, up_case)
{
    char str[] = "   TEST  "; 
    char *res = my_strupcase(str);
    cr_assert_str_eq(res, "   TEST  ");
}

Test(my_strupcase2, up_case)
{
    char str[] = "TesT "; 
    char *res = my_strupcase(str);
    cr_assert_str_eq(res, "TEST ");
}

Test(my_strupcase3, up_case)
{
    char str[] = "  test"; 
    char *res = my_strupcase(str);
    cr_assert_str_eq(res, "  TEST");
}