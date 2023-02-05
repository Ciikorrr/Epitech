/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include <criterion/criterion.h>
char *my_strupcase(char *str);

Test(my_strupcase, upper_case)
{
    char res = my_strupcase("Test moi");
    cr_assert_str_eq(res, "TEST MOI");
}

Test(my_strupcase2, upper_case)
{
    char res = my_strupcase("Test");
    cr_assert_str_eq(res, "TEST");
}

Test(my_strupcase3, upper_case)
{
    char res = my_strupcase("TEST");
    cr_assert_str_eq(res, "TEST");
}
