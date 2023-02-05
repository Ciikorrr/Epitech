/*
** EPITECH PROJECT, 2022
** test_my_strncmp.c
** File description:
** test strncmp
*/

#include <criterion/criterion.h>

int my_strncmp(char const *s1, char const *s2, int n);

Test(my_strncmp, compare_str)
{
    my_strncmp("coucou", "cou", 2);
    cr_assert_eq(my_strncmp("coucou", "cou",2), 0);
}

Test(my_strncmp2, compare_str)
{
    my_strncmp("coucou", "abc", 2);
    cr_assert_eq(my_strncmp("coucou", "abc",2), 1);
}

Test(my_strncmp3, compare_str)
{
    my_strncmp("coucou", "edf", 2);
    cr_assert_eq(my_strncmp("coucou", "edf",2), -1);
}
