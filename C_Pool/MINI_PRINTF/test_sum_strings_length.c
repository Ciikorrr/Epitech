/*
** EPITECH PROJECT, 2022
** test_my_revstr
** File description:
** test 
*/

#include <criterion/criterion.h>
int sum_strings_length(int i, ...);

Test(sum_strings_length1, test)
{
    int res = sum_strings_length(5, "hello", "a", "toto", "", "plop");
    cr_assert_eq(res, 14);
}

Test(sum_strings_length2, test)
{
    int res = sum_strings_length(5, "a", "b", "c", "d", "e");
    cr_assert_eq(res, 5);
}

Test(sum_strings_length3, test)
{
    int res = sum_strings_length(5, "", "", "", "", "");
    cr_assert_eq(res, 0);
}

Test(sum_strings_length4, test)
{
    int res = sum_strings_length(3, "marius", "marolleau", "", "d", "e");
    cr_assert_eq(res, 15);
}