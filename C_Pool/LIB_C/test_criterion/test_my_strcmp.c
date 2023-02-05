/*
** EPITECH PROJECT, 2022
** test_strcmp.c
** File description:
** test strcmp
*/

#include <criterion/criterion.h>

int my_strlen( char const *str);
int my_strcmp(char const *s1, char const *s2);

Test(my_strcmp, compare_two_strings)
{
    char *s1 = "abcdefg";
    char *s2 = "abcdefg";

    int res = my_strcmp(s1, s2);
    cr_assert_eq(res, 0);
}

Test(my_strcmp2, compare_two_strings)
{
    char *s1 = "abcdefg";
    char *s2 = "aze";

    int res = my_strcmp(s1, s2);
    cr_assert_eq(res, -1);
}

Test(my_strcmp3, compare_two_strings)
{
    char *s1 = "lol";
    char *s2 = "abcdefg";

    int res = my_strcmp(s1, s2);
    cr_assert_eq(res, -1);
}

